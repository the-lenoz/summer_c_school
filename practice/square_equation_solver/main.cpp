#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "constants.hpp"
#include "structures_and_enums.hpp"

#include "user_interface.hpp"
#include "math_functions.hpp"


int main(void)
{
    int exit = 0;
    send_greeting();
    QuadraticEquationForm equation_form = {0};
    QuadraticEquationSolutionOutput result = {0};
    SolvedQuadraticEquation equation = {0};
    
    while (!exit)
    {
        if (read_input(&equation_form) == 3) // read 3 doubles
        {
            result = solve_quadratic_equation(equation_form); // solve equation
            equation = {
                equation_form,
                result
            };

            print_result(equation); // output result
        }

        exit = wait_for_newline_or_exit();        
             
        if (!exit) 
        {
            send_try_again(); // request new equation
        }
    }
    
    
    return 0;
}

