#ifndef NUMBER_OF_EQUATION_ROOTS_STR_ENUM_DECLARED
#define NUMBER_OF_EQUATION_ROOTS_STR_ENUM_DECLARED

#include "square_equation_types.hpp"

struct NumberOfRootsStrEnum
{
    const char* number_of_roots_str;
    NumberOfEquationRoots number_of_roots;
};

//-------------------------------------------------------
//! @brief NumberOfEquationRoots get_equation_roots_number_enum_by_str(char* number_of_roots_str)
//! @param [in] number_of_roots_str - string that means number of equation roots
//! @return number of equation roots enum
//-------------------------------------------------------
NumberOfEquationRoots get_equation_roots_number_enum_by_str(const char* number_of_roots_str);


//-------------------------------------------------------
//! @brief NumberOfEquationRoots get_equation_roots_number_str_by_enum(char* number_of_roots_str)
//! @param [in] number_of_roots - enum that means number of equation roots
//! @return number of equation roots string
//-------------------------------------------------------
const char* get_equation_roots_number_str_by_enum(NumberOfEquationRoots number_of_roots);

#endif // NUMBER_OF_EQUATION_ROOTS_STR_ENUM_DECLARED