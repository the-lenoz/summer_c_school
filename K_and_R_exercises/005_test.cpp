#include <stdio.h>

void to_bin(long int x, char* buffer);

int is_negative(long int x);

unsigned long int X_or(unsigned long int x, unsigned long int y);

long int negative(long int x);

long int add(long int x, long int y);

int x_larger_than_y(long int x, long int y);

long int mul(long int x, long int y);

long int power(long int x, long int n);

int main()
{
    long int x = 0;
    char buffer[sizeof(x) << 3 + 1];
    buffer[sizeof(x) << 3] = '\0';
    for (; x < 10; ++x)
    {
        printf("-3^%d = %d\n", x, power(3, x));
    }
    
    return 0;
}

void to_bin(long int x, char* buffer)
{
    unsigned long int mask = 1;
    char bit = 0;
    for (int i = 0; i != (sizeof(x) << 3); ++i)
    {
        bit = ((mask << i) & x) >> i;
        buffer[(sizeof(x) << 3) - 1 - i] = '0' + bit;
    }
}

int is_negative(long int x)
{
    return (int) (x & ((unsigned long int) 1 << add(sizeof(x), -1))) >> add(sizeof(x), -1);
}

unsigned long int X_or(unsigned long int x, unsigned long int y)
{
    return (~(x & y)) & (x | y);
}

long int negative(long int x)
{
    return add(~x, 1);
}


long int add(long int x, long int y)
{
    long int result = 0;
    long int flag = 0;
    for (int i = 0; i != (sizeof(x) << 3); ++i)
    {
        result |= X_or(X_or(((long int)1 << i) & x, ((long int)1 << i) & y), flag << i);
        flag = ((((long int)1 << i) & x) && (((long int)1 << i) & y)) || ((((long int)1 << i) & x) && flag) || ((((long int)1 << i) & y) && flag);

    }
    return result;
}

int x_larger_than_y(long int x, long int y)
{
    return is_negative(add(y, negative(x)));
}

long int mul(long int x, long int y)
{
    int sign = 0;
    if (is_negative(x)) 
    {
        sign = X_or(1, sign);
        x = negative(x);
    }
    if (is_negative(y)) 
    {
        sign = X_or(1, sign);
        y = negative(y);
    }

    long int result = 0;
    for (int i = 0; i < (sizeof(y) << 3); ++i)
    {
        if (((long int)1 << i) & y)
        {
            result = add(result, x << i);
        }
    }
    return sign ? negative(result) : result;
}

long int power(long int x, long int n)
{
    int sign = 0;
    if (is_negative(n)) return 0;
    if (is_negative(x)) {
        sign = 1;
        x = negative(x);
    }
    long int result = 1;
    long int x_pow = x;
    for (int i = 0; (i != add(sizeof(n) << 3, -1) && x_larger_than_y(x, ((long int) 1 << i)), -1); ++i)
    {
        if (((long int) 1 << i) & n)
        {
            result = mul(result, x_pow);
        }
        x_pow = mul(x_pow, x_pow);
    }
    return sign ? ((n & (long int) 1) ? negative(result) : result) : result;
}