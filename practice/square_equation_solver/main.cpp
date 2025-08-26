#include <stdio.h>
#include <math.h>
#include <string.h>
#include <signal.h>
#include "my_assert.hpp"

#include "user_interface.hpp"
#include "cli.hpp"
#include "cli_structures.hpp" // global_flag_runs array defined here

#include "signal_handlers.hpp"

#include "status.hpp"
#include "terminal_decorator.hpp"

#include "logger.hpp"

#include "cool.hpp"


void print_on_exit(void);

int main(int argc, const char** argv)
{
    signal(SIGWINCH, wc_detect);


    assert(argv != NULL);
    assert(argv[0] != NULL);

    StatusData function_call_status_data = {};

    CLIFlagStructure cli_runs[global_flag_runs_number];
    int current_cli_flag = 0;
    
    int logger_initialized = 0;
    int cool_mode = 0;

    for (size_t i = 0; i < global_flag_runs_number; ++i)
    {
        if (is_flag_set(argc, argv, global_flag_runs[i]))
        {
            if (global_flag_runs[i].flag_type == RUN_FLAG)
            {
                cli_runs[current_cli_flag++] = global_flag_runs[i];
            }
            else // SETTING FLAG
            {
                function_call_status_data = global_flag_runs[i].CLI_run_function_ptr(argc, argv, global_flag_runs[i]);
                if (function_call_status_data.status_code == SUCCESS)
                {
                    if (global_flag_runs[i].flag_type == LOGGER_SETUP_FLAG)
                    {
                        logger_initialized = 1;
                    }
                }
                else {
                    print_error(function_call_status_data);
                    return 1;
                }
            }
        }
    }

    if (!logger_initialized)
    {
        LogTarget log_targets[] = 
        {
            {.file_path = NULL}
        };
        LOG_START(argv[0], 1, log_targets);
    }

    LOG_ERROR(MAKE_ERROR_STRUCT(ASSERTION_FAILED));


    if (cool_mode)
    {
        printf_blinking("Мяу\n");
        atexit(&print_on_exit);
    }


    if (current_cli_flag == 0) // NO FLAGS SET
    {
        if (argc == 4)
        {
            return run_cli_from_args(argc, argv); 
        }
        else
        {
            return run_user_loop();
        }
    }

    for (int i = 0; i < current_cli_flag; ++i)
    {
        function_call_status_data = cli_runs[i].CLI_run_function_ptr(argc, argv, cli_runs[i]);
        if (function_call_status_data.status_code == SUCCESS)
        {
            // NOT YET IMPLEMENTED
        }
        else {
            LOG_ERROR(function_call_status_data);
            return 1;
        }
    }
    return 0;
}

void print_on_exit(void)
{
    printf_blinking(COMMIT_GIT_MESSAGE);
}