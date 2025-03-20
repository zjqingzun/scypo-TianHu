#include "user.h"




// Function Definitions
int __erno__(const char* _errorCode) {
    const char *_filePath = "resrc/erno/ERNO.json";

    // Load error messages from JSON file
    cJSON *_errorData = __loadErrorMessages(_filePath);
    if (!_errorData) {
        std::cerr << "01:  !(app/user/erno.cpp)\n";
        std::cerr << "Cannot open file\n";
        return 0;
    }

    // Print with various error codes
    __getErrorMessage(_errorCode, _errorData);

    // Free memory
    cJSON_Delete(_errorData);
    return 1;
}