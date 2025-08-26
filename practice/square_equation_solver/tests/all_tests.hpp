#ifndef ALL_TESTS_RUN_DECLARED
#define ALL_TESTS_RUN_DECLARED

#include "errors.hpp"
#include "cli_structures.hpp"

//---------------------------------------------------------------
//! int StatusData run_all_tests(int argc, const char** argv, const CLIFlagStructure flag)
//! @brief Function runs all unit tests
//! @param [in] dummy_stub - stub to unify function tuns
//! @return status of execution
//---------------------------------------------------------------
StatusData run_all_tests(int argc, const char** argv, const CLIFlagStructure flag);

#endif