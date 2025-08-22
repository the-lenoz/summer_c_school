#ifndef USER_INTERFACE_DECLARED
#define USER_INTERFACE_DECLARED


#include "structures_and_enums.hpp"

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
//! int wait_for_newline_or_exit(void)
//! @brief Function gets chars from stdin and waits for newline or exit.
//! @return 0 if got newline else (if got Esc or EOF) 1
//---------------------------------------------------------------
int wait_for_newline_or_exit(void);

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