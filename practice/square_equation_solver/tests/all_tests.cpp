#include <stdio.h>

#include "test_double_operations.hpp"
#include "test_equation_solvers.hpp"


int main(void)
{
    printf("Starting tests...\n");
    printf("Testing are_doubles_equal...\n");
    test_are_doubles_equal();
    printf("PASSED!\n");

    printf("Testing solve_linear_equation...\n");
    test_solve_linear_equation();
    printf("PASSED!\n");

    printf("Testing solve_square_equation...\n");
    test_solve_square_equation();
    printf("PASSED!\n");

    printf("All tests PASSED!\n");
    return 0;
}

