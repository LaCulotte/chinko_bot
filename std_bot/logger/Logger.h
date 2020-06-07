#ifndef LOGGER_H
#define LOGGER_H

#include "std_include.h"
#include "thread_include.h"
#include <fstream>
#include <filesystem>
#include <cstdlib>

#define LOG_ERROR "Error - "
#define LOG_IMPORTANT_WARNING "Important warning - "
#define LOG_WARNING "Warning - "
#define LOG_INFO "Info - "
#define LOG_DEBUG "Debug - "

// Global object that logs messages into files
using namespace std;
class Logger{
public:

    // Begin current Logger instance
    static Logger* beginInstance();
    // Finish current Logger instance
    static void endInstance();

    // Initialize the Logger and the log file path
    static void init();

    // Logger writes to the console and into the log file
    static void write(string str, string type = LOG_DEBUG);

    //Full path of the log file
    static string fullLogPath;
private:
    // Constructor
    Logger();
    // Destructor
    ~Logger();

    // Logger object
    static Logger* logger;
    // Path to the current folder
    static string currPath;

    // Log file's output stream
    static ofstream log;

    // Locker to synchronise the writing between the different threads
    static mutex locker;
};

#endif