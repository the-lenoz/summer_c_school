#ifndef STRUCTURES_DECLARED
#define STRUCTURES_DECLARED


enum NumberOfEquationRoots
{
    ZERO_ROOTS,
    INFINITE_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

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