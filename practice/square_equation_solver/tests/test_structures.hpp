#ifndef TEST_STRUCTURES_DECLARED
#define TEST_STRUCTURES_DECLARED

#define NUMBER_OF_ROOTS_STRING_MAX_LEN  64

#include "square_equation_types.hpp"


struct TestRunStructure
{
    int (*test_function_ptr)(void);
    const char* test_name;
};


struct LinearEquationSolverTestData 
{
    double k;
    double b;
    double result;
    char number_of_roots_str[NUMBER_OF_ROOTS_STRING_MAX_LEN]; // TODO
    NumberOfEquationRoots number_of_roots;
};

struct SquareEquationSolverTestData 
{
    SquareEquationForm equation_form;
    double x1;
    double x2;
    char number_of_roots_str[NUMBER_OF_ROOTS_STRING_MAX_LEN];
    NumberOfEquationRoots number_of_roots;
};

struct DoublesEqualityTestData 
{
    double a;
    double b;
    int result;
};

#endif