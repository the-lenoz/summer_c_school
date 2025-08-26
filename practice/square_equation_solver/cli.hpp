#ifndef CLI_FUNCTIONS_DECLARED
#define CLI_FUNCTIONS_DECLARED

#include <stdlib.h>

#include "status.hpp"
#include "cli_structures.hpp"

#ifdef TEST_MODE
#include "all_tests.hpp"
#endif // TEST_MODE


//---------------------------------------------------------------
//! StatusData print_help(int argc, const char** argv, const CLIFlagStructure flag);
//! @brief Function prints help to user. 
//! @param [in] dummy_stub - stub parameter to unify functions input format
//! @return status of execution
//---------------------------------------------------------------
StatusData print_help(int argc, const char** argv, const CLIFlagStructure flag);


//---------------------------------------------------------------
//! int get_flag_index(int argc, char** argv, CLIFlagStructure flag)
//! @brief Function returns cli flag index in argv array. 
//! @param [in] argc - number of CLI arguments
//! @param [in] argv - CLI arguments
//! @param [in] flag - string with flag to find
//! @return flag index in argv array if flag set else 0
//---------------------------------------------------------------
int get_flag_index(int argc, const char** argv, CLIFlagStructure flag);

//---------------------------------------------------------------
//! @brief int is_str_flag(const char* str)
//! function to check is string registered flag
//! @param [in] str - string to check
//! @return 1 if true else 0
//---------------------------------------------------------------
int is_str_flag(const char* str);

//---------------------------------------------------------------
//! @brief int get_next_flag_index(int argc, const char** argv, int flag_index)
//! function to get flag index next to the current
//! @param [in] argc - number of CLI arguments
//! @param [in] argv - CLI arguments
//! @param [in] flag_index - index of the current flag
//! @return index of the next flag if found else -1
//---------------------------------------------------------------
int get_next_flag_index(int argc, const char** argv, int flag_index);


//---------------------------------------------------------------
//! int is_flag_set(int argc, char** argv, CLIFlagStructure flag)
//! @brief Function checks is cli flag set. 
//! @param [in] argc - number of CLI arguments
//! @param [in] argv - CLI arguments
//! @param [in] flag - string with flag to find
//! @return 1 if flag set else 0
//---------------------------------------------------------------
int is_flag_set(int argc, const char** argv, CLIFlagStructure flag);


//---------------------------------------------------------------
//! int run_cli_from_args(int argc, char** argv)
//! @brief Function runs calculation based on values from arguments
//! @param [in] argc - args count
//! @param [in] argv - args array
//! @return process status code
//---------------------------------------------------------------
int run_cli_from_args(int argc, const char** argv);

//---------------------------------------------------------------
//! StatusData run_cli_from_file(int argc, const char** argv, const CLIFlagStructure flag)
//! @brief Function runs calculation based on values from file in format `a b c`
//! @param [in] argc - number of CLI arguments
//! @param [in] argv - CLI arguments
//! @param [in] flag - --file flag object
//! @return status of execution
//----------------------------------------  ---------------------
StatusData run_cli_from_file(int argc, const char** argv, const CLIFlagStructure flag);

//---------------------------------------------------------------
//! StatusData setup_logger_cli(int argc, const char** argv, const CLIFlagStructure flag, LogTarget* log_targets)
//! @brief Function runs calculation based on values from file in format `a b c`
//! @param [in] argc - number of CLI arguments
//! @param [in] argv - CLI arguments
//! @param [in] flag - --file flag object
//! @param [out] log_targets - address of dynamically allocated array of log targets
//! @return status of execution
//----------------------------------------  ---------------------
StatusData setup_logger_cli(int argc, const char** argv, const CLIFlagStructure flag);


const CLIFlagStructure global_flag_runs[] = {
    {
        .CLI_run_function_ptr = &setup_logger_cli,
        .short_flag = "-l",
        .long_flag = "--log",
        .description = "Лог-файлы через пробел (STDOUT для стандартного вывода): --log STDOUT file1 file2 ...",
        .flag_type = LOGGER_SETUP_FLAG
    },
    {
        .CLI_run_function_ptr = &print_help,
        .short_flag = "-h",
        .long_flag = "--help",
        .description = "Показать подсказку"
    },
    {
        .CLI_run_function_ptr = &run_cli_from_file,
        .short_flag = "-f",
        .long_flag = "--file",
        .description = "Считать коэффиценты из файла"
    },
#ifdef TEST_MODE    
    {
        .CLI_run_function_ptr = &run_all_tests, //TODO
        .short_flag = "-t",
        .long_flag = "--test",
        .description = "Запустить юнит-тесты"
    }
#endif // TEST_MODE
};

const size_t global_flag_runs_number = sizeof(global_flag_runs) / sizeof(global_flag_runs[0]);

#endif // CLI_FUNCTIONS_DECLARED

