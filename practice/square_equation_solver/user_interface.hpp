#ifndef USER_INTERFACE_DECLARED
#define USER_INTERFACE_DECLARED

#include "square_equation_structures.hpp"
#include "user_interface_enums.hpp"

const char ESCAPE_KEY = 27;

//---------------------------------------------------------------
//! void send_greeting(void)
//! @brief Function sends greeting to user. 
//---------------------------------------------------------------
void send_greeting(void);

//---------------------------------------------------------------
//! void send_try_again(void)
//! @brief Function sends try again message to user. 
//---------------------------------------------------------------
void send_try_again(void);

//---------------------------------------------------------------
//! InputCharSignal wait_for_newline_or_exit(void)
//! @brief Function gets chars from stdin and waits for newline or exit.
//! @return CORRECT_INPUT, INCORRECT_INPUT or EXIT_KEY
//---------------------------------------------------------------
InputCharSignal wait_for_newline_or_exit(void);

//---------------------------------------------------------------
//! void read_input(void)
//! @brief Function reads user input into a quadratic equation structure.
//!
//! @param [out] equation_form - pointer to target structure 
//!
//! @return number of readed fields
//---------------------------------------------------------------
int read_input(QuadraticEquationForm* equation_form);

//---------------------------------------------------------------
//! void print_result(SolvedQuadraticEquation equation)
//! @brief Function prints results or quadratic equation solving.
//!
//! @param [in] equation - structure of solved equation to show
//---------------------------------------------------------------
void print_result(SolvedQuadraticEquation equation);

#endif