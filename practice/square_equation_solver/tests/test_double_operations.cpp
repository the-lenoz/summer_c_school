#include <assert.h>

#include "double_operations.hpp"


int test_are_doubles_equal(void)
{
    // Test case 1
    assert(are_doubles_equal(0, -0));

    // Test case 2
    assert(are_doubles_equal(0 + eps / 2, 0));

    // Test case 3
    assert(are_doubles_equal(0 - eps / 2, 0));

    return 1; // PASSED
}