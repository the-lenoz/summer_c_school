#ifndef CLI_STRUCTURES_DECLARED
#define CLI_STRUCTURES_DECLARED

#ifdef TEST_MODE

#endif // TEST_MODE

#include "status.hpp"


enum CLIFlagType
{
    RUN_FLAG = 0,
    LOGGER_SETUP_FLAG
};


struct CLIFlagStructure
{
    StatusData (*CLI_run_function_ptr)(int argc, const char** argv, const CLIFlagStructure flag);
    const char* short_flag;
    const char* long_flag;
    const char* description;
    CLIFlagType flag_type;
};

typedef StatusData (*CLI_run_function_type)(int argc, const char** argv, const CLIFlagStructure flag);

#endif // CLI_STRUCTURES_DECLARED