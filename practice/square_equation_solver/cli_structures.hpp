#ifndef CLI_STRUCTURES_DECLARED
#define CLI_STRUCTURES_DECLARED
#include "cli.hpp"

#ifdef TEST_MODE
#include "tests/all_tests.hpp"
#endif // TEST_MODE

struct CLIFRunModeStructure
{
    StatusData (*CLI_run_function_ptr)(const void*);
    const char* short_flag;
    const char* long_flag;
    const char* description;
};

const CLIFRunModeStructure global_flag_runs[] = {
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

#endif // CLI_STRUCTURES_DECLARED