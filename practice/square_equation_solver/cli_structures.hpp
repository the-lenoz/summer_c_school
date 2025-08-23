#ifndef CLI_STRUCTURES_DECLARED
#define CLI_STRUCTURES_DECLARED

struct CLIFunctionWithFlag
{
    int (*CLI_run_function_ptr)(const void*);
    const char* flag;
    const char* file_path;
};

#endif