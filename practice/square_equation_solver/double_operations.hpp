#ifndef DOUBLE_OPERATIONS_DECLARED
#define DOUBLE_OPERATIONS_DECLARED

const double eps = 1e-10;

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

#endif