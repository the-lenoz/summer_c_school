#include <stdlib.h>
#include <stdio.h>

#include "double_operations.hpp"
#include "status.hpp"
#include "terminal_decorator.hpp"

#include "test_structures.hpp"

#include "test_double_operations.hpp"


int test_are_doubles_equal(void)
{
    FILE* test_cases_file_pointer = fopen("tests/double_equality_test_cases.txt", "r+");
    DoublesEqualityTestData test_case = {};
    int result = 0;


    size_t file_size = 0;

    if (test_cases_file_pointer == NULL)
    {
        printf("Test failed: can't read samples file!\n");
        return 1;
    }

    fseek(test_cases_file_pointer, 0L, SEEK_END);
    file_size = (size_t) ftell(test_cases_file_pointer); 
    fseek(test_cases_file_pointer, 0L, SEEK_SET);

    char* file_buffer = (char*)calloc(file_size, sizeof(char));
    if (file_buffer == NULL)
    {
        return 1;
    }

    fread(file_buffer, file_size, 1, test_cases_file_pointer);
    fclose(test_cases_file_pointer);

    int count = 0, n = 0;
    
    while (sscanf(&(file_buffer[count]), " a: %lg b: %lg result: %d %n", &test_case.a, &test_case.b, &test_case.result, &n) == 3)
    {
        printf_yellow("Tesing case a: %lg, b: %lg, expected result: %d\n", 
            test_case.a, test_case.b, test_case.result);
        
        result = are_doubles_equal(test_case.a, test_case.b);
        if (result != test_case.result)
        {
            printf_red("TEST CASE FAILED! expexted: %d. got: %d\n", test_case.result, result);
            return 0;
        }
        count += n;
    }
    return 1;
}