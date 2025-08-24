#include <math.h>
#include <assert.h>

#include "square_equation_types.hpp"
#include "double_operations.hpp"

#include "equation_solvers.hpp"


double solve_linear_equation(double k, double b, NumberOfEquationRoots* number_of_roots)
{
    assert(number_of_roots != NULL);

    if (!isfinite(k) || !isfinite(b))
    {
        *number_of_roots = ZERO_ROOTS;
        return NAN;
    }

    if (are_doubles_equal(k, 0)) 
    {
        // line is parallel with oX
        if (are_doubles_equal(b, 0))
        {
            *number_of_roots = INFINITE_ROOTS;
        }
        else 
        {
            *number_of_roots = ZERO_ROOTS;
        }
        return NAN;
    }
    else
    {
        *number_of_roots = ONE_ROOT;
        return -b / k; 
    }
}

SquareEquationSolutionOutput solve_square_equation(SquareEquationForm equation_form)
{
    SquareEquationSolutionOutput result = {0, 0, TWO_ROOTS};

    if (!isfinite(equation_form.a) || !isfinite(equation_form.b) || !isfinite(equation_form.c))
    {
        result.number_of_roots = ZERO_ROOTS;
        return result;
    }
    
    if (are_doubles_equal(equation_form.a, 0))
    {
        result.x1 = result.x2 = solve_linear_equation(equation_form.b, equation_form.c, &result.number_of_roots);
        return result;
    }
    
    double D = equation_form.b * equation_form.b - 4 * equation_form.a * equation_form.c;

    if (are_doubles_equal(D, 0))
    {
        result.x1 = (-equation_form.b) / (2 * equation_form.a);
        result.x2 = (-equation_form.b) / (2 * equation_form.a);
        result.number_of_roots = ONE_ROOT;
        return result; 
    } 

    if (D < 0) 
    {
        result.number_of_roots = ZERO_ROOTS; 
        return result;
    } 

    double D_sqrt = sqrt(D);

    result.x1 = (-equation_form.b + D_sqrt) / (2 * equation_form.a);
    result.x2 = (-equation_form.b - D_sqrt) / (2 * equation_form.a);
    result.number_of_roots = TWO_ROOTS;
    return result;
}