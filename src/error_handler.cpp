#include "error_handler.h"
#include "logger.h"

int16_t handleStatus(int16_t status_id) {
    if(status_id >= 500 && status_id < 600) return handleError(status_id);
    else return handleLog(status_id);
    return 0;
}

// Handle Info Log between id 100 - 200
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

// Handle Errors between id 500 - 599
const char* getErrorMessage(int16_t error_id) {
    switch (error_id) {
        case 500:
            return "No scene found";
        case 501:
            return "New FPS target value below 0";
        case 502:
            return "Cannot instantiate entity in a scene that is not played";
        default:
            return "An unknown error occurred!";
    }
}

int16_t handleError(int16_t error_id) {
    Log::error(getErrorMessage(error_id));
    return error_id;
}