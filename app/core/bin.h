// include <bin.h>
#ifndef BIN_H
#define BIN_H
// config/src/prog-import.json - AC0001

#include <stddef.h>  // Để dùng size_t

#ifdef __cplusplus
extern "C" {
#endif


// Function Declarations
// Khai báo các hàm
void decimalToBinary(int n, char* binaryStr);
int binaryToDecimal(const char* binaryStr);
void stringToBinary(const char* str, char* binaryOutput, size_t maxOutputSize);
void binaryToString(const char* binaryInput, char* strOutput, size_t maxOutputSize);
int saveToBinaryFile(const char* filename, const char* data, size_t dataSize);
int readFromBinaryFile(const char* filename, char** buffer, size_t* dataSize);
void printBinaryData(const char* binaryData, size_t dataSize);

#ifdef __cplusplus
}
#endif

#endif