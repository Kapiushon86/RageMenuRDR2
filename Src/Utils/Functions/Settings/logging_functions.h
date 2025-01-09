#ifndef LOGGING_FUNCTIONS_H
#define LOGGING_FUNCTIONS_H

#include <fstream>
#include <string>

extern std::ofstream logFile;  // Declare logFile as an external variable
extern int logCounter;         // Declare logCounter as an external variable

void Logging_LoggingFunction();
void WriteLogEntry(std::ofstream& logFile, const std::string& type, const std::string& message, int& logCounter);
void Logging_DetailedLoggingFunction();
void Logging_ConsoleFunction();

#endif
