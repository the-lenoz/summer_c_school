#include <math.h>

const double eps = 1e-10;

int are_doubles_equal(double a, double b)
{
    return fabs(a - b) < eps;
}