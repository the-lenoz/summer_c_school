#include <stdio.h>
#include <math.h>
#include <string.h>

#include "square_equation_types.hpp"

#include "user_interface.hpp"
#include "cli.hpp"
#include "cli_structures.hpp" // flag_runs array defined here

#include "errors.hpp"

int main(int argc, const char** argv)
{
    //LOG_START(argv[0]);

    // atexit
    // 
    // HTML 
    // backtrace
    //
    // --loger name_fale 
    // FILE* 
    // open()
    // fileno()open
    // write
    // close

    // LOG()
    // LOG_ERR(...)
    // LOG()

    int file_flag_index = 0;

    StatusData function_call_status_data = {};
    
    if (argc == 1)
    {
        return run_user_loop();
    } 
    else
    {
        for (int i = 0; i < flag_runs_number; ++i)
        {
            if ((file_flag_index = is_flag_set(argc, argv, flag_runs[i].short_flag)) ||
                (file_flag_index = is_flag_set(argc, argv, flag_runs[i].long_flag)))
            {
                function_call_status_data = (*flag_runs[i].CLI_run_function_ptr)((const void*)(argc > file_flag_index - 1 ? 
                    argv[file_flag_index + 1] : NULL));

                if (function_call_status_data.status_code != SUCCESS)
                {
                    print_error(function_call_status_data);
                    return 1;
                }
                return 0;
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

