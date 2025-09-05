#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

class Log {
    private:
        static const char *logger_title;
    
    private:
        static void set_logger_title(const char *);
    public:
        static void info(const char *);
        static void warn(const char *);
        static void error(const char *);
        
};

#endif