#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include "logger.hpp"

#define WRITE_AND_EXIT_ON_ERROR(fd, buf, count) if (write(fd, (const void*) buf, count) == -1)\
    {\
        print_error(MAKE_ERROR_STRUCT(LOG_WRITE_ERROR));\
        return -1;\
    }



struct LoggerProperties
{
    int log_file_descriptor;
    int log_to_stdout;
    int logging_on;
};


static LoggerProperties logger_properties = 
{
    .log_file_descriptor = NULL,
    .log_to_stdout = 0,
    .logging_on = 0
};




int LOG_START(const char* log_file_path, int log_to_stdout)
{
    if (logger_properties.logging_on)
    {
        printf_red("Логгер уже запущен\n");
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
    

    logger_properties.logging_on = 1;


    return 0;
}


int LOG(const char* message, LogMessageType message_type)
{
    assert(message != NULL);
    
}


void LOG_STOP(void)
{
    if (logger_properties.logging_on)
    {
        LOG("Завершение", INFO);
        if (logger_properties.log_file_descriptor != NULL)
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
    time_t timer;
    char time_buffer[MAX_LOGGER_TIMESTAMP_LEN];
    char buffer[MAX_LOGGER_ANNOTATION_LEN];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(time_buffer, MAX_LOGGER_TIMESTAMP_LEN, "[%Y-%m-%d %H:%M:%S] - [", tm_info);
    strncpy(buffer, time_buffer, MAX_LOGGER_TIMESTAMP_LEN);
    strcat(buffer, get_log_message_type_str(message_type));
    strcat(buffer, "]: ");
    return write(file_descriptor, buffer, strlen(buffer));
}


int log_to_file(const char* message, LogMessageType message_type)
{
    assert(message != NULL);

    int error_flag = 0;
    size_t message_len = strlen(message);

    write_log_annotation(message_type, logger_properties.log_file_descriptor);

    switch (message_type)
    {
        case INFO:
            //WRITE_AND_EXIT_ON_ERROR();
            break;
        case WARNING:
            break;
        case ERROR:
            break;
        default:
            break;
    }

}

int log_to_stdout(const char* message, LogMessageType message_type)
{
    assert(message != NULL);

    switch (message_type)
    {
        case INFO:
            //WRITE_AND_EXIT_ON_ERROR();

            break;
        case WARNING:
            break;
        case ERROR:
            break;
        default:
            break;
    }
}
