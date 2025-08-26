#include <string.h>
#include "my_assert.hpp"

#include "square_equation_types.hpp"
#include "number_of_equation_roots_str_enum.hpp"


NumberOfRootsStrEnum number_of_roots_enum_array[] = {
    {
        .number_of_roots_str = "ZERO_ROOTS",
        .number_of_roots = ZERO_ROOTS
    },
    {
        .number_of_roots_str = "ONE_ROOT",
        .number_of_roots = ONE_ROOT
    },
    {
        .number_of_roots_str = "TWO_ROOTS",
        .number_of_roots = TWO_ROOTS
    },
    {
        .number_of_roots_str = "INFINITE_ROOTS",
        .number_of_roots = INFINITE_ROOTS
    }
};

NumberOfEquationRoots get_equation_roots_number_enum_by_str(const char* number_of_roots_str)
{
    assert(number_of_roots_str != NULL);

    if (strcmp(number_of_roots_str, "ZERO_ROOTS") == 0)
    {
        return ZERO_ROOTS;
    }
    else if (strcmp(number_of_roots_str, "ONE_ROOT") == 0)
    {
        return ONE_ROOT;
    }
    else if (strcmp(number_of_roots_str, "TWO_ROOTS") == 0)
    {
        return TWO_ROOTS;
    }
    else if (strcmp(number_of_roots_str, "INFINITE_ROOTS") == 0)
    {
        return INFINITE_ROOTS;
    }
    else 
    {
        return ZERO_ROOTS;
    }
}

const char* get_equation_roots_number_str_by_enum(NumberOfEquationRoots number_of_roots)
{
    switch (number_of_roots)
    {
        case ZERO_ROOTS:
            return "ZERO_ROOTS";
            break;
        case ONE_ROOT:
            return "ONE_ROOT";
            break;
        case TWO_ROOTS:
            return "TWO_ROOTS";
            break;
        case INFINITE_ROOTS:
            return "INFINITE_ROOTS";
            break;
        default:
            return "ZERO_ROOTS";
            break;
    }

}