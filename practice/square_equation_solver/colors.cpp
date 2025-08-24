#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.hpp"

int vprintf_color(const char* color, const char* format, va_list ap)
{
    int result = 0;

    printf("%s", color);
    result = vprintf(format, ap);
    printf("%s", ANSI_COLOR_RESET);

    return result;
}


int printf_red(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    return vprintf_color(ANSI_COLOR_RED, format, ap);
}


int printf_green(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    return vprintf_color(ANSI_COLOR_GREEN, format, ap);
}


int printf_yellow(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    return vprintf_color(ANSI_COLOR_YELLOW, format, ap);
}