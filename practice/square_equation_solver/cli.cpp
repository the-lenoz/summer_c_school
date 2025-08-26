#define UNUSED(x) (void)(x)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "square_equation_types.hpp"

#include "equation_solvers.hpp"
#include "user_interface.hpp"

#include "cli_structures.hpp"

#include "errors.hpp"

#include "cli.hpp"


const int start_max_file_path_len = 512;


StatusData print_help(const void* dummy_stub)
{
    UNUSED(dummy_stub);
    printf("Решатель квадратных уравнений. Вызов:\n");
    printf("main [-флаги] [аргументы]\n");
    for (size_t i = 0; i < global_flag_runs_number; ++i)
    {
        printf("\t%s, %-64s%s\n", global_flag_runs[i].short_flag, 
            global_flag_runs[i].long_flag, global_flag_runs[i].description);
    }
    printf("\t%-68s%s\n", "[a b c]", "3 вещественных числа - решить квадратное уравнение вида ax^2 + bx + c = 0");
    printf("\t%-68s%s\n","","Без аргументов - запустить в интерактивном режиме");
    return MAKE_SUCCESS_STRUCT();
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

int is_flag_set(int argc, const char** argv, CLIFlagStructure flag)
{
    return !!get_flag_index(argc, argv, flag);
}

const char* get_flag_value(int argc, const char** argv, CLIFlagStructure flag)
{
    assert(argv != NULL);

    int flag_index = get_flag_index(argc, argv, flag);

    if (!flag_index) 
    {
        return NULL;
    }
    else if (flag_index == argc - 1)
    {
        return NULL;
    }
    else 
    {
        assert(argv[flag_index + 1] != NULL);

        if (*(argv[flag_index + 1]) == '-')
        {
            return NULL;
        }
        else
        {
            return argv[flag_index + 1];
        }
    }
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
            print_help(NULL);
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
        print_help(NULL);
        return 1;
    }
    return 0;
}

StatusData run_cli_from_file(const void* file_path_input)
{
    const char* file_path = (const char*)file_path_input;
    FILE* file_ptr = NULL;
    SquareEquationForm equation_form = {};
    SolvedSquareEquation equation = {};
    SquareEquationSolutionOutput result = {};
    char* entered_file_path = (char*)calloc(start_max_file_path_len, sizeof(char));

    if (file_path == NULL)
    {
        printf("Введите путь к файлу с коэффицентами:\n");
        
        int c = 0;
        size_t index = 0;
        size_t current_file_path_len = start_max_file_path_len;
        do
        {
            if (entered_file_path == NULL)
                return MAKE_ERROR_STRUCT(CANNOT_ALLOCATE_MEMORY_ERROR);
            
            c = getchar();
            if (c != '\n' && c != EOF)
                entered_file_path[index++] = (char)c;

            if (index == current_file_path_len)
            {
                current_file_path_len = current_file_path_len << 1;
                entered_file_path = (char*)realloc(entered_file_path, current_file_path_len * sizeof(char));

            }
        } while (c != '\n' && c != EOF);

        file_ptr = fopen(entered_file_path, "r+");   
    }
    else
    {
        file_ptr = fopen(file_path, "r+");
    }

    if (file_ptr == NULL)
    {
        return MAKE_ERROR_STRUCT(CANNOT_OPEN_FILE_ERROR);
    }
    while (fscanf(file_ptr, "%lg %lg %lg\n", &equation_form.a, &equation_form.b, &equation_form.c) == 3)
    {
        result = solve_square_equation(equation_form); 
        equation = {
            equation_form,
            result
        };
        print_result(equation); 
        printf("\n");
    }

    fclose(file_ptr);
    return MAKE_SUCCESS_STRUCT();
}


