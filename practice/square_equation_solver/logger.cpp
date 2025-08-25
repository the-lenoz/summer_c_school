#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <execinfo.h>

#include "errors.hpp"
#include "colors.hpp"

#include "logger.hpp"




struct LoggerProperties
{
    int log_file_descriptor;
    int log_to_stdout;
    int logging_on;
    const char* filename;
};


static LoggerProperties logger_properties = 
{
    .log_file_descriptor = -1,
    .log_to_stdout = 0,
    .logging_on = 0,
    .filename = NULL
};




int LOG_START(const char* filename, const char* log_file_path, int log_to_stdout)
{
    assert(filename != NULL);

    void* bt_buf[1] = {0};
    backtrace(bt_buf, 1); // MAKE SURE THAT LIBGCC IS LOADED

    if (logger_properties.logging_on)
    {
        print_error(MAKE_ERROR_STRUCT(LOG_START_ERROR));
        return -1;
    }
    if (log_file_path != NULL)
    {
        logger_properties.log_file_descriptor = open(log_file_path, O_CREAT | O_APPEND);

        if (logger_properties.log_file_descriptor == -1)
        {
            print_error(MAKE_ERROR_STRUCT(CANNOT_OPEN_FILE_ERROR));
            return -1;
        }
    }
    else if (!log_to_stdout)
    {
        print_error(MAKE_ERROR_STRUCT(LOG_TARGET_EMPTY_ERROR));
        return -1;
    }

    logger_properties.log_to_stdout = log_to_stdout;
    logger_properties.filename = filename;

    logger_properties.logging_on = 1;

    LOG_MESSAGE("Логгер запущен\n", INFO);

    return 0;
}

int LOG_MESSAGE(const char* message, LogMessageType message_type)
{
    assert(message != NULL);

    int log_status_code = 0;
    
    if (logger_properties.logging_on)
    {
        if (logger_properties.log_file_descriptor != -1)
        {
            if (log_to_file(message, message_type) == -1)
            {
                print_error(MAKE_ERROR_STRUCT(LOG_WRITE_ERROR));
                log_status_code = -1;
            }
        }
        if (logger_properties.log_to_stdout)
        {
            if (log_to_stdout(message, message_type) == -1)
            {
                print_error(MAKE_ERROR_STRUCT(LOG_WRITE_ERROR));
                log_status_code = -1;
            }
        }
    }
    else 
    {
        print_error(MAKE_ERROR_STRUCT(LOGGER_OFF_WRITE_ERROR));
        log_status_code = -1;
    }
    return log_status_code;    
}

int LOG_ERROR(StatusData error_data)
{
    const char* error_description = get_error_description(error_data.status_code);
    char line_number_string[MAX_LINE_NUMBER_STR_LEN] = {0};
    void * backtrace_buffer[BACKTRACE_BUFFER_SIZE] = {0};

    backtrace(backtrace_buffer, BACKTRACE_BUFFER_SIZE);

    sprintf(line_number_string, "%d", error_data.line_number);

    if (LOG_MESSAGE("ОШИБКА:", ERROR) == -1) return -1;
    if (LOG_MESSAGE(error_description, ERROR) == -1) return -1;
    if (LOG_MESSAGE("Произошла в файле:", ERROR) == -1) return -1;
    if (LOG_MESSAGE(error_data.filename, ERROR) == -1) return -1;
    if (LOG_MESSAGE("В функции:", ERROR) == -1) return -1;
    if (LOG_MESSAGE(error_data.func_name, ERROR) == -1) return -1;
    if (LOG_MESSAGE("На строке номер:", ERROR) == -1) return -1;
    if (LOG_MESSAGE(line_number_string, ERROR) == -1) return -1;
    if (LOG_MESSAGE("ТРАССИРОВКА (последний вызов указан последним):", ERROR) == -1) return -1;

    if (logger_properties.log_to_stdout)
    {
        backtrace_symbols_fd(backtrace_buffer, BACKTRACE_BUFFER_SIZE, STDOUT_FILENO);
    }
    if (logger_properties.log_file_descriptor != -1)
    {
        backtrace_symbols_fd(backtrace_buffer, BACKTRACE_BUFFER_SIZE, logger_properties.log_file_descriptor);
    }

    return 0;
}

void LOG_STOP(void)
{
    if (logger_properties.logging_on)
    {
        LOG_MESSAGE("Завершение", INFO);
        if (logger_properties.log_file_descriptor != -1)
        {
            fsync(logger_properties.log_file_descriptor);
            close(logger_properties.log_file_descriptor);
        }
    }
}

const char* get_log_message_type_str(LogMessageType message_type)
{
    switch (message_type)
    {
        case INFO:
            return "INFO";
            break;
        case WARNING:
            return "WARNING";
            break;
        case ERROR:
            return "ERROR";
            break;
        default:
            return "INFO";
            break;
    }
}

int write_log_annotation(LogMessageType message_type, int file_descriptor)
{
    assert(logger_properties.filename != NULL);

    time_t timer;
    char time_buffer[MAX_LOGGER_TIMESTAMP_LEN] = {0};
    char buffer[MAX_LOGGER_ANNOTATION_LEN] = {0};
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(time_buffer, MAX_LOGGER_TIMESTAMP_LEN, " [%Y-%m-%d %H:%M:%S] - [", tm_info);

    if (file_descriptor == STDOUT_FILENO && message_type != INFO)
    {
        if (message_type == WARNING)
        {
            strcat(buffer, ANSI_COLOR_YELLOW);
        }
        else if (message_type == ERROR)
        {
            strcat(buffer, ANSI_COLOR_RED);
        }
    }

    strcat(buffer, logger_properties.filename);
    strncat(buffer, time_buffer, MAX_LOGGER_TIMESTAMP_LEN);
    strcat(buffer, get_log_message_type_str(message_type));
    strcat(buffer, "]: ");

    return write(file_descriptor, buffer, strlen(buffer)) == -1 ? -1 : 0;
}


int log_to_file(const char* message, LogMessageType message_type)
{
    assert(message != NULL);
    assert(logger_properties.log_file_descriptor != -1);

    size_t message_len = strlen(message);

    if (write_log_annotation(message_type, logger_properties.log_file_descriptor) == -1)
    {
        return -1;
    }

    if (write(logger_properties.log_file_descriptor, message, message_len) == -1)
    {
        return -1;
    }

    return 0;

}

int log_to_stdout(const char* message, LogMessageType message_type)
{
    assert(message != NULL);

    size_t message_len = strlen(message);

    if (write_log_annotation(message_type, STDOUT_FILENO) == -1)
    {
        return -1;
    }

    if (write(STDOUT_FILENO, message, message_len) == -1)
    {
        return -1;
    }

    if (write(STDOUT_FILENO, ANSI_COLOR_RESET, ANSI_COLOR_RESET_LEN) == -1)
    {
        return -1;
    }

    if (write(STDOUT_FILENO, "\n", 1) == -1)
    {
        return -1;
    }

    return 0;
}
