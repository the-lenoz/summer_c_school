#include <stdlib.h>

#include "all_tests.hpp"


int main(int argc, const char** argv)
{
    StatusData function_call_status_data = run_all_tests(argc, argv, {});
    if (function_call_status_data.status_code != SUCCESS)
    {
        print_error(function_call_status_data);
        return 1;
    }
    return 0;
}