#include "Logger.h"
#include <experimental/filesystem>
#include <time_include.h>

Logger * Logger::logger = NULL;
string Logger::currPath = "";
string Logger::fullLogPath = "";
ofstream Logger::log;
mutex Logger::locker;

using namespace std;

Logger::Logger(){
}

Logger::~Logger(){
    endInstance();
}

void Logger::endInstance(){
    // Closes the file
    log.close();

    // Copies the file into a easily acessible file : last-log.txt
    experimental::filesystem::copy(fullLogPath, currPath + "/logs/last-log.txt", experimental::filesystem::copy_options::overwrite_existing);
}

Logger* Logger::beginInstance(){
    if(!logger) {
        logger = new Logger();
        logger->init();
    }
    return logger;
}

void Logger::init(){
    // Gets path to the current folder
    currPath = experimental::filesystem::current_path();

    // Build log file's path with current date and time
    time_t currentTime = time(NULL);
    tm *localCurrentTime = localtime(&currentTime);
    fullLogPath = currPath + "/logs/log" + "_" + \
        (localCurrentTime->tm_mday<10?"0":"") + to_string(localCurrentTime->tm_mday) + "-" + \
        (localCurrentTime->tm_mon<10?"0":"") + to_string(localCurrentTime->tm_mon) + "-" + \
        to_string(localCurrentTime->tm_year%100) + "_" + \
        (localCurrentTime->tm_hour<10?"0":"") + to_string(localCurrentTime->tm_hour) + ":" + \
        (localCurrentTime->tm_min<10?"0":"") + to_string(localCurrentTime->tm_min) + ":" + \
        (localCurrentTime->tm_sec<10?"0":"") + to_string(localCurrentTime->tm_sec) + ".txt";
    
    // Creates the log file
    log.open(fullLogPath);
}

void Logger::write(string str, string type){
    // Tries to access the file
    unique_lock<mutex> u_lock(locker, defer_lock);

    while(!u_lock.try_lock());

    // Writes the message (str) with the type of message and the current time
    time_t currentTime = time(NULL);
    tm *localCurrentTime = localtime(&currentTime);


    cout << "[" << (localCurrentTime->tm_hour<10?"0":"") << to_string(localCurrentTime->tm_hour) << ":" << (localCurrentTime->tm_min<10?"0":"") << to_string(localCurrentTime->tm_min) << ":" << (localCurrentTime->tm_sec<10?"0":"") << to_string(localCurrentTime->tm_sec) << "] " << type << str << endl; 
    log << "[" << (localCurrentTime->tm_hour<10?"0":"") << to_string(localCurrentTime->tm_hour) << ":" << (localCurrentTime->tm_min<10?"0":"") << to_string(localCurrentTime->tm_min) << ":" << (localCurrentTime->tm_sec<10?"0":"") << to_string(localCurrentTime->tm_sec) << "] " << type << str << endl; 
}