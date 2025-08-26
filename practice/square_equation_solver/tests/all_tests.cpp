#define UNUSED(x) (void)(x)

#include <stdio.h>

#include "test_double_operations.hpp"
#include "test_equation_solvers.hpp"

#include "terminal_decorator.hpp"
#include "test_structures.hpp"

#include "status.hpp"

#include "cli_structures.hpp"

#include "all_tests.hpp"

const TestRunStructure test_runs[] = {
    {
        .test_function_ptr = &test_are_doubles_equal,
        .test_name = "are_doubles_equal"
    },
    {
        .test_function_ptr = &test_solve_linear_equation,
        .test_name = "solve_linear_equation"
    },
    {
        .test_function_ptr = &test_solve_square_equation,
        .test_name = "solve_square_equation"
    }
};

const size_t test_runs_number = sizeof(test_runs) / sizeof(test_runs[0]);


StatusData run_all_tests(int argc, const char** argv, const CLIFlagStructure flag)
{
    UNUSED(argc);
    UNUSED(argv);
    UNUSED(flag);

    printf_yellow("Starting tests...\n");
    for (size_t i = 0; i < test_runs_number; ++i)
    {
        printf_yellow("Testing %s\n", test_runs[i].test_name);
        if (!(*test_runs[i].test_function_ptr)()) 
        {
            // Test failed
            printf_red("ABORT!\n");
            return MAKE_ERROR_STRUCT(TEST_FAILED_ERROR);
        }
        printf_green("PASSED!\n");
    }
    
    printf_green("All tests PASSED!\n");
    return MAKE_SUCCESS_STRUCT(NULL);
}


