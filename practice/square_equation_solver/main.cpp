#include <stdio.h>
#include <math.h>
#include <string.h>
#include <signal.h>
#include <assert.h>

#include "user_interface.hpp"
#include "cli.hpp"
#include "cli_structures.hpp" // global_flag_runs array defined here

#include "signal_handlers.hpp"

#include "errors.hpp"
#include "terminal_decorator.hpp"

#include "logger.hpp"

int main(int argc, const char** argv)
{
    printf_blinking("Мяу\n");
    signal(SIGWINCH, wc_detect);


    assert(argv != NULL);
    assert(argv[0] != NULL);

    LogTarget log_targets[] = {
        {
            .file_path = "log001.txt"
        },
        {
            .file_path = "log001.html"
        },
        {
            .file_path = NULL // STDOUT
        }
    };

    LOG_START(argv[0], (int) (sizeof(log_targets) / sizeof(log_targets[0])), log_targets);
    atexit(&LOG_STOP);

    StatusData function_call_status_data = {};
    
    if (argc == 1)
    {
        return run_user_loop();
    } 
    else
    {
        for (size_t i = 0; i < global_flag_runs_number; ++i)
        {
            if (is_flag_set(argc, argv, global_flag_runs[i]))
            {
                function_call_status_data = 
                    global_flag_runs[i].CLI_run_function_ptr((const void*)(get_flag_value(argc, argv, global_flag_runs[i])));

                if (function_call_status_data.status_code != SUCCESS)
                {
                    LOG_ERROR(function_call_status_data);
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

