#ifndef ERRORS_DECLARED
#define ERRORS_DECLARED


#define MAKE_ERROR_STRUCT(status_code) {\
            status_code,\
            __FILE__,\
            __func__,\
            __LINE__\
        }
#define MAKE_SUCCESS_STRUCT() {SUCCESS}


enum StatusCode
{
    SUCCESS,
    CANNOT_OPEN_FILE_ERROR,
    TEST_FAILED_ERROR
};


struct StatusData
{
    StatusCode status_code;
    const char* filename;
    const char* func_name;
    int line_number;
};

//------------------------------------------------------------------------
//! @brief void log_error(StatusData error)
//! Function pretty prints error by its ERRNO
//! @param [in] error - ERRNO
//------------------------------------------------------------------------
void log_error(StatusData error);


#endif // ERRORS_DECLARED