#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "square_equation_structures.hpp"
#include "solver_enums.hpp"

#include "equation_solvers.hpp"
#include "user_interface.hpp"
#include "cli.hpp"

// -f / --file file_name
// ./main -f -h
// -t / --test

const int max_file_path_len = 512;

void print_help(void)
{
    printf("Решатель квадратных уравнений. Вызов:\n");
    printf("main [-флаги] [аргументы]\n");
    printf("    --help, -h                  -   Показать подсказку\n");
    printf("    --file [путь], -f [путь]    -   Считать коэффиценты из файла\n");
    printf("    --test, -t                  -   Запустить юнит-тесты\n");
    printf("    [a b c]                     -   3 вещественных числа - решить квадратное уравнение вида ax^2 + bx + c = 0\n");
    printf("                                -   Без аргументов - запустить в интерактивном режиме\n");
}

int is_flag_set(int argc, char** argv, char* flag)
{
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(flag, argv[i]) == 0)
        {
            return i;
        }
    }
    return 0;
}


int run_cli_from_args(int argc, char** argv)
{
    if (argc == 4){
        QuadraticEquationForm equation_form = {};
        equation_form.a = strtod(argv[1], NULL);
        equation_form.b = strtod(argv[2], NULL);
        equation_form.c = strtod(argv[3], NULL);
        QuadraticEquationSolutionOutput result = solve_quadratic_equation(equation_form); 

        SolvedQuadraticEquation equation = {
            equation_form,
            result
        };
        print_result(equation); 
    }
    else 
    {
        print_help();
        return 1;
    }
    return 0;
}

int run_cli_from_file(char* file_path)
{
    FILE* file_ptr = NULL;
    QuadraticEquationForm equation_form = {};
    SolvedQuadraticEquation equation = {};
    QuadraticEquationSolutionOutput result = {};
    char entered_file_path[max_file_path_len] = {0};

    if (file_path == NULL)
    {
        printf("Введите путь к файлу с коэффицентами:\n");
        
        fgets(entered_file_path, max_file_path_len - 1, stdin);
        
        entered_file_path[strcspn(entered_file_path, "\n")] = 0;

        file_ptr = fopen(entered_file_path, "r+");   
    }
    else
    {
        file_ptr = fopen(file_path, "r+");
    }

    
    if (file_ptr == NULL)
    {
        printf("Ошибка: не могу открыть файл!\n");
        return 1;
    }
    while (fscanf(file_ptr, "%lg %lg %lg\n", &equation_form.a, &equation_form.b, &equation_form.c) == 3)
    {
        result = solve_quadratic_equation(equation_form); 
        equation = {
            equation_form,
            result
        };
        print_result(equation); 
    }

    fclose(file_ptr);
    return 0;
}