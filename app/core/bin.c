#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin.h"

// Save data as real binary bytes
int __ac_saveToBinaryFile(const char* _fileName, const char* _data, size_t _dataSize) {
    FILE* _file = fopen(_fileName, "wb");  // Open file in binary write mode
    if (_file == NULL) {
        fprintf(stderr, "01:  !(app/core/bin.c)\nError: Could not open file '%s' for writing.\n", _fileName);
        return 0;
    }

    size_t _written = fwrite(_data, sizeof(char), _dataSize, _file);
    fclose(_file);
    
    if (_written != _dataSize) {
        fprintf(stderr, "02:  !(app/core/bin.c)\nError: Failed to write all data to file '%s'.\n", _fileName);
        return 0;
    }
    
    return 1;
}

// Read byte data from binary file
int __ac_readFromBinaryFile(const char* _fileName, unsigned char** _buffer, size_t* _dataSize) {
    FILE* _file = fopen(_fileName, "rb");  // Open file in binary read mode
    if (_file == NULL) {
        fprintf(stderr, "03:  !(app/core/bin.c)\nError: Could not open file '%s' for reading.\n", _fileName);
        return 0;
    }
    
    fseek(_file, 0, SEEK_END);
    *_dataSize = ftell(_file);
    fseek(_file, 0, SEEK_SET);
    
    *_buffer = (unsigned char*)malloc(*_dataSize);
    if (*_buffer == NULL) {
        fprintf(stderr, "04:  !(app/core/bin.c)\nError: Failed to allocate memory for buffer.\n");
        fclose(_file);
        return 0;
    }
    
    size_t _bytesRead = fread(*_buffer, sizeof(unsigned char), *_dataSize, _file);
    fclose(_file);
    
    if (_bytesRead != *_dataSize) {
        fprintf(stderr, "05:  !(app/core/bin.c)\nError: Failed to read all data from file '%s'.\n", _fileName);
        free(*_buffer);
        return 0;
    }
    
    return 1;
}

// Print byte data to the screen
void __ac_printBinaryData(const unsigned char* _data, size_t _dataSize) {
    printf("Binary data (%zu bytes):\n", _dataSize);
    
    printf("Hex: ");
    for (size_t i = 0; i < _dataSize; i++) {
        printf("%02X ", _data[i]);
    }
    printf("\n");
    
    printf("Text: ");
    for (size_t i = 0; i < _dataSize; i++) {
        if (_data[i] >= 32 && _data[i] <= 126) {
            printf("%c", _data[i]);
        } else {
            printf(".");
        }
    }
    printf("\n");
}

// Set bit value at a specific position
void __ac_setBit(unsigned char* _byte, int _position, int _value) {
    if (_position < 0 || _position > 7) {
        fprintf(stderr, "06:  !(app/core/bin.c)\nError: Invalid bit position.\n");
        return;
    }
    
    if (_value) {
        *_byte |= (1 << _position);  // Set bit to 1
    } else {
        *_byte &= ~(1 << _position); // Set bit to 0
    }
}

// Get bit value at a specific position
int __ac_getBit(const unsigned char* _byte, int _position) {
    if (_position < 0 || _position > 7) {
        fprintf(stderr, "07:  !(app/core/bin.c)\nError: Invalid bit position.\n");
        return -1;
    }
    
    return (*_byte >> _position) & 1;  // Shift bit to position 0 and extract value
}

// Print all bits of the data
void __ac_printBits(const unsigned char* _data, size_t _dataSize) {
    printf("Bits: ");
    for (size_t i = 0; i < _dataSize; i++) {
        for (int j = 7; j >= 0; j--) {  // Print from highest bit (7) to lowest (0)
            printf("%d", __ac_getBit(&_data[i], j));
        }
        printf(" ");  // Add space between bytes
    }
    printf("\n");
}

// Convert a single byte to a binary string (e.g., "01010101")
void __ac_byteToBinaryString(unsigned char _byte, char* _binaryStr) {
    for (int i = 7; i >= 0; i--) {
        _binaryStr[7 - i] = (_byte >> i) & 1 ? '1' : '0';
    }
    _binaryStr[8] = '\0';  // Null terminate the string
}

// Shift bits left across the entire data
void __ac_shiftLeft(unsigned char* _data, size_t _dataSize, int _positions) {
    if (_positions <= 0 || _dataSize == 0) return;
    
    int _totalBits = _dataSize * 8;
    _positions = _positions % _totalBits;  // Normalize shift positions
    
    for (int p = 0; p < _positions; p++) {
        int carry = 0;
        for (size_t i = 0; i < _dataSize; i++) {
            int newCarry = (_data[i] & 0x80) >> 7;  // Get the highest bit
            _data[i] = (_data[i] << 1) | carry;     // Shift left and add carry from previous byte
            carry = newCarry;
        }
    }
}

// Shift bits right across the entire data
void __ac_shiftRight(unsigned char* _data, size_t _dataSize, int _positions) {
    if (_positions <= 0 || _dataSize == 0) return;
    
    int _totalBits = _dataSize * 8;
    _positions = _positions % _totalBits;  // Normalize shift positions
    
    for (int p = 0; p < _positions; p++) {
        int carry = 0;
        for (size_t i = _dataSize - 1; i != (size_t)-1; i--) {
            int newCarry = (_data[i] & 0x01) << 7;  // Get the lowest bit
            _data[i] = (_data[i] >> 1) | carry;     // Shift right and add carry from next byte
            carry = newCarry;
        }
    }
}

// Rotate bits left across the entire data
void __ac_rotateLeft(unsigned char* _data, size_t _dataSize, int _positions) {
    if (_positions <= 0 || _dataSize == 0) return;
    
    int _totalBits = _dataSize * 8;
    _positions = _positions % _totalBits;  // Normalize rotation positions
    
    unsigned char* _temp = (unsigned char*)malloc(_dataSize);
    if (!_temp) {
        fprintf(stderr, "08:  !(app/core/bin.c)\nError: Failed to allocate temporary memory.\n");
        return;
    }
    memcpy(_temp, _data, _dataSize);
    
    for (int p = 0; p < _positions; p++) {
        int carry = (_temp[0] & 0x80) >> 7;  // Get the highest bit of the first byte
        for (size_t i = 0; i < _dataSize; i++) {
            int newCarry = (_temp[i] & 0x80) >> 7;
            _data[i] = (_temp[i] << 1) | carry;
            carry = newCarry;
        }
        _data[_dataSize - 1] |= carry;  // Place the highest bit pushed out into the lowest position
        memcpy(_temp, _data, _dataSize);
    }
    free(_temp);
}

// Rotate bits right across the entire data
void __ac_rotateRight(unsigned char* _data, size_t _dataSize, int _positions) {
    if (_positions <= 0 || _dataSize == 0) return;
    
    int _totalBits = _dataSize * 8;
    _positions = _positions % _totalBits;  // Normalize rotation positions
    
    unsigned char* _temp = (unsigned char*)malloc(_dataSize);
    if (!_temp) {
        fprintf(stderr, "09:  !(app/core/bin.c)\nError: Failed to allocate temporary memory.\n");
        return;
    }
    memcpy(_temp, _data, _dataSize);
    
    for (int p = 0; p < _positions; p++) {
        int carry = (_temp[_dataSize - 1] & 0x01) << 7;  // Get the lowest bit of the last byte
        for (size_t i = _dataSize - 1; i != (size_t)-1; i--) {
            int newCarry = (_temp[i] & 0x01) << 7;
            _data[i] = (_temp[i] >> 1) | carry;
            carry = newCarry;
        }
        _data[0] |= carry;  // Place the lowest bit pushed out into the highest position
        memcpy(_temp, _data, _dataSize);
    }
    free(_temp);
}

// Simple checksum function that calculates the sum of all bytes
unsigned int __ac_calculateChecksum(const unsigned char* _data, size_t _dataSize) {
    unsigned int _checksum = 0;
    for (size_t i = 0; i < _dataSize; i++) {
        _checksum += _data[i];
    }
    return _checksum;
}

// Converts the endianness of the data by reversing the byte order of each group
void __ac_convertEndianness(unsigned char* _data, size_t _dataSize, size_t _numberSize) {
    if (_dataSize % _numberSize != 0) {
        fprintf(stderr, "10:  !(app/core/bin.c)\nWarning: Data size is not a multiple of number size. Some data may not be converted.\n");
    }
    
    for (size_t i = 0; i < _dataSize - (_dataSize % _numberSize); i += _numberSize) {
        size_t start = i;
        size_t end = i + _numberSize - 1;
        while (start < end) {
            unsigned char temp = _data[start];
            _data[start] = _data[end];
            _data[end] = temp;
            start++;
            end--;
        }
    }
}

// Finds the first occurrence of a pattern in the data
int __ac_findPattern(const unsigned char* _data, size_t _dataSize, const unsigned char* _pattern, size_t _patternSize) {
    if (_patternSize > _dataSize) {
        return -1;
    }
    
    for (size_t i = 0; i <= _dataSize - _patternSize; i++) {
        int match = 1;
        for (size_t j = 0; j < _patternSize; j++) {
            if (_data[i + j] != _pattern[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
}

// Counts the number of set bits (1s) in the entire data block
size_t __ac_countSetBits(const unsigned char* _data, size_t _dataSize) {
    size_t _count = 0;
    for (size_t i = 0; i < _dataSize; i++) {
        for (int j = 0; j < 8; j++) {
            if (__ac_getBit(&_data[i], j)) {
                _count++;
            }
        }
    }
    return _count;
}

// Finds the position of the first set bit (starting from the left)
int __ac_findFirstSetBit(const unsigned char* _data, size_t _dataSize) {
    for (size_t i = 0; i < _dataSize; i++) {
        for (int j = 7; j >= 0; j--) {
            if (__ac_getBit(&_data[i], j)) {
                int position = (i * 8) + (7 - j);
                return position;
            }
        }
    }
    return -1;
}

// Finds the position of the last set bit (starting from the right)
int __ac_findLastSetBit(const unsigned char* _data, size_t _dataSize) {
    for (size_t i = _dataSize - 1; i != (size_t)-1; i--) {
        for (int j = 0; j < 8; j++) {
            if (__ac_getBit(&_data[i], j)) {
                int position = (i * 8) + j;
                return position;
            }
        }
    }
    return -1;
}

// Creates a new BinaryData structure with the specified size
BinaryData_* __ac_createBinaryData(size_t _size) {
    BinaryData_* _bd = (BinaryData_*)malloc(sizeof(BinaryData_));
    if (_bd) {
        _bd->_data = (unsigned char*)malloc(_size);
        if (_bd->_data) {
            _bd->_size = _size;
        } else {
            free(_bd);
            _bd = NULL;
        }
    }
    if (!_bd) {
        fprintf(stderr, "11:  !(app/core/bin.c)\nError: Failed to allocate memory for BinaryData.\n");
    }
    return _bd;
}

// Destroys the BinaryData structure and frees its memory
void __ac_destroyBinaryData(BinaryData_* _bd) {
    if (_bd) {
        free(_bd->_data);
        free(_bd);
    }
}

// Creates a copy of the BinaryData structure
BinaryData_* __ac_copyBinaryData(const BinaryData_* _src) {
    if (!_src) {
        fprintf(stderr, "12:  !(app/core/bin.c)\nError: Source BinaryData is NULL.\n");
        return NULL;
    }
    
    BinaryData_* _dest = __ac_createBinaryData(_src->_size);
    if (_dest) {
        memcpy(_dest->_data, _src->_data, _src->_size);
    }
    return _dest;
}