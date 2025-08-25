#ifndef LOGGER_DECLARED
#define LOGGER_DECLARED

#define MAX_LOGGER_ANNOTATION_LEN   64
#define MAX_LOGGER_TIMESTAMP_LEN    31
#define MAX_LINE_NUMBER_STR_LEN     32

#define BACKTRACE_BUFFER_SIZE 32

enum LogMessageType
{
    INFO,
    WARNING,
    ERROR
};

//--------------------------------------------------------------
//! @brief int LOG_START(const char* filename, const char* log_file_path, int log_to_stdout)
//! Function opens log file and starts logging
//! @param [in] filename - this executable name
//! @param [in] log_file_path - path to log file
//! @param [in] log_to_stdout - should logger write its messages to stdout
//! @return 0 if started successfully else -1
//--------------------------------------------------------------
int LOG_START(const char* filename, const char* log_file_path, int log_to_stdout);

//--------------------------------------------------------------
//! @brief int LOG_MESSAGE(const char* message)
//! Function logs message
//! @param [in] message
//! @return 0 if logged successfully else -1
//--------------------------------------------------------------
int LOG_MESSAGE(const char* message, LogMessageType message_type);

//--------------------------------------------------------------
//! @brief int LOG_ERROR(StatusData error_data)
//! Function logs error
//! @param [in] error_data
//! @return 0 if logged successfully else -1
//--------------------------------------------------------------
int LOG_ERROR(StatusData error_data);

//--------------------------------------------------------------
//! @brief int LOG_STOP(const char* log_file_path)
//! Function opens log file and starts logging
//! @param [in] log_file_path - path to log file
//--------------------------------------------------------------
void LOG_STOP(void);

//--------------------------------------------------------------
//! @brief int get_log_message_type_str(const char* log_file_path)
//! Function to get log message type string by enum
//! @param [in] message_type
//! @return message type string
//--------------------------------------------------------------
const char* get_log_message_type_str(LogMessageType message_type);

//--------------------------------------------------------------
//! @brief int write_log_annotation(const char* log_file_path)
//! Function logs logger annotation
//! @param [in] message_type
//! @param [in] file_descriptor
//! @return -1 on error else 0
//--------------------------------------------------------------
int write_log_annotation(LogMessageType message_type, int file_descriptor);

//--------------------------------------------------------------
//! @brief int log_to_file(const char* message, LogMessageType message_type)
//! Function logs message to log file
//! @param [in] message
//! @param [in] message_type
//! @return -1 on error else 0
//--------------------------------------------------------------
int log_to_file(const char* message, LogMessageType message_type);

//--------------------------------------------------------------
//! @brief int log_to_stdout(const char* message, LogMessageType message_type)
//! Function logs message to stdout
//! @param [in] message
//! @param [in] message_type
//! @return -1 on error else 0
//--------------------------------------------------------------
int log_to_stdout(const char* message, LogMessageType message_type);


#endif // LOGGER_DECLARED