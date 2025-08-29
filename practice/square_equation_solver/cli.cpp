#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_assert.hpp"

#include "square_equation_types.hpp"

#include "equation_solvers.hpp"
#include "user_interface.hpp"

#include "cli_structures.hpp"

#include "status.hpp"

#include "logger.hpp"


#include "cli.hpp"


StatusData print_help(int argc, const char** argv, const CLIFlagStructure flag)
{
    UNUSED(argc);
    UNUSED(argv);
    UNUSED(flag);

    printf("Решатель квадратных уравнений. Вызов:\n");
    printf("main [-флаги] [аргументы]\n");
    for (size_t i = 0; i < global_flag_runs_number; ++i)
    {
        printf("\t%s, %-64s%s\n", global_flag_runs[i].short_flag, 
            global_flag_runs[i].long_flag, global_flag_runs[i].description);
    }
    printf("\t%-68s%s\n", "[a b c]", "3 вещественных числа - решить квадратное уравнение вида ax^2 + bx + c = 0");
    printf("\t%-68s%s\n","","Без аргументов - запустить в интерактивном режиме");
    return MAKE_SUCCESS_STRUCT(NULL);
}

int get_flag_index(int argc, const char** argv, CLIFlagStructure flag)
{
    assert(argv != NULL);
    assert(flag.short_flag != NULL);
    assert(flag.long_flag != NULL);

    for (int i = 1; i < argc; ++i)
    {
        assert(argv[i] != NULL);

        if (strcmp(flag.short_flag, argv[i]) == 0 || strcmp(flag.long_flag, argv[i]) == 0)
        {
            return i;
        }
    }
    return 0;
}

int is_str_flag(const char* str)
{
    assert(str != NULL);

    for (size_t i = 0; i < global_flag_runs_number; ++i)
    {
        if (strcmp(str, global_flag_runs[i].long_flag) == 0 ||
            strcmp(str, global_flag_runs[i].short_flag) == 0)
            {
                return 1;
            }
    }
    return 0;
}

int get_next_flag_index(int argc, const char** argv, int flag_index)
{
    assert(argv != NULL);

    if (flag_index >= argc - 1)
    {
        return -1;
    }

    for (int i = flag_index + 1; i < argc; ++i)
    {
        assert(argv[i] != NULL);

        if (is_str_flag(argv[i]))
        {
            return i;
        }
    }

    return -1;
}

int is_flag_set(int argc, const char** argv, CLIFlagStructure flag)
{
    return !!get_flag_index(argc, argv, flag);
}

int run_cli_from_args(int argc, const char** argv)
{
    assert(argv != NULL);

    if (argc == 4)
    {
        assert(argv[1] != NULL);
        assert(argv[2] != NULL);
        assert(argv[3] != NULL);

        SquareEquationForm equation_form = {};
        char wrong = 0;
        if (!sscanf(argv[1], "%lg%c", &equation_form.a, &wrong) || 
            !sscanf(argv[2], "%lg%c", &equation_form.b, &wrong) || 
            !sscanf(argv[3], "%lg%c", &equation_form.c, &wrong) ||
            wrong)
        {
            print_help(argc, argv, {});
            return 1;
        }

        SquareEquationSolutionOutput result = solve_square_equation(equation_form); 

        SolvedSquareEquation equation = {
            equation_form,
            result
        };
        print_result(equation); 
    }
    else 
    {
        print_help(argc, argv, {});
        return 1;
    }
    return 0;
}

StatusData run_cli_from_file(int argc, const char** argv, const CLIFlagStructure flag)
{
    assert(argv != NULL);
    int flag_index = get_flag_index(argc, argv, flag);
    
    const char* file_path = NULL;
    FILE* file_ptr = NULL;
    SquareEquationForm equation_form = {};
    SolvedSquareEquation equation = {};
    SquareEquationSolutionOutput result = {};

    size_t file_size = 0;
    

    if (flag_index + 1 < argc)
    {
        assert(argv[flag_index + 1] != NULL);
        file_path = argv[flag_index + 1];
    }

    if (file_path == NULL)
    {
        char* entered_file_path = prompt_input_file_path();
        if (entered_file_path == NULL) // allocation error in prompt_input_file_path
        {
            return MAKE_ERROR_STRUCT(CANNOT_ALLOCATE_MEMORY_ERROR);
        }

        file_ptr = fopen(entered_file_path, "r+");  
        free((void *) entered_file_path);
    }
    else
    {
        printf("%s\n", file_path);
        file_ptr = fopen(file_path, "r+");
    }

    if (file_ptr == NULL)
    {
        return MAKE_ERROR_STRUCT(CANNOT_OPEN_FILE_ERROR);
    }

    fseek(file_ptr, 0L, SEEK_END);
    file_size = (size_t) ftell(file_ptr); 
    fseek(file_ptr, 0L, SEEK_SET);

    if (file_size == 0)
    {
        return MAKE_ERROR_STRUCT(CANNOT_OPEN_FILE_ERROR);
    }
    
    char* file_buffer = (char*)calloc(file_size, sizeof(char));
    if (file_buffer == NULL)
    {
        return MAKE_ERROR_STRUCT(CANNOT_ALLOCATE_MEMORY_ERROR);
    }

    fread(file_buffer, file_size, 1, file_ptr);
    fclose(file_ptr);

    int count = 0;
    int n;

    while (sscanf(&(file_buffer[count]), " %lg %lg %lg %n", &equation_form.a, &equation_form.b, &equation_form.c, &n) == 3)
    {
        result = solve_square_equation(equation_form); 
        equation = {
            equation_form,
            result
        };
        print_result(equation); 
        printf("\n");
        count += n;
    }

    return MAKE_SUCCESS_STRUCT(NULL);
}


StatusData setup_logger_cli(int argc, const char** argv, const CLIFlagStructure flag)
{
    assert(argv != NULL);

    int flag_index = get_flag_index(argc, argv, flag);
    int next_flag_index = get_next_flag_index(argc, argv, flag_index);

    int log_targets_count = 0;

    LogTarget* log_targets = NULL;


    if (flag_index == 0 || flag_index == argc - 1)
    {
        return MAKE_ERROR_STRUCT(CANNOT_GET_LOG_TARGETS);
    }

    if (next_flag_index == -1)
    {
        log_targets_count = argc - 1 - flag_index;
    }
    else {
        log_targets_count = next_flag_index - 1 - flag_index;
    }

    log_targets = (LogTarget*) calloc((size_t) log_targets_count, sizeof(LogTarget));

    if (log_targets == NULL)
    {
        return MAKE_ERROR_STRUCT(CANNOT_ALLOCATE_MEMORY_ERROR);
    }


    for (int i = 0; i < log_targets_count; ++i)
    {
        assert(argv[i + flag_index + 1] != NULL);
        if (strcmp("STDOUT", argv[i + flag_index + 1]) == 0)
        {
            log_targets[i] = 
            {
                NULL // STDOUT
            };
        }
        else 
        {
            log_targets[i] = 
            {
                argv[i + flag_index + 1]
            };
        }
    }

    LOG_START(argv[0], log_targets_count, log_targets);

    return MAKE_SUCCESS_STRUCT(NULL);
}

