#ifndef CLI_FUNCTIONS_DECLARED
#define CLI_FUNCTIONS_DECLARED

//---------------------------------------------------------------
//! int print_help(void)
//! @brief Function prints help to user. 
//! @param [in] dummy_stub - stub parameter to unify functions input format
//---------------------------------------------------------------
int print_help(const void* dummy_stub);


//---------------------------------------------------------------
//! int is_flag_set(int argc, char** argv, char* flag)
//! @brief Function checks is cli flag set. 
//! @param [in] argc - number of CLI arguments
//! @param [in] argv - CLI arguments
//! @param [in] flag - string with flag to find
//! @return flag index in argv array if flag set else 0
//---------------------------------------------------------------
int is_flag_set(int argc, const char** argv, const char* flag);


//---------------------------------------------------------------
//! int run_cli_from_args(int argc, char** argv)
//! @brief Function runs calculation based on values from arguments
//! @param [in] argc - args count
//! @param [in] argv - args array
//! @return process status code
//----------------------------------------  -----------------------
int run_cli_from_args(int argc, const char** argv);

//---------------------------------------------------------------
//! int run_cli_from_file(char* file_path)
//! @brief Function runs calculation based on values from file in format `a b c`
//! @param [in] run_cli_from_file_structure - RunCliFromFile structure containing file path
//! @return process status code
//----------------------------------------  -----------------------
int run_cli_from_file(const void* run_cli_from_file_structure);

#endif // CLI_FUNCTIONS_DECLARED