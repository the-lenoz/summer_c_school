#include <math.h>
#include <assert.h>

#include "structures.hpp"
#include "enums.hpp"
#include "double_operations.hpp"


double solve_linear_equation(double k, double b, NumberOfEquationRoots* number_of_roots)
{
    if (are_doubles_equal(k, 0)) 
    {
        // Константа, не зависит от x
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
        return -b / k; // Корень найден
    }
    
}

QuadraticEquationSolutionOutput solve_quadratic_equation(QuadraticEquationForm equation_form)
{
    assert(isfinite(equation_form.a));
    assert(isfinite(equation_form.b));
    assert(isfinite(equation_form.c));

    QuadraticEquationSolutionOutput result = {0, 0, TWO_ROOTS};
    
    if (are_doubles_equal(equation_form.a, 0)) // Линейное уравнение
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
        return result; // Успех, но корень один
    } 

    if (D < 0) 
    {
        result.number_of_roots = ZERO_ROOTS; 
        return result; // ОШИБКА - корней нет
    } 

    double D_sqrt = sqrt(D);

    result.x1 = (-equation_form.b + D_sqrt) / (2 * equation_form.a);
    result.x2 = (-equation_form.b - D_sqrt) / (2 * equation_form.a);
    result.number_of_roots = TWO_ROOTS;
    return result; // Успех
}