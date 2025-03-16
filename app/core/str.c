#include "str.h"




// Function Definitions
// Read a single integer from file
// Returns the read integer or -1 on error
int __fileReadInteger(FILE* _fp) {
    int _value = -1;
    if (_fp != NULL) {
        if (fscanf(_fp, "%d", &_value) != 1) {
            printf("!(app/core/str.c) Error reading integer from file\n");
            return -1;
        }
    }
    return _value;
}


// Read a single float from file
// Returns the read float or -1.0 on error
float __fileReadFloat(FILE* _fp) {
    float _value = -1.0f;
    if (_fp != NULL) {
        if (fscanf(_fp, "%f", &_value) != 1) {
            printf("!(app/core/str.c) Error reading float from file\n");
            return -1.0f;
        }
    }
    return _value;
}


// Read a single double from file
// Returns the read double or -1.0 on error
double __fileReadDouble(FILE* _fp) {
    double _value = -1.0;
    if (_fp != NULL) {
        if (fscanf(_fp, "%lf", &_value) != 1) {
            printf("!(app/core/str.c) Error reading double from file\n");
            return -1.0;
        }
    }
    return _value;
}


// Read a single long integer from file
// Returns the read long or -1L on error
long __fileReadLong(FILE* _fp) {
    long _value = -1L;
    if (_fp != NULL) {
        if (fscanf(_fp, "%ld", &_value) != 1) {
            printf("!(app/core/str.c) Error reading long from file\n");
            return -1L;
        }
    }
    return _value;
}


// Read a single word (string until whitespace) from file
// Returns the read string or NULL on error
// Note: Caller must free the returned string
char* __fileReadWord(FILE* _fp) {
    char _buffer[1024];
    if (_fp != NULL) {
        if (fscanf(_fp, "%1023s", _buffer) == 1) {
            char* _word = (char*)malloc(strlen(_buffer) + 1);
            if (_word != NULL) {
                strcpy(_word, _buffer);
                return _word;
            }
            printf("!(app/core/str.c) Memory allocation failed for word\n");
            return NULL;
        }
        printf("!(app/core/str.c) Error reading word from file\n");
    }
    return NULL;
}


// Read an array of integers from file
// Returns number of integers successfully read
int __fileReadIntegerArray(FILE* _fp, int* _array, int _size) {
    int _count = 0;
    if (_fp != NULL && _array != NULL && _size > 0) {
        for (_count = 0; _count < _size; _count++) {
            if (fscanf(_fp, "%d", &_array[_count]) != 1) {
                break;
            }
        }
    }
    return _count;
}


// Read an array of floats from file
// Returns number of floats successfully read
int __fileReadFloatArray(FILE* _fp, float* _array, int _size) {
    int _count = 0;
    if (_fp != NULL && _array != NULL && _size > 0) {
        for (_count = 0; _count < _size; _count++) {
            if (fscanf(_fp, "%f", &_array[_count]) != 1) {
                break;
            }
        }
    }
    return _count;
}


// Additional function declarations
// Read fixed length string from file
// Returns dynamically allocated string of specified length or NULL on error
// Note: Caller must free the returned string
char* __fileReadStringN(FILE* _fp, int _length) {
    if (_fp != NULL && _length > 0) {
        char* _buffer = (char*)malloc(_length + 1);
        if (_buffer != NULL) {
            int _chars_read = fread(_buffer, 1, _length, _fp);
            if (_chars_read == _length) {
                _buffer[_length] = '\0';
                return _buffer;
            }
            free(_buffer);
            printf("!(app/core/str.c) Error reading %d characters from file\n", _length);
        } else {
            printf("!(app/core/str.c) Memory allocation failed for string\n");
        }
    }
    return NULL;
}


// Read an array of doubles from file
// Returns number of doubles successfully read
int __fileReadDoubleArray(FILE* _fp, double* _array, int _size) {
    int _count = 0;
    if (_fp != NULL && _array != NULL && _size > 0) {
        for (_count = 0; _count < _size; _count++) {
            if (fscanf(_fp, "%lf", &_array[_count]) != 1) {
                break;
            }
        }
    }
    return _count;
}


// Read until specified delimiter character
// Returns dynamically allocated string or NULL on error
// Note: Caller must free the returned string
char* __fileReadUntilDelimiter(FILE* _fp, char _delimiter) {
    if (_fp != NULL) {
        char _buffer[1024];
        int _pos = 0;
        int _char;

        while ((_char = fgetc(_fp)) != EOF && _char != _delimiter) {
            if (_pos < 1023) {
                _buffer[_pos++] = (char)_char;
            }
        }

        if (_pos > 0) {
            _buffer[_pos] = '\0';
            char* _result = (char*)malloc(_pos + 1);
            if (_result != NULL) {
                strcpy(_result, _buffer);
                return _result;
            }
            printf("!(app/core/str.c) Memory allocation failed for delimited string\n");
        }
    }
    return NULL;
}


// Read a boolean value from file (1/0 or true/false)
// Returns 1 for true, 0 for false, -1 on error
int __fileReadBoolean(FILE* _fp) {
    if (_fp != NULL) {
        char _buffer[6];  // Enough for "false" + null
        if (fscanf(_fp, "%5s", _buffer) == 1) {
            if (strcmp(_buffer, "1") == 0 || 
                strcmp(_buffer, "true") == 0 ||
                strcmp(_buffer, "TRUE") == 0) {
                return 1;
            }
            if (strcmp(_buffer, "0") == 0 || 
                strcmp(_buffer, "false") == 0 ||
                strcmp(_buffer, "FALSE") == 0) {
                return 0;
            }
        }
        printf("!(app/core/str.c) Error reading boolean value from file\n");
    }
    return -1;
}


// Check if end of file has been reached
// Returns 1 if EOF reached, 0 if not, -1 on error
int __fileIsEOF(FILE* _fp) {
    if (_fp != NULL) {
        return feof(_fp) ? 1 : 0;
    }
    return -1;
}