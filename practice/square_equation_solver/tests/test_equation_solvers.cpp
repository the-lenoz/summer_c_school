#include <assert.h>

#include "double_operations.hpp"
#include "square_equation_structures.hpp"
#include "solver_enums.hpp"

#include "test_equation_solvers.hpp"

#include "equation_solvers.hpp"



int test_solve_linear_equation(void)
{
    NumberOfEquationRoots linear_equation_number_of_roots = TWO_ROOTS;
    double linear_equation_root;

    // Case 1
    linear_equation_root = solve_linear_equation(0, -1, &linear_equation_number_of_roots);
    assert(linear_equation_number_of_roots == ZERO_ROOTS);

    // Case 2
    linear_equation_root = solve_linear_equation(0, 0, &linear_equation_number_of_roots);
    assert(linear_equation_number_of_roots == INFINITE_ROOTS);

    // Case 3
    linear_equation_root = solve_linear_equation(2, -1, &linear_equation_number_of_roots);
    assert(linear_equation_number_of_roots == ONE_ROOT);
    assert(are_doubles_equal(linear_equation_root, 0.5));
    
    // Case 4
    linear_equation_root = solve_linear_equation(2, 1, &linear_equation_number_of_roots);
    assert(linear_equation_number_of_roots == ONE_ROOT);
    assert(are_doubles_equal(linear_equation_root, -0.5));

    return 1; // PASSED
}

int test_solve_square_equation(void)
{
    QuadraticEquationForm test_equation_form = {};
    QuadraticEquationSolutionOutput square_equation_solver_output = {};

    // Case 1
    test_equation_form = {0, 0, -1};
    square_equation_solver_output = solve_quadratic_equation(test_equation_form);
    assert(square_equation_solver_output.number_of_roots == ZERO_ROOTS);

    // Case 2
    test_equation_form = {1, 3, -10};
    square_equation_solver_output = solve_quadratic_equation(test_equation_form);
    assert(square_equation_solver_output.number_of_roots == TWO_ROOTS);
    assert(are_doubles_equal(square_equation_solver_output.x1, 2));
    assert(are_doubles_equal(square_equation_solver_output.x2, -5));

    // Case 3
    test_equation_form = {1, 2, 1};
    square_equation_solver_output = solve_quadratic_equation(test_equation_form);
    assert(square_equation_solver_output.number_of_roots == ONE_ROOT);
    assert(are_doubles_equal(square_equation_solver_output.x1, -1));
    assert(are_doubles_equal(square_equation_solver_output.x2, -1));
    
    // Case 4
    test_equation_form = {100, 1, 1};
    square_equation_solver_output = solve_quadratic_equation(test_equation_form);
    assert(square_equation_solver_output.number_of_roots == ZERO_ROOTS);

    return 1; // PASSED
}