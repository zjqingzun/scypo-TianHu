#include "user.h"




// Function Definitions
bool __helpZmain(std::string _exec, std::string _stdd, std::string _pack) {
    if (_exec == "") {
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

bool __helpZGetPrint(const char *_filePath) {
    if (processAndPrintJson(_filePath)) {
        return true;
    }
    return false;
}

// Function to read the entire file content into a string
std::string readFile(const char* filename) {
    std::ifstream _file(filename);
    std::string content;
    
    if (_file.is_open()) {
        std::string line;
        while (getline(_file, line)) {
            content += line;
        }
        _file.close();
    }
    return content;
}

// Function to print a single JSON item in the required format
void printJsonItem(cJSON* item) {
    // Get the name of the item (interface, gui, norm, etc.)
    const char* title = item->string;
    
    // Get description and syntax fields
    cJSON* description = cJSON_GetObjectItem(item, "description");
    cJSON* syntax = cJSON_GetObjectItem(item, "syntax");

    // Set width for title column (e.g., 15 characters)
    std::cout << "\t" << std::left << std::setw(15) << (title ? title : "[No title]");
    
    // Print description
    if (cJSON_IsString(description) && description->valuestring != NULL) {
        std::cout << description->valuestring;
    } else {
        std::cout << "[No description]";
    }
    std::cout << std::endl;

    // Print syntax on a new line, aligned with title
    std::cout << "\n\t        >>>> ";
    if (cJSON_IsString(syntax) && syntax->valuestring != NULL) {
        std::cout << syntax->valuestring;
    } else {
        std::cout << "[No syntax]";
    }
    std::cout << std::endl << std::endl;
}

// Function to process and print the entire JSON content
bool processAndPrintJson(const char* filename) {
    // Read JSON file content
    std::string jsonStr = readFile(filename);
    
    if (jsonStr.empty()) {
        std::cout << "Unable to read JSON file or file is empty!" << std::endl;
        return false;
    }

    // Parse JSON string
    cJSON* root = cJSON_Parse(jsonStr.c_str());
    if (root == NULL) {
        const char* error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            std::cout << "JSON parsing error: " << error_ptr << std::endl;
        }
        return false;
    }

    // Check if root is an object
    if (!cJSON_IsObject(root)) {
        std::cout << "JSON must be an object!" << std::endl;
        cJSON_Delete(root);
        return false;
    }

    // Iterate through each property in the object
    cJSON* item = NULL;
    cJSON_ArrayForEach(item, root) {
        printJsonItem(item);
    }

    // Free allocated memory
    cJSON_Delete(root);
    return true;
}
