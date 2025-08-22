#ifndef STRUCTURES_DECLARED
#define STRUCTURES_DECLARED

#include "enums.hpp"

struct QuadraticEquationForm
{
    double a;
    double b;
    double c;
};

struct QuadraticEquationSolutionOutput
{
    double x1;
    double x2;
    NumberOfEquationRoots number_of_roots;
};

struct SolvedQuadraticEquation
{
    QuadraticEquationForm form;
    QuadraticEquationSolutionOutput solution_output;
};

#endif