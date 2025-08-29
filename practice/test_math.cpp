#include "square_equation_solver/mathematics.hpp"
#include "square_equation_solver/plotter.hpp"
#include <cmath>
#include <cstdlib>
#include <stdio.h>

double sq_eq_001(double x) {return x * x + 2*x - 10;}
double sq_eq_002(double x) {return x * x * x + 3*x*x -6*x - 8;}
double sq_eq_003(double x) {return sin(1/x);}
double sq_eq_004(double x) {return x*x*x*x - x*x*x + x*x * x - x + 1;}
double sq_eq_005(double x) {return (double) rand()/RAND_MAX;}


int main(void)
{
    char* buf = plot_function(sq_eq_001, {.x=160, .y=80}, {.x=40, .y=80});
    printf("%s", buf);
    free(buf);
    buf = plot_function(sq_eq_002, {.x=160, .y=80}, {.x=40, .y=80});
    printf("%s", buf);
    free(buf);
    buf = plot_function(sq_eq_003, {.x=160, .y=80}, {.x=10, .y=5});
    printf("%s", buf);
    free(buf);
    buf = plot_function(sq_eq_004, {.x=160, .y=80}, {.x=40, .y=80});
    printf("%s", buf);
    free(buf);
    buf = plot_function(sq_eq_005, {.x=160, .y=80}, {.x=40, .y=80});
    printf("%s", buf);
    free(buf);
    return 0;
}