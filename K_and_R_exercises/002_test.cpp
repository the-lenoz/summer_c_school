#include <stdio.h>


const int fahr_T_step = 20;
const int upper = 300;
const int lower = 0;

int main()
{
    int celsius, fahr = 0;

    do
    {
        celsius = (fahr - 32) * 5 / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + fahr_T_step;
    }
    while (fahr <= upper);

    return 0;
}