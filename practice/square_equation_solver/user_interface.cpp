#include <stdio.h>

#include "constants.hpp"
#include "structures_and_enums.hpp"



void send_greeting(void)
{
    printf("# Решение квадратного уравнения с помощью дискриминанта. (Esc чтобы выйти)\n");
    printf("# Введите коэффиценты a, b, c для уравнения вида ax^2 + bx + c = 0 через пробел:\n");
}


void send_try_again(void)
{
    printf("# Введите коэффиценты a, b, c для уравнения вида ax^2 + bx + c = 0 через пробел или Esc чтобы выйти\n");
}


int wait_for_newline_or_exit(void)
{
    int exit = 0;
    int c = 0;

    while ((c = getchar()) != '\n')
    {
        if (c == EOF || c == ESCAPE_KEY)
        {
            exit = 1;
            break;
        }
    }
    return exit;
}


int read_input(QuadraticEquationForm* equation_form)
{  
    return scanf("%lg %lg %lg", &equation_form->a, &equation_form->b, &equation_form->c);
}


void print_result(SolvedQuadraticEquation equation)
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