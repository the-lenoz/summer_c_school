#ifndef MATHEMATICS_DECLARED
#define MATHEMATICS_DECLARED

const int gradient_descent_max_steps = 1000000;

const double dx = 1e-8;
const double eps = 1e-20;

//---------------------------------------------------------------
//! int are_doubles_equal(double a, double b)
//! @brief Function compares two doubles with precision gap. 
//!
//! @param [in] a - the first double
//! @param [in] b - the second double
//!
//! @return 1 if there are equal else 0
//---------------------------------------------------------------
int are_doubles_equal(double a, double b);



double get_func_extremum(double (*f)(double));


double get_func_min(double (*f)(double), double* derivative);

double get_func_max(double (*f)(double), double* derivative);


double get_deriv_in_point(double (*f)(double), double x);


#endif // MATHEMATICS_DECLARED