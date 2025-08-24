#include <stdlib.h>

#include "errors.hpp"

#include "colors.hpp"


void print_error(StatusData error)
{
    const char* error_code_string = NULL;
    switch(error.status_code)
    {
        case CANNOT_OPEN_FILE_ERROR:
            error_code_string = "не могу открыть файл";
            break;
        case TEST_FAILED_ERROR:
            error_code_string = "тест провален";
            break;
        case LOG_TARGET_EMPTY_ERROR:
            error_code_string = "старт логгера без цели";
            break;
        case LOG_WRITE_ERROR:
            error_code_string = "ошибка записи лога";
            break;
        case SUCCESS:
            error_code_string = "ошибки нет";
            break;
        default:
            error_code_string = "тип неизвестен";
            break;
    }
    printf_red("Произошла ошибка: %s. Файл - %s, функция - %s, строка - %d\nЗавершение программы.\n",
                error_code_string, error.filename, error.func_name, error.line_number);
}