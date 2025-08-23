#include <stdio.h>
#include <math.h>
#include <string.h>

#include "square_equation_types.hpp"

#include "user_interface.hpp"
#include "cli.hpp"
#include "cli_structures.hpp"

#ifdef TEST_MODE
#include "tests/all_tests.hpp"
#endif // TEST_MODE

CLIFunctionWithFlag flag_runs[] = {
    {
        .CLI_run_function_ptr = print_help,
        .flag = "-h",
    },
    {
        .CLI_run_function_ptr = print_help,
        .flag = "--help"
    },
    {
        .CLI_run_function_ptr = run_cli_from_file,
        .flag = "-f"
    },
    {
        .CLI_run_function_ptr = run_cli_from_file,
        .flag = "--file"
    }
#ifdef TEST_MODE    
    ,
    {
        .CLI_run_function_ptr = run_all_tests,
        .flag = "-t"
    },
    {
        .CLI_run_function_ptr = run_all_tests,
        .flag = "--test"
    }
#endif // TEST_MODE
};

const int flag_runs_number = sizeof(flag_runs) / sizeof(CLIFunctionWithFlag);


int main(int argc, const char** argv)
{
    int file_flag_index = 0;
    if (argc == 1)
    {
        return run_user_loop();
    } 
    else
    {
        for (int i = 0; i < flag_runs_number; ++i)
        {
            if ((file_flag_index = is_flag_set(argc, argv, flag_runs[i].flag)))
            {
                return (*flag_runs[i].CLI_run_function_ptr)((const void*)(argc > file_flag_index - 1 ? argv[file_flag_index + 1] : NULL));
            }
        }
    }
    if (argc == 4)
    {
        return run_cli_from_args(argc, argv); 
    }
    else
    {
        // Неверный формат вызова
        print_help(NULL); 
        return 1;
    }
}

