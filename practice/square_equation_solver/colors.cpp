#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.hpp"

int vprintf_color(const char* color, const char* format, va_list ap)
{
    int result = 0;
    char* new_format_ptr = NULL;

    size_t color_len = strlen(color);
    size_t color_reset_len = strlen(ANSI_COLOR_RESET);
    size_t format_len = strlen(format);
    
    new_format_ptr = (char*) calloc(format_len + color_len + color_reset_len + 1, sizeof(char));

    strcpy(new_format_ptr, color);
    strcat(new_format_ptr, format);
    strcat(new_format_ptr, ANSI_COLOR_RESET);

    result = vprintf(new_format_ptr, ap);

    free(new_format_ptr);
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