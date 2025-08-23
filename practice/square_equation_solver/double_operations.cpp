#include <math.h>

#include "double_operations.hpp"

int are_doubles_equal(double a, double b)
{
    if (!isfinite(a) && !isfinite(b))
    {
        return 1;
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