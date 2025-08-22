#include <math.h>

#include "double_operations.hpp"

int are_doubles_equal(double a, double b)
{
    return fabs(a - b) < eps;
}