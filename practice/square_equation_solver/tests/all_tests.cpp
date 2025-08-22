#include <stdio.h>

#include "test_double_operations.hpp"
#include "test_equation_solvers.hpp"

#include "colors.hpp"

int main(void)
{
    printf(ANSI_COLOR_YELLOW "Starting tests...\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "Testing are_doubles_equal...\n" ANSI_COLOR_RESET);
    if (!test_are_doubles_equal())
    {
        printf(ANSI_COLOR_RED "ABORT!\n" ANSI_COLOR_RESET);
        return 1;
    }
    printf(ANSI_COLOR_GREEN "PASSED!\n" ANSI_COLOR_RESET);

    printf(ANSI_COLOR_YELLOW "Starting tests...\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "Testing solve_linear_equation...\n" ANSI_COLOR_RESET);
    if (!test_solve_linear_equation())
    {
        printf(ANSI_COLOR_RED "ABORT!\n" ANSI_COLOR_RESET);
        return 1;
    }
    printf(ANSI_COLOR_GREEN "PASSED!\n" ANSI_COLOR_RESET);

    printf(ANSI_COLOR_YELLOW "Starting tests...\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "Testing solve_square_equation...\n" ANSI_COLOR_RESET);
    if (!test_solve_square_equation())
    {
        printf(ANSI_COLOR_RED "ABORT!\n" ANSI_COLOR_RESET);
        return 1;
    }
    printf(ANSI_COLOR_GREEN "PASSED!\n" ANSI_COLOR_RESET);

    printf(ANSI_COLOR_GREEN "All tests PASSED!\n" ANSI_COLOR_RESET);
    return 0;
}


