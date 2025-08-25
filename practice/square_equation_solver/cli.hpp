#ifndef CLI_FUNCTIONS_DECLARED
#define CLI_FUNCTIONS_DECLARED

#include "errors.hpp"
#include "cli_structures.hpp"


//---------------------------------------------------------------
//! StatusData print_help(void)
//! @brief Function prints help to user. 
//! @param [in] dummy_stub - stub parameter to unify functions input format
//! @return status of execution
//---------------------------------------------------------------
StatusData print_help(const void* dummy_stub);


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
//! int is_flag_set(int argc, char** argv, CLIFlagStructure flag)
//! @brief Function checks is cli flag set. 
//! @param [in] argc - number of CLI arguments
//! @param [in] argv - CLI arguments
//! @param [in] flag - string with flag to find
//! @return 1 if flag set else 0
//---------------------------------------------------------------
int is_flag_set(int argc, const char** argv, CLIFlagStructure flag);


//---------------------------------------------------------------
//! int get_flag_value(int argc, char** argv, CLIFlagStructure flag)
//! @brief Function to get flag value
//! @param [in] argc - number of CLI arguments
//! @param [in] argv - CLI arguments
//! @param [in] flag - string with flag to find
//! @return string with flag value 
//---------------------------------------------------------------
const char* get_flag_value(int argc, const char** argv, CLIFlagStructure flag);


//---------------------------------------------------------------
//! int run_cli_from_args(int argc, char** argv)
//! @brief Function runs calculation based on values from arguments
//! @param [in] argc - args count
//! @param [in] argv - args array
//! @return process status code
//---------------------------------------------------------------
int run_cli_from_args(int argc, const char** argv);

//---------------------------------------------------------------
//! StatusData run_cli_from_file(char* file_path)
//! @brief Function runs calculation based on values from file in format `a b c`
//! @param [in] run_cli_from_file_structure - RunCliFromFile structure containing file path
//! @return status of execution
//----------------------------------------  -----------------------
StatusData run_cli_from_file(const void* run_cli_from_file_structure);

const CLIFlagStructure global_flag_runs[] = {
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
        .CLI_run_function_ptr = &run_all_tests,
        .short_flag = "-t",
        .long_flag = "--test",
        .description = "Запустить юнит-тесты"
    }
#endif // TEST_MODE
};

const size_t global_flag_runs_number = sizeof(global_flag_runs) / sizeof(global_flag_runs[0]);

#endif // CLI_FUNCTIONS_DECLARED

