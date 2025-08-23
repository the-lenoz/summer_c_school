#ifndef TEST_STRUCTURES_DECLARED
#define TEST_STRUCTURES_DECLARED

#include "solver_enums.hpp"
#include "square_equation_structures.hpp"


struct TestRunStructure
{
    int (*test_function_ptr)(void);
    char test_name[128];
};


struct LinearEquationSolverTestData 
{
    double k;
    double b;
    double result;
    char number_of_roots_str[15];
    NumberOfEquationRoots number_of_roots;
};

struct SquareEquationSolverTestData 
{
    QuadraticEquationForm equation_form;
    double x1;
    double x2;
    char number_of_roots_str[15];
    NumberOfEquationRoots number_of_roots;
};

struct DoublesEqualityTestData 
{
    double a;
    double b;
    int result;
};

#endif