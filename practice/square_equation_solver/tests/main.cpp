#include <stdlib.h>

#include "all_tests.hpp"


int main(void)
{
    StatusData function_call_status_data = run_all_tests(NULL);
    if (function_call_status_data.status_code != SUCCESS)
    {
        log_error(function_call_status_data);
        return 1;
    }
    return 0;
}