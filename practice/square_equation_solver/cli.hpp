
//---------------------------------------------------------------
//! void print_help(void)
//! @brief Function prints help to user. 
//---------------------------------------------------------------
void print_help(void);


//---------------------------------------------------------------
//! int is_flag_set(int argc, char** argv, char* flag)
//! @brief Function checks is cli flag set. 
//! @param [in] argc - number of CLI arguments
//! @param [in] argv - CLI arguments
//! @param [in] flag - string with flag to find
//! @return flag index in argv array if flag set else 0
//---------------------------------------------------------------
int is_flag_set(int argc, char** argv, char* flag);


//---------------------------------------------------------------
//! int run_cli_from_args(int argc, char** argv)
//! @brief Function runs calculation based on values from arguments
//! @param [in] argc - number of CLI arguments
//! @param [in] argv - CLI arguments
//! @return process status code
//----------------------------------------  -----------------------
int run_cli_from_args(int argc, char** argv);

//---------------------------------------------------------------
//! int run_cli_from_file(char* file_path)
//! @brief Function runs calculation based on values from file in format `a b c`
//! @param [in] file_path - path to file to read
//! @return process status code
//----------------------------------------  -----------------------
int run_cli_from_file(char* file_path);