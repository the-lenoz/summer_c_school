#ifndef LOGGER_DECLARED
#define LOGGER_DECLARED

#define MAX_LOGGER_ANNOTATION_LEN   64
#define MAX_LOGGER_TIMESTAMP_LEN    31


enum LogMessageType
{
    INFO,
    WARNING,
    ERROR
};

//--------------------------------------------------------------
//! @brief int LOG_START(const char* log_file_path)
//! Function opens log file and starts logging
//! @param [in] log_file_path - path to log file
//! @return 0 if started successfully else -1
//--------------------------------------------------------------
int LOG_START(const char* log_file_path, int log_to_stdout);


//--------------------------------------------------------------
//! @brief int LOG(const char* message)
//! Function logs message
//! @param [in] message
//! @return 0 if logged successfully else -1
//--------------------------------------------------------------
int LOG(const char* message, LogMessageType message_type);


//--------------------------------------------------------------
//! @brief int LOG_STOP(const char* log_file_path)
//! Function opens log file and starts logging
//! @param [in] log_file_path - path to log file
//--------------------------------------------------------------
void LOG_STOP(void);


const char* get_log_message_type_str(LogMessageType message_type);

int write_log_annotation(LogMessageType message_type, int file_descriptor);

int log_to_file(const char* message, LogMessageType message_type);

int log_to_stdout(const char* message, LogMessageType message_type);


#endif // LOGGER_DECLARED