#include "logger.h"

const char* Log::logger_title = "KRUGER";

void Log::info(const char *log) {
    printf("INFO %s: %s\n", logger_title, log);
}

void Log::warn(const char *log) {
    printf("WARN %s: %s\n", logger_title, log);
}

void Log::error(const char *log) {
    printf("ERROR %s: %s\n", logger_title, log);
}