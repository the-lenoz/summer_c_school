#include <execinfo.h>
#include <stdlib.h>
#include <unistd.h>

#include "status.hpp"

#include "terminal_decorator.hpp"


void print_error(StatusData error_data)
{
    const char* error_code_string = get_error_description(error_data.status_code);
    printf_red("Произошла ошибка: %s %s. Файл - %s, функция - %s, строка - %d\n",
                error_code_string, error_data.error_description, error_data.filename, error_data.func_name, error_data.line_number);
}

void print_back_trace(void)
{
    void * backtrace_buffer[BACKTRACE_BUFFER_SIZE] = {0};

    backtrace(backtrace_buffer, BACKTRACE_BUFFER_SIZE);

    int backtrace_size = 0;
    for (;backtrace_size <= BACKTRACE_BUFFER_SIZE && backtrace_buffer[backtrace_size] != NULL; ++backtrace_size)
    {
        // do nothing
    }

    backtrace_symbols_fd(backtrace_buffer, backtrace_size, STDOUT_FILENO);
}

const char* get_error_description(StatusCode status_code)
{
    switch(status_code)
    {
        case CANNOT_OPEN_FILE_ERROR:
            return "не могу открыть файл";
        case CANNOT_ALLOCATE_MEMORY_ERROR:
            return "не могу выделить память";
        case TEST_FAILED_ERROR:
            return "тест провален";
        case LOG_TARGET_EMPTY_ERROR:
            return "старт логгера без цели";
        case LOG_WRITE_ERROR:
            return "ошибка записи лога";
        case LOGGER_OFF_WRITE_ERROR:
            return "ошибка записи лога, логгер выключен";
        case LOG_START_ERROR:
            return "не могу запустить логгер";
        case CANNOT_GET_LOG_TARGETS:
            return "не могу получить лог-файлы";
        case ASSERTION_FAILED:
            return "ASSERTION FAILED";
        case SUCCESS:
            return "ошибки нет";
        default:
            return "тип неизвестен";
    }
}