#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin.h"

// Chuyển đổi số thập phân sang nhị phân
void decimalToBinary(int n, char* binaryStr) {
    int i = 0;
    if (n == 0) {
        strcpy(binaryStr, "0");
        return;
    }
    
    while (n > 0) {
        binaryStr[i] = (n % 2) + '0';
        n = n / 2;
        i++;
    }
    binaryStr[i] = '\0';
    
    int len = strlen(binaryStr);
    for (int j = 0; j < len / 2; j++) {
        char temp = binaryStr[j];
        binaryStr[j] = binaryStr[len - 1 - j];
        binaryStr[len - 1 - j] = temp;
    }
}

// Chuyển đổi nhị phân sang thập phân
int binaryToDecimal(const char* binaryStr) {
    int decimal = 0;
    int len = strlen(binaryStr);
    
    for (int i = 0; i < len; i++) {
        if (binaryStr[i] == '1') {
            decimal += 1 << (len - 1 - i);
        }
    }
    return decimal;
}

// Chuyển chuỗi thành nhị phân với giới hạn kích thước
void stringToBinary(const char* str, char* binaryOutput, size_t maxOutputSize) {
    size_t outputIndex = 0;
    for (size_t i = 0; str[i] != '\0' && outputIndex < maxOutputSize - 8; i++) {
        char temp[9];
        decimalToBinary((unsigned char)str[i], temp);
        
        int padding = 8 - strlen(temp);
        for (int j = 0; j < padding && outputIndex < maxOutputSize; j++) {
            binaryOutput[outputIndex++] = '0';
        }
        size_t tempLen = strlen(temp);
        if (outputIndex + tempLen < maxOutputSize) {
            strcpy(binaryOutput + outputIndex, temp);
            outputIndex += tempLen;
        }
    }
    binaryOutput[outputIndex] = '\0';
}

// Chuyển nhị phân thành chuỗi với giới hạn kích thước
void binaryToString(const char* binaryInput, char* strOutput, size_t maxOutputSize) {
    size_t len = strlen(binaryInput);
    size_t outputIndex = 0;
    
    for (size_t i = 0; i < len && outputIndex < maxOutputSize - 1; i += 8) {
        char byte[9];
        strncpy(byte, binaryInput + i, 8);
        byte[8] = '\0';
        strOutput[outputIndex++] = (char)binaryToDecimal(byte);
    }
    strOutput[outputIndex] = '\0';
}

// Lưu dữ liệu lớn vào file nhị phân
int saveToBinaryFile(const char* filename, const char* data, size_t dataSize) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return 0;
    }
    
    // Tính kích thước dữ liệu nhị phân
    size_t binarySize = dataSize * 8 + 1;  // Mỗi ký tự thành 8 bit + null terminator
    char* binaryData = (char*)malloc(binarySize);
    if (binaryData == NULL) {
        fclose(file);
        return 0;
    }
    
    stringToBinary(data, binaryData, binarySize);
    size_t written = fwrite(binaryData, sizeof(char), strlen(binaryData), file);
    
    free(binaryData);
    fclose(file);
    return (written > 0) ? 1 : 0;
}

// Đọc dữ liệu từ file nhị phân vào mảng ký tự động
int readFromBinaryFile(const char* filename, char** buffer, size_t* dataSize) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return 0;
    }
    
    // Xác định kích thước file
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Cấp phát bộ nhớ cho buffer
    *buffer = (char*)malloc(fileSize + 1);
    if (*buffer == NULL) {
        fclose(file);
        return 0;
    }
    
    // Đọc dữ liệu
    *dataSize = fread(*buffer, sizeof(char), fileSize, file);
    (*buffer)[*dataSize] = '\0';
    
    fclose(file);
    return 1;
}

// In dữ liệu nhị phân ra màn hình
void printBinaryData(const char* binaryData, size_t dataSize) {
    printf("Binary data (%zu bytes): ", dataSize);
    for (size_t i = 0; i < dataSize; i++) {
        printf("%c", binaryData[i]);
    }
    printf("\n");
    
    // Chuyển đổi và in dưới dạng chuỗi
    size_t textSize = dataSize / 8 + 1;
    char* text = (char*)malloc(textSize);
    if (text) {
        binaryToString(binaryData, text, textSize);
        printf("As text: %s\n", text);
        free(text);
    }
}