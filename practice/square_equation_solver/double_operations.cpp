#include <math.h>

#include "double_operations.hpp"

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