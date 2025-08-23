#include <stdio.h>

#include "test_double_operations.hpp"
#include "test_equation_solvers.hpp"

#include "colors.hpp"
#include "test_structures.hpp"

TestRunStructure test_runs[] = {
    {
        .test_function_ptr = &test_are_doubles_equal,
        .test_name = "are_doubles_equal\0"
    },
    {
        .test_function_ptr = &test_solve_linear_equation,
        .test_name = "solve_linear_equation\0"
    },
    {
        .test_function_ptr = &test_solve_square_equation,
        .test_name = "solve_square_equation\0"
    }
};

const int test_runs_number = 3;


int main(void)
{
    printf(ANSI_COLOR_YELLOW "Starting tests...\n" ANSI_COLOR_RESET);
    for (int i = 0; i < test_runs_number; ++i)
    {
        printf(ANSI_COLOR_YELLOW "Testing %s...\n" ANSI_COLOR_RESET, test_runs[i].test_name);
        if (!(*(test_runs[i].test_function_ptr))())
        {
            printf(ANSI_COLOR_RED "ABORT!\n" ANSI_COLOR_RESET);
            return 1;
        }
        printf(ANSI_COLOR_GREEN "PASSED!\n" ANSI_COLOR_RESET);
    }
    
    printf(ANSI_COLOR_GREEN "All tests PASSED!\n" ANSI_COLOR_RESET);
    return 0;
}


