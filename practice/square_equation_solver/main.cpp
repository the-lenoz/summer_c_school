#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "structures.hpp"

#include "user_interface.hpp"
#include "equation_solvers.hpp"


int main(void)
{
    int input_length = 0;
    InputCharSignal input_char_signal = CORRECT_INPUT;
    QuadraticEquationForm equation_form = {0};
    QuadraticEquationSolutionOutput result = {0};
    SolvedQuadraticEquation equation = {0};
    
    send_greeting();
    do
    {
        input_length = read_input(&equation_form);
        input_char_signal = wait_for_newline_or_exit();

        if (input_length == 3 and input_char_signal == CORRECT_INPUT) 
        {
            result = solve_quadratic_equation(equation_form); 
            equation = {
                equation_form,
                result
            };

            print_result(equation); 
        }        
             
        if (input_char_signal != EXIT_KEY) 
        {
            send_try_again(); 
        }
    }
    while (input_char_signal != EXIT_KEY);

    printf("Выход!\n");
    
    return 0;
}

