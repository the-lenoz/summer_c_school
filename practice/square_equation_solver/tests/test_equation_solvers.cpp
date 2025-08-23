#include <string.h>
#include <stdio.h>

#include "double_operations.hpp"
#include "square_equation_types.hpp"

#include "test_equation_solvers.hpp"

#include "equation_solvers.hpp"

#include "test_structures.hpp"

#include "colors.hpp"

#include "number_of_equation_roots_str_enum.hpp"

int test_solve_linear_equation(void)
{
    FILE* test_cases_file_pointer = fopen("tests/linear_equation_solver_test_cases.txt", "r+");
    LinearEquationSolverTestData test_case = {};
    NumberOfEquationRoots test_number_of_roots = ZERO_ROOTS;
    double result = 0;

    if (test_cases_file_pointer == NULL)
    {
        printf("Test failed: can't read samples file!\n");
        return 1;
    }

    while (fscanf(test_cases_file_pointer, "k: %lg b: %lg result: %lg, number_of_roots: %14s\n", 
        &test_case.k, &test_case.b, &test_case.result, test_case.number_of_roots_str) == 4)
    {
        test_case.number_of_roots = get_equation_roots_number_enum_by_str(test_case.number_of_roots_str);

        result = solve_linear_equation(test_case.k, test_case.b, &test_number_of_roots);
        printf_yellow("Tesing case k: %lg, b: %lg, expected result: %lg, number_of_roots: %s\n",
               test_case.k, test_case.b, test_case.result, test_case.number_of_roots_str);
        
        if (test_case.number_of_roots == ONE_ROOT)
        {
            if (!are_doubles_equal(result, test_case.result))
            {
                printf_red("TEST CASE FAILED! expexted result: %lg. got: %lg\n", result, test_case.result);
                fclose(test_cases_file_pointer);
                return 0;
            }
        }

        if (test_case.number_of_roots != test_number_of_roots)
        {
            printf_red("TEST CASE FAILED! Wrong number of roots!\n");
            fclose(test_cases_file_pointer);
            return 0;
        }
    }
    fclose(test_cases_file_pointer);
    return 1;
}

int test_solve_square_equation(void)
{
    FILE* test_cases_file_pointer = fopen("tests/square_equation_solver_test_cases.txt", "r+");
    SquareEquationSolverTestData test_case = {};
    QuadraticEquationSolutionOutput result = {};

    if (test_cases_file_pointer == NULL)
    {
        printf("Test failed: can't read samples file!\n");
        return 1;
    }

    while (fscanf(test_cases_file_pointer, "a: %lg b: %lg c: %lg x1: %lg x2: %lg, number_of_roots: %14s\n",
          &test_case.equation_form.a, &test_case.equation_form.b, &test_case.equation_form.c,
          &test_case.x1, &test_case.x2, test_case.number_of_roots_str) == 6)
    {
        if (strcmp(test_case.number_of_roots_str, "ZERO_ROOTS") == 0)
        {
            test_case.number_of_roots = ZERO_ROOTS;
        }
        else if (strcmp(test_case.number_of_roots_str, "ONE_ROOT") == 0)
        {
            test_case.number_of_roots = ONE_ROOT;
        }
        else if (strcmp(test_case.number_of_roots_str, "TWO_ROOTS") == 0)
        {
            test_case.number_of_roots = TWO_ROOTS;
        }
        else if (strcmp(test_case.number_of_roots_str, "INFINITE_ROOTS") == 0)
        {
            test_case.number_of_roots = INFINITE_ROOTS;
        }
        else 
        {
            test_case.number_of_roots = ZERO_ROOTS;
        }

        result = solve_quadratic_equation(test_case.equation_form);
        printf_yellow("Tesing case a: %lg b: %lg c: %lg x1: %lg x2: %lg, number_of_roots: %s\n", 
            test_case.equation_form.a, test_case.equation_form.b, test_case.equation_form.c, 
            test_case.x1, test_case.x2, test_case.number_of_roots_str);
        
        if (test_case.number_of_roots == ONE_ROOT || test_case.number_of_roots == TWO_ROOTS)
        {
            if (!are_doubles_equal(result.x1, test_case.x1))
            {
                printf_red("TEST CASE FAILED! expexted: %lg. got: %lg\n", result.x1, test_case.x1);
                fclose(test_cases_file_pointer);
                return 0;
            }
            if (!are_doubles_equal(result.x2, test_case.x2))
            {
                printf_red("TEST CASE FAILED! expexted: %lg. got: %lg\n", result.x2, test_case.x2);
                fclose(test_cases_file_pointer);
                return 0;
            }
        }
        if (result.number_of_roots != test_case.number_of_roots)
        {
            printf_red("TEST CASE FAILED! Wrong number of roots!\n");
            fclose(test_cases_file_pointer);
            return 0;
        }
    }
    fclose(test_cases_file_pointer);
    return 1;
}