

struct LoggerProperties
{
    int log_file_descriptor;
    int log
};


//--------------------------------------------------------------
//! @brief int LOG_START(const char* log_file_path)
//! Function opens log file and starts logging
//! @param [in] log_file_path - path to log file
//! @return 1 if 
//--------------------------------------------------------------
int LOG_START(const char* log_file_path);


//--------------------------------------------------------------
//! @brief int LOG(const char* message)
//! Function logs message
//! @param [in] message
//! @return 
//--------------------------------------------------------------
int LOG(const char* message);


//--------------------------------------------------------------
//! @brief int LOG_START(const char* log_file_path)
//! Function opens log file and starts logging
//! @param [in] log_file_path - path to log file
//--------------------------------------------------------------
void LOG_STOP(const char* log_file_path);