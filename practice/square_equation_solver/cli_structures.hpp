#ifndef CLI_STRUCTURES_DECLARED
#define CLI_STRUCTURES_DECLARED

#ifdef TEST_MODE
#include "tests/all_tests.hpp"
#endif // TEST_MODE

#include "errors.hpp"

struct CLIFlagStructure
{
    StatusData (*CLI_run_function_ptr)(const void*);
    const char* short_flag;
    const char* long_flag;
    const char* description;
};

#endif // CLI_STRUCTURES_DECLARED