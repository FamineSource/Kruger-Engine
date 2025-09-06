#include "error_handler.h"
#include "logger.h"

int16_t handleStatus(int16_t status_id) {
    if(status_id >= 500 && status_id <= 749) return handleError(status_id);
    else if(status_id >= 250 && status_id <= 499) return handleWarn(status_id);
    else return handleLog(status_id);
    return 0;
}

// Handle Info Log between id 0 - 249
const char* getLogMessage(int16_t status_id) {
    switch (status_id) {
        default:
            return "An unknown information occurred!";
    }
}

int16_t handleLog(int16_t status_id) {
    Log::info(getLogMessage(status_id));
    return status_id;
}

// Handle Warning between id 250 - 499
const char* getWarnMessage(int16_t warn_id) {
    switch (warn_id) {
        case 260:
            return "System could not find component searched";
        default:
            return "An unknown warning occurred!";
    }
}

int16_t handleWarn(int16_t warn_id) {
    Log::warn(getWarnMessage(warn_id));
    return warn_id;
}

// Handle Errors between id 500 - 749
// 0 - 10: Scene Errors
const char* getErrorMessage(int16_t error_id) {
    switch (error_id) {
        case 500:
            return "No scene found";
        case 501:
            return "Scene index out of bounds";
        case 511:
            return "New FPS target value below 0";
        default:
            return "An unknown error occurred!";
    }
}

int16_t handleError(int16_t error_id) {
    Log::error(getErrorMessage(error_id));
    return error_id;
}