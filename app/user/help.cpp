#include "user.h"




// Function Definitions
// Function to handle help command
bool __helpZmain(std::string _exec, std::string _stdd, std::string _pack) {
    if (_exec == "") {
        // Display the guide
        const char *_fileName = "resrc/sys-doc/guide.txt";
        FILE* _file = __fileOpen(_fileName, "r");
        if (!_file) {
            __erno__("400");
        }
        else {
            __fileReadByLine(_file);
            __fileClose(_file);
        }
        return true;
    }
    else if (_exec == "get") {
        __helpZGet(_stdd, _pack);
        return true;
    }
    return false;
}

// Function to get help content
bool __helpZGet(std::string _stdd, std::string _pack) {
    if (_stdd == "") {
        if (_pack == "") {
            std::string _path = "resrc/abac/mode.json";
            const char* _filePath = _path.c_str();
            if (__helpZGetPrint(_filePath)) {
                return true;
            }
        }
        else {
            std::string _path = "resrc/abac/mode/" + _pack + ".json";
            const char* _filePath = _path.c_str();
            if (__helpZGetPrint(_filePath)) {
                return true;
            }
        }
    }

    return false;
}

// Function to print help content
bool __helpZGetPrint(const char *_filePath) {
    if (__helpZProcessAndPrintJson(_filePath)) {
        return true;
    }
    return false;
}

// Function to read the entire file content into a string
std::string __helpZReadFile(const char* _fileName) {
    std::ifstream _file(_fileName);
    std::string _content;
    
    if (_file.is_open()) {
        std::string line;
        while (getline(_file, line)) {
            _content += line;
        }
        _file.close();
    }
    return _content;
}

// Function to print a single JSON item in the required format
void printJsonItem(cJSON* item) {
    // Get the name of the item (interface, gui, norm, etc.)
    const char* _title = item->string;
    
    // Get description and syntax fields
    cJSON* _description = cJSON_GetObjectItem(item, "description");
    cJSON* _syntax = cJSON_GetObjectItem(item, "syntax");

    // Set width for title column (e.g., 15 characters)
    std::cout << "\t" << std::left << std::setw(15) << (_title ? _title : "[No title]");
    
    // Print description
    if (cJSON_IsString(_description) && _description->valuestring != NULL) {
        std::cout << _description->valuestring;
    } else {
        std::cout << "[No description]";
    }
    std::cout << std::endl;

    // Print syntax on a new line, aligned with title
    std::cout << "\n\t        >>>> ";
    if (cJSON_IsString(_syntax) && _syntax->valuestring != NULL) {
        std::cout << _syntax->valuestring;
    } else {
        std::cout << "[No syntax]";
    }
    std::cout << std::endl << std::endl;
}

// Function to process and print the entire JSON content
bool __helpZProcessAndPrintJson(const char* _fileName) {
    // Read JSON file content
    std::string _jsonStr = __helpZReadFile(_fileName);
    
    if (_jsonStr.empty()) {
        std::cout << "01:  !(app/user/help.cpp)\n";
        std::cout << "Unable to read JSON file or file is empty!" << std::endl;
        return false;
    }

    // Parse JSON string
    cJSON* _root = cJSON_Parse(_jsonStr.c_str());
    if (_root == NULL) {
        const char* error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            std::cout << "02:  !(app/user/help.cpp)\n";
            std::cout << "JSON parsing error: " << error_ptr << std::endl;
        }
        return false;
    }

    // Check if root is an object
    if (!cJSON_IsObject(_root)) {
        std::cout << "03:  !(app/user/help.cpp)\n";
        std::cout << "JSON must be an object!" << std::endl;
        cJSON_Delete(_root);
        return false;
    }

    // Iterate through each property in the object
    cJSON* item = NULL;
    cJSON_ArrayForEach(item, _root) {
        printJsonItem(item);
    }

    // Free allocated memory
    cJSON_Delete(_root);
    return true;
}
