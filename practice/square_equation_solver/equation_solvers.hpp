#ifndef MATH_FUNCTIONS_DECLARED
#define MATH_FUNCTIONS_DECLARED

#include "square_equation_types.hpp"


//---------------------------------------------------------------
//! double solve_linear_equation(double k, double b)
//! @brief Function solves linear equation of kx + b = 0 form.
//!
//! @param [in] k - the first coefficent
//! @param [in] k - the second coefficent
//! @param [out] number_of_roots - number of equation roots
//!
//! @return root if exists, INF if anything is a root and NAN if a root doesn't exist.
//---------------------------------------------------------------
double solve_linear_equation(double k, double b, NumberOfEquationRoots* number_of_roots);


//---------------------------------------------------------------
//! int solve_square_equation(double a, double b, double c, double* x1, double* x2)
//! @brief Function solves square equation. a*x^2 + b*x + c = 0. 
//! It receives 3 coefficents (a, b, c) and outputs 2 roots. Returns status code
//!
//! @param [in] a - the first coefficent
//! @param [in] b - the second coefficent
//! @param [in] c - the third coefficent
//! @param [out] x1 - the first root
//! @param [out] x2 - the second root
//!
//! @return status code
//---------------------------------------------------------------
SquareEquationSolutionOutput solve_square_equation(SquareEquationForm equation_form);

#endif