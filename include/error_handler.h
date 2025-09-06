#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <stdio.h>
#include <string.h>
#include <cstdint>

int16_t handleStatus(int16_t);

const char* getLogMessage(int16_t);
int16_t handleLog(int16_t);

const char* getWarnMessage(int16_t);
int16_t handleWarn(int16_t);

// Errors
const char* getErrorMessage(int16_t);
int16_t handleError(int16_t);

#endif