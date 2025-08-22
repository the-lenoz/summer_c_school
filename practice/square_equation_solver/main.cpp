#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "structures.hpp"

#include "user_interface.hpp"
#include "equation_solvers.hpp"


int main(void)
{
    int exit_program = 0;
    send_greeting();
    QuadraticEquationForm equation_form = {0};
    QuadraticEquationSolutionOutput result = {0};
    SolvedQuadraticEquation equation = {0};
    
    while (!exit_program)
    {
        if (read_input(&equation_form) == 3) 
        {
            result = solve_quadratic_equation(equation_form); 
            equation = {
                equation_form,
                result
            };

            print_result(equation); 
        }

        exit_program = wait_for_newline_or_exit();        
             
        if (!exit_program) 
        {
            send_try_again(); 
        }
    }
    printf("Выход!\ns");
    
    return 0;
}

