#include "logging_functions.h"
#include "../../Config/settings_manager.h"
#include "../../../../Menu/Base/Submenus/Main/Settings/logging.h"
#include "../../../../Utils/Saving/States/Settings/logging_default_states.h"
#include "../../Config/config.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <ctime>
#include <Windows.h>
#include <Lmcons.h>
#include <thread>

std::ofstream logFile; 
int logCounter = 1;

std::string CapitalizeWords(const std::string& str) {
    std::stringstream ss(str);
    std::string word;
    std::string result;

    while (ss >> word) {
        word[0] = std::toupper(word[0]);
        for (size_t i = 1; i < word.size(); ++i) {
            word[i] = std::tolower(word[i]);
        }
        result += word + " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

std::string CapitalizeType(const std::string& type) {
    std::string capitalizedType = type;
    if (!capitalizedType.empty()) {
        capitalizedType[0] = std::toupper(capitalizedType[0]);
        for (size_t i = 1; i < capitalizedType.size(); ++i) {
            capitalizedType[i] = std::tolower(capitalizedType[i]);
        }
    }
    return capitalizedType;
}

void WriteLogEntry(std::ofstream& logFile, const std::string& type, const std::string& message, int& logCounter) {
    auto now = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &now);

    std::ostringstream timeStream;
    timeStream << std::setw(2) << std::setfill('0') << (localTime.tm_hour % 12 == 0 ? 12 : localTime.tm_hour % 12)
        << ":" << std::setw(2) << std::setfill('0') << localTime.tm_min
        << ":" << std::setw(2) << std::setfill('0') << localTime.tm_sec
        << (localTime.tm_hour >= 12 ? " PM" : " AM");

    std::ostringstream dateStream;
    dateStream << std::setw(2) << std::setfill('0') << (localTime.tm_mon + 1) << "-"
        << std::setw(2) << std::setfill('0') << localTime.tm_mday << "-"
        << (localTime.tm_year + 1900);

    std::string capitalizedType = CapitalizeType(type);
    std::string capitalizedMessage = CapitalizeWords(message);

    std::ostringstream logStream;
    logStream << std::setw(10) << std::setfill('0') << logCounter++ << " | "
        << dateStream.str() << " | "
        << timeStream.str() << " | "
        << std::setw(3) << capitalizedType << " | "
        << capitalizedMessage;

    std::string logEntry = logStream.str();

    if (logFile.is_open()) {
        logFile << logEntry << std::endl;
    }

    if (logging_console_bool) {
        std::cout << logEntry << std::endl;
    }
}

void WriteLogEntryWithDelay(std::ofstream& logFile, const std::string& logType, const std::string& message, int& logCounter) {
    WriteLogEntry(logFile, logType, message, logCounter);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Logging_LoggingFunction() {
    static bool isLoggingActive = false;

    if (logging_logging_bool) {
        if (!isLoggingActive) {
            logCounter = 1;
            Config config;
            std::string dateSpecificFolderPath = config.GetDateSpecificFolderPath();

            if (!std::filesystem::create_directories(dateSpecificFolderPath) &&
                !std::filesystem::exists(dateSpecificFolderPath)) {
                return;
            }

            auto now = std::time(nullptr);
            std::tm localTime;
            localtime_s(&localTime, &now);

            std::ostringstream timeStream;
            timeStream << std::setw(2) << std::setfill('0') << (localTime.tm_hour % 12 == 0 ? 12 : localTime.tm_hour % 12)
                << "-" << std::setw(2) << std::setfill('0') << localTime.tm_min
                << "-" << std::setw(2) << std::setfill('0') << localTime.tm_sec
                << (localTime.tm_hour >= 12 ? "_PM" : "_AM");

            std::string logFilePath = dateSpecificFolderPath + "\\RageMenu-" + timeStream.str() + ".log";

            logFile.open(logFilePath, std::ios::out | std::ios::app);
            if (!logFile.is_open()) {
                return;
            }
            isLoggingActive = true;
        }
    }
    else {
        if (isLoggingActive) {
            if (logFile.is_open()) {
                logFile.close();
            }
            isLoggingActive = false;
        }
    }
}

void Logging_DetailedLoggingFunction() {

}

void Logging_ConsoleFunction() {
    if (logging_console_bool) {
        if (!GetConsoleWindow()) { 
            AllocConsole();
            freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
            freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);

            SetConsoleTitleA("RageMenu Logging Console");

            std::cout << "Console logging is active." << std::endl;
            std::cout << "Welcome to RageMenu Logging Console." << std::endl;

            HWND consoleWindow = GetConsoleWindow();
            if (consoleWindow) {
                SetForegroundWindow(consoleWindow);
            }
        }
    }
    else {
        HWND consoleWindow = GetConsoleWindow();
        if (consoleWindow) {
            FreeConsole(); 
        }
    }
}