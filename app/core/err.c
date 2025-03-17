#include "err.h"




// Function Definitions
// Function to load error messages from a JSON file
cJSON *__loadErrorMessages(const char *_filePath) {
    FILE *_file = fopen(_filePath, "r");
    if (!_file) {
        fprintf(stderr, "!(app/core/err.c): 01\nCannot open file: %s\n", _filePath);
        return NULL;
    }

    // Determine file size
    fseek(_file, 0, SEEK_END);
    long _fileSize = ftell(_file);
    fseek(_file, 0, SEEK_SET);

    // Allocate memory for file content
    char *_fileContent = (char *)malloc(_fileSize + 1);
    if (!_fileContent) {
        fprintf(stderr, "!(app/core/err.c): 02\nMemory allocation failed for reading file\n");
        fclose(_file);
        return NULL;
    }

    // Read file content
    fread(_fileContent, 1, _fileSize, _file);
    _fileContent[_fileSize] = '\0';
    fclose(_file);

    // Parse JSON content
    cJSON *_root = cJSON_Parse(_fileContent);
    free(_fileContent);

    if (!_root) {
        fprintf(stderr, "!(app/core/err.c): 03\nError parsing JSON: %s\n", cJSON_GetErrorPtr());
        return NULL;
    }

    return _root;
}


// Function to retrieve and print error message based on error code
void __getErrorMessage(const char *_errorCode, cJSON *_errorData) {
    if (!_errorData) {
        printf("!(app/core/err.c): 04\nError data is not available\n");
        return;
    }

    // Look for the error object corresponding to the error code
    cJSON *_errorObj = cJSON_GetObjectItem(_errorData, _errorCode);
    if (!_errorObj || !cJSON_IsObject(_errorObj)) {
        printf("!(app/core/err.c): 05\nError Code: %s\n", _errorCode);
        printf("  Message: No error information found for this code\n\n");
        return;
    }

    // Extract message, description, and suggestion fields
    cJSON *_message = cJSON_GetObjectItem(_errorObj, "message");
    cJSON *_description = cJSON_GetObjectItem(_errorObj, "description");
    cJSON *_suggestion = cJSON_GetObjectItem(_errorObj, "suggestion");

    // Print error information
    printf("Error Code: %s\n", _errorCode);
    printf("   Message: %s\n", cJSON_IsString(_message) ? _message->valuestring : "No message available");
    printf("   Description: %s\n", cJSON_IsString(_description) ? _description->valuestring : "No description available");
    printf("   Suggestion: %s\n\n", cJSON_IsString(_suggestion) ? _suggestion->valuestring : "No suggestion available");
}