#include <stdio.h>

#include "double_operations.hpp"
#include "colors.hpp"

#include "test_structures.hpp"

#include "test_double_operations.hpp"


int test_are_doubles_equal(void)
{
    FILE* test_cases_file_pointer = fopen("tests/double_equality_test_cases.txt", "r+");
    DoublesEqualityTestData test_case = {};
    int result = 0;

    if (test_cases_file_pointer == NULL)
    {
        printf("Test failed: can't read samples file!\n");
        return 1;
    }

    while (fscanf(test_cases_file_pointer, "a: %lg b: %lg result: %d\n", &test_case.a, &test_case.b, &test_case.result) == 3)
    {
        printf(ANSI_COLOR_YELLOW "Tesing case a: %lg, b: %lg, expected result: %d\n" ANSI_COLOR_RESET, 
            test_case.a, test_case.b, test_case.result);
        
        result = are_doubles_equal(test_case.a, test_case.b);
        if (result != test_case.result)
        {
            printf(ANSI_COLOR_RED "TEST CASE FAILED! expexted: %d. got: %d\n" ANSI_COLOR_RESET, result, test_case.result);
            return 0;
        }
    }
    return 1;
}