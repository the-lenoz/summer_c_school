#include <cstddef>
#include <stdio.h>
#include "my_assert.hpp"
#include <stdlib.h>

#include "square_equation_types.hpp"

#include "equation_solvers.hpp"

#include "user_interface.hpp"


const int start_max_file_path_len = 512;


int run_user_loop(void)
{
    int input_length = 0;
    InputCharSignal input_char_signal = CORRECT_INPUT;
    SquareEquationForm equation_form = {};
    SquareEquationSolutionOutput result = {};
    SolvedSquareEquation equation = {};
    
    send_greeting();
    do
    {
        input_length = read_input(&equation_form);
        input_char_signal = wait_for_newline_or_exit();

        if (input_length == 3 && input_char_signal == CORRECT_INPUT) 
        {
            result = solve_square_equation(equation_form); 
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


void send_greeting(void)
{
    printf("# Решение квадратного уравнения с помощью дискриминанта. (Esc чтобы выйти)\n");
    printf("# Введите коэффиценты a, b, c для уравнения вида ax^2 + bx + c = 0 через пробел:\n");
}


void send_try_again(void)
{
    printf("# Введите коэффиценты a, b, c для уравнения вида ax^2 + bx + c = 0 через пробел или Esc чтобы выйти\n");
}


InputCharSignal wait_for_newline_or_exit(void)
{
    InputCharSignal result = CORRECT_INPUT;
    int c = 0;

    while ((c = getchar()) != '\n')
    {
        if (c == EOF || c == ESCAPE_KEY)
        {
            result = EXIT_KEY;
            break;
        }
        else
        {
            result = INCORRECT_INPUT;
        }
    }
    return result;
}


int read_input(SquareEquationForm* equation_form)
{  
    assert(equation_form != NULL);

    return scanf("%lg %lg %lg", &equation_form->a, &equation_form->b, &equation_form->c);
}

char* prompt_input_file_path()
{
    char* entered_file_path = (char*)calloc(start_max_file_path_len, sizeof(char));
    printf("Введите путь к файлу с коэффицентами:\n");
    
    int c = 0;
    size_t index = 0;
    size_t current_file_path_len = start_max_file_path_len;
    do
    {
        if (entered_file_path == NULL)
            return NULL;

        c = getchar();
        if (c != '\n' && c != EOF)
        {
            entered_file_path[index++] = (char)c;
            if (index == current_file_path_len)
            {
                current_file_path_len = current_file_path_len << 1;
                entered_file_path = (char*)realloc(entered_file_path, current_file_path_len * sizeof(char));

            }
        }
                    
    } while (c != '\n' && c != EOF);
    return entered_file_path;
}


void print_result(SolvedSquareEquation equation)
{
    printf("Уравнение %lg*x^2 + %lg*x + %lg = 0:\n", equation.form.a, equation.form.b, equation.form.c);
    switch (equation.solution_output.number_of_roots)
    {
        case ZERO_ROOTS:
            printf("Корней нет.\n");
            break;
        case INFINITE_ROOTS:
            printf("Корень - любое число.\n");
            break;
        case ONE_ROOT:
            printf("Единственный корень: x=%g\n", equation.solution_output.x1);
            break;
        case TWO_ROOTS:
            printf("Корни: x1=%g, x2=%g\n", equation.solution_output.x1, equation.solution_output.x2);
            break;
        default:
            break;
    }
}