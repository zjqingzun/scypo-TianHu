#include "test.h"




// Function Definitions
void __test000001() {
    // TEST ----------------------------------ciph and secrust
    const char* _data = "test";
    size_t _len = 4;

    int _encrypted = __ciphEncrypt((const unsigned char*)_data, _len);
    std::cout << "\nEncrypted value: " << _encrypted << std::endl;

    int _hashed = __secrustHash((const unsigned char*)_data, _len);
    std::cout << "Hashed value: " << _hashed << std::endl;
}

void __test000002() {
    // TEST ----------------------------------zerotrace
    int _result = zerotrace_scan("127.0.0.1", "80-100", 0, 500, 20, -1, NULL);
    if (_result == 0) {
        printf("Scan completed successfully\n");
    } else {
        printf("01:  !(app/proc/test.cpp)\nScan failed with error: %d\n", _result);
    }
}

int __test000003() {
    // TEST ----------------------------------app/core/bin
    
    // Sample data
    const char* _largeData = "Hello, World!";
    size_t _dataSize = strlen(_largeData);

    // Save data to file
    if (__ac_saveToBinaryFile("cache/data/data.bin", _largeData, _dataSize)) {
        printf("Successfully saved %zu bytes to data.bin\n", _dataSize);
    } else {
        printf("02: !(app/proc/test.cpp)\nFailed to save data\n");
        return 1;
    }

    // Read data from file
    unsigned char* _buffer = NULL;
    size_t _readSize = 0;
    if (__ac_readFromBinaryFile("cache/data/data.bin", &_buffer, &_readSize)) {
        printf("Successfully read %zu bytes from file\n", _readSize);
    
        // Print original data
        printf("Original data:\n");
        __ac_printBinaryData(_buffer, _readSize);
        __ac_printBits(_buffer, _readSize);
    
        // Calculate checksum
        unsigned int checksum = __ac_calculateChecksum(_buffer, _readSize);
        printf("Checksum: %u\n", checksum);
    
        // Find pattern before converting endianness
        const unsigned char pattern[] = {0x6f, 0x2c}; // 'o '
        size_t patternSize = sizeof(pattern);
        int patternPos = __ac_findPattern(_buffer, _readSize, pattern, patternSize);
        if (patternPos != -1) {
            printf("Pattern found at position %d\n", patternPos);
        } else {
            printf("Pattern not found\n");
        }
        
        // Convert endianness only if size is a multiple of 2
        if (_readSize % 2 != 0) {
            printf("Skipping endianness conversion: Data size (%zu) is not a multiple of 2.\n", _readSize);
        } else {
            __ac_convertEndianness(_buffer, _readSize, 2);
            printf("\nAfter converting endianness (2-byte numbers):\n");
            __ac_printBinaryData(_buffer, _readSize);
            __ac_printBits(_buffer, _readSize);
        }
        
        // Count set bits
        size_t setBits = __ac_countSetBits(_buffer, _readSize);
        printf("Number of set bits: %zu\n", setBits);
        
        // Find first and last set bits
        int _firstSetBit = __ac_findFirstSetBit(_buffer, _readSize);
        int _lastSetBit = __ac_findLastSetBit(_buffer, _readSize);
        printf("First set bit position: %d\n", _firstSetBit);
        printf("Last set bit position: %d\n", _lastSetBit);
        
        // Memory management example
        BinaryData_* _bd = __ac_createBinaryData(_readSize);
        if (_bd) {
            memcpy(_bd->_data, _buffer, _readSize);
            printf("Copied data to BinaryData structure.\n");
            __ac_destroyBinaryData(_bd);
        }
        
        free(_buffer);  // Free allocated memory
    } else {
        printf("04: !(app/proc/test.cpp)\nFailed to read data\n");
        return 1;
    }

    return 0;
}