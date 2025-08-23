#ifndef COLORS_DECLARED
#define COLORS_DECLARED

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"

#define ANSI_COLOR_RESET   "\x1b[0m"


//----------------------------------------------------------------------------
//! @brief int printf_red(char* format, ...)
//! This function works like standard printf but prints all in red color
//----------------------------------------------------------------------------
int vprintf_color(const char* color, const char* format, va_list ap);

//----------------------------------------------------------------------------
//! @brief int printf_red(char* format, ...)
//! This function works like standard printf but prints all in red color
//----------------------------------------------------------------------------
int printf_red(const char* format, ...);

//----------------------------------------------------------------------------
//! @brief int printf_green(char* format, ...)
//! This function works like standard printf but prints all in red color
//----------------------------------------------------------------------------
int printf_green(const char* format, ...);

//----------------------------------------------------------------------------
//! @brief int printf_red(char* format, ...)
//! This function works like standard printf but prints all in red color
//----------------------------------------------------------------------------
int printf_yellow(const char* format, ...);

#endif