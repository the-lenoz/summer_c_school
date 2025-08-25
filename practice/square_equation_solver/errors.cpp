#include <stdlib.h>

#include "errors.hpp"

#include "colors.hpp"


void print_error(StatusData error_data)
{
    const char* error_code_string = get_error_description(error_data.status_code);
    printf_red("Произошла ошибка: %s. Файл - %s, функция - %s, строка - %d\n",
                error_code_string, error_data.filename, error_data.func_name, error_data.line_number);
}

const char* get_error_description(StatusCode status_code)
{
    const char* error_code_string = NULL;
    switch(status_code)
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
        case LOGGER_OFF_WRITE_ERROR:
            error_code_string = "ошибка записи лога, логгер выключен";
            break;
        case LOG_START_ERROR:
            error_code_string = "не могу запустить логгер";
            break;
        case SUCCESS:
            error_code_string = "ошибки нет";
            break;
        default:
            error_code_string = "тип неизвестен";
            break;
    }
    return error_code_string;
}