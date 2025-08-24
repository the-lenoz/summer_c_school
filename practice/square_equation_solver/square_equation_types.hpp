#ifndef STRUCTURES_DECLARED
#define STRUCTURES_DECLARED


enum NumberOfEquationRoots
{
    ZERO_ROOTS,
    INFINITE_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

struct SquareEquationForm
{
    double a;
    double b;
    double c;
};

struct SquareEquationSolutionOutput
{
    double x1;
    double x2;
    NumberOfEquationRoots number_of_roots;
};

struct SolvedSquareEquation
{
    SquareEquationForm form;
    SquareEquationSolutionOutput solution_output;
};

#endif