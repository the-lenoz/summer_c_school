#include <stdio.h>
#include <math.h>
#include <assert.h>

const double eps = 1e-10;


enum NumberOfEquationRoots
{
    ZERO_ROOTS,
    INFINITE_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

struct QuadraticEquationForm
{
    double a;
    double b;
    double c;
};

struct QuadraticEquationSolutionOutput
{
    double x1;
    double x2;
    NumberOfEquationRoots number_of_roots;
};

struct SolvedQuadraticEquation
{
    QuadraticEquationForm form;
    QuadraticEquationSolutionOutput solution_output;
};


void send_greeting(void);
void send_try_again(void);
int read_input(QuadraticEquationForm* equation_form);
void print_result(SolvedQuadraticEquation equation);
int are_doubles_equal(double a, double b);
double solve_linear_equation(double k, double b);
QuadraticEquationSolutionOutput solve_quadratic_equation(QuadraticEquationForm equation_form);

int main(void)
{
    send_greeting();
    QuadraticEquationForm equation_form = {0};
    
    while (read_input(&equation_form) != 3)
    {
        getchar();
        send_try_again();
    }

    QuadraticEquationSolutionOutput result = solve_quadratic_equation(equation_form);

    SolvedQuadraticEquation equation = {
        equation_form,
        result
    };

    print_result(equation);
    
    return 0;
}

//---------------------------------------------------------------
//! void send_greeting(void)
//! @brief Function sends greeting to user. 
//---------------------------------------------------------------
void send_greeting(void)
{
    printf("# Решение квадратного уравнения с помощью дискриминанта. (Нажмите Ctrl+C чтобы выйти)\n");
    printf("# Введите коэффиценты a, b, c для уравнения вида ax^2 + bx + c = 0 через пробел:\n");
}


//---------------------------------------------------------------
//! void send_try_again(void)
//! @brief Function sends try again message to user. 
//---------------------------------------------------------------
void send_try_again(void)
{
    printf("# Неверный формат! Введите коэффиценты a, b, c для уравнения вида ax^2 + bx + c = 0 через пробел:\n");
}
//---------------------------------------------------------------
//! void read_input(void)
//! @brief Function reads user input into a quadratic equation structure.
//!
//! @param [out] equation_form - pointer to target structure 
//!
//! @return number of readed fields
//---------------------------------------------------------------
int read_input(QuadraticEquationForm* equation_form)
{  
    return scanf("%lg %lg %lg", &equation_form->a, &equation_form->b, &equation_form->c);
}

//---------------------------------------------------------------
//! void print_result(SolvedQuadraticEquation equation)
//! @brief Function prints results or quadratic equation solving.
//!
//! @param [in] equation - structure of solved equation to show
//---------------------------------------------------------------
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

//---------------------------------------------------------------
//! int are_doubles_equal(double a, double b)
//! @brief Function compares two doubles with precision gap. 
//!
//! @param [in] a - the first double
//! @param [in] b - the second double
//!
//! @return 1 if there are equal else 0
//---------------------------------------------------------------
int are_doubles_equal(double a, double b)
{
    if (a > b) return (a - b) < eps;
    else return (b - a) < eps;
}

//---------------------------------------------------------------
//! double solve_linear_equation(double k, double b)
//! @brief Function solves linear equation of kx + b = 0 form.
//!
//! @param [in] k - the first coefficent
//! @param [in] k - the second coefficent
//! @param [out] number_of_roots - number of equation roots
//!
//! @return root if exists, INF if anything is a root and NAN if a root doesn't exist.
//---------------------------------------------------------------
double solve_linear_equation(double k, double b, NumberOfEquationRoots* number_of_roots)
{
    if (are_doubles_equal(k, 0)) 
    {
        // Константа, не зависит от x
        if (are_doubles_equal(b, 0))
        {
            *number_of_roots = INFINITE_ROOTS;
        }
        else 
        {
            *number_of_roots = ZERO_ROOTS;
        }
        return NAN;
    }
    else
    {
        *number_of_roots = ONE_ROOT;
        return -b / k; // Корень найден
    }
    
}

//---------------------------------------------------------------
//! int solve_quadratic_equation(double a, double b, double c, double* x1, double* x2)
//! @brief Function solves quadratic equation. a*x^2 + b*x + c = 0. 
//! It receives 3 coefficents (a, b, c) and outputs 2 roots. Returns status code
//!
//! @param [in] a - the first coefficent
//! @param [in] b - the second coefficent
//! @param [in] c - the third coefficent
//! @param [out] x1 - the first root
//! @param [out] x2 - the second root
//!
//! @return status code
//---------------------------------------------------------------
QuadraticEquationSolutionOutput solve_quadratic_equation(QuadraticEquationForm equation_form)
{
    assert(isfinite(equation_form.a));
    assert(isfinite(equation_form.b));
    assert(isfinite(equation_form.c));

    QuadraticEquationSolutionOutput result = {0, 0, TWO_ROOTS};
    
    if (are_doubles_equal(equation_form.a, 0)) // Линейное уравнение
    {
        result.x1 = result.x2 = solve_linear_equation(equation_form.b, equation_form.c, &result.number_of_roots);
        return result;
    }
    
    double D = equation_form.b * equation_form.b - 4 * equation_form.a * equation_form.c;

    if (are_doubles_equal(D, 0))
    {
        result.x1 = (-equation_form.b) / (2 * equation_form.a);
        result.x2 = (-equation_form.b) / (2 * equation_form.a);
        result.number_of_roots = ONE_ROOT;
        return result; // Успех, но корень один
    } 

    if (D < 0) 
    {
        result.number_of_roots = ZERO_ROOTS; 
        return result; // ОШИБКА - корней нет
    } 

    double D_sqrt = sqrt(D);

    result.x1 = (-equation_form.b + D_sqrt) / (2 * equation_form.a);
    result.x2 = (-equation_form.b - D_sqrt) / (2 * equation_form.a);
    result.number_of_roots = TWO_ROOTS;
    return result; // Успех
}
