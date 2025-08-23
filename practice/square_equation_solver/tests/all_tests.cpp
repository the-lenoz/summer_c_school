#include <stdio.h>

#include "test_double_operations.hpp"
#include "test_equation_solvers.hpp"

#include "colors.hpp"
#include "test_structures.hpp"

#include "all_tests.hpp"

TestRunStructure test_runs[] = {
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

const int test_runs_number = 3;


int run_all_tests(void)
{
    printf(ANSI_COLOR_YELLOW "Starting tests...\n" ANSI_COLOR_RESET);
    for (int i = 0; i < test_runs_number; ++i)
    {
        printf(ANSI_COLOR_YELLOW "Testing %s\n" ANSI_COLOR_RESET, test_runs[i].test_name);
        if (!(*test_runs[i].test_function_ptr)()) 
        {
            // Test failed
            printf(ANSI_COLOR_RED "ABORT!\n" ANSI_COLOR_RESET);
            return 1;
        }
        printf(ANSI_COLOR_GREEN "PASSED!\n" ANSI_COLOR_RESET);
    }
    
    printf(ANSI_COLOR_GREEN "All tests PASSED!\n" ANSI_COLOR_RESET);
    return 0;
}


