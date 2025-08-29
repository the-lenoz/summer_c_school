#include <math.h>
#include <stdio.h>

#include "mathematics.hpp"

int are_doubles_equal(double a, double b)
{
    if (isnan(a) || isnan(b)) 
    {
        return 0;
    }
    if (!isfinite(a) && !isfinite(b))
    {
        if (a * b > 0)
        {
            return 1;
        } 
        return 0;
    } 
    else if (!isfinite(a))
    {
        return 0;
    }
    else if (!isfinite(b))
    {
        return 0;
    }
    else
    {
        return fabs(a - b) < eps;
    }
}

double get_func_extremum(double (*f)(double))
{
    double min_precision = 0, max_precision = 0;
    double min_x = 0, max_x = 0;

    min_x = get_func_min(f, &min_precision);
    max_x = get_func_max(f, &max_precision);

    return abs(min_precision) < abs(max_precision) ? min_x : max_x;
}


double get_func_min(double (*f)(double), double* derivative)
{
    double x = 0.001;

    double step = 1;

    *derivative = 0;

    for (int i = 0; i < gradient_descent_max_steps; ++i)
    {
        x += (*derivative > 0 ? 1 : -1) * step;
        *derivative = get_deriv_in_point(f, x);
        step *= 0.9999;
    }
    return x ;
}

double get_func_max(double (*f)(double), double* derivative)
{
    double x = 0.001;

    double step = 10;

    *derivative = 0;

    for (int i = 0; i < gradient_descent_max_steps; ++i)
    {
        x -= (*derivative > 0 ? 1 : -1) * step;
        *derivative = get_deriv_in_point(f, x);
        step *= 0.999;
    }
    return x ;
}


double get_deriv_in_point(double (*f)(double), double x)
{
    double dy = f(x + dx) - f(x);
    return dy/dx;
}


