// include <bin.h>
#ifndef BIN_H
#define BIN_H
// config/src/prog-import.json - AC0001

#include "z_type.h"

#ifdef __cplusplus
extern "C" {
#endif


// Function Declarations
/**
 * Saves data to a binary file.
 * @param _fileName The name of the file to save to (const char*).
 * @param _data The data to save (const char*). Can be NULL if _dataSize is 0.
 * @param _dataSize The size of the data in bytes (size_t).
 * @return 1 if successful, 0 if failed (e.g., file cannot be opened or written).
 * @condition If _dataSize > 0, data must not be NULL; if _dataSize = 0, creates an empty file.
 */
int __ac_saveToBinaryFile(const char* _fileName, const char* _data, size_t _dataSize);

/**
 * Reads data from a binary file into a dynamically allocated buffer.
 * @param _fileName The name of the file to read from (const char*).
 * @param _buffer Pointer to an unsigned char* that will be allocated and filled with data.
 * @param _dataSize Pointer to a size_t that will store the size of the read data.
 * @return 1 if successful, 0 if failed (e.g., file not found or memory allocation failed).
 * @condition buffer and _dataSize must not be NULL; caller must free _buffer after use; handles empty files (size = 0).
 */
int __ac_readFromBinaryFile(const char* _fileName, unsigned char** _buffer, size_t* _dataSize);

/**
 * Prints binary data in hex and text format to the screen.
 * @param _data Pointer to the data to print (const unsigned char*).
 * @param _dataSize Size of the data in bytes (size_t).
 * @return None (void).
 * @condition If _dataSize > 0, _data must not be NULL.
 */
void __ac_printBinaryData(const unsigned char* _data, size_t _dataSize);

// Bit manipulation functions

/**
 * Sets a bit at a specific position in a byte.
 * @param _byte Pointer to the byte to modify (unsigned char*).
 * @param _position Position of the bit to set (0-7, 0 is the least significant bit) (int).
 * @param _value Value to set (0 or 1) (int).
 * @return None (void).
 * @condition _byte must not be NULL; if _position is not 0-7, function does nothing.
 */
void __ac_setBit(unsigned char* _byte, int _position, int _value);

/**
 * Gets the value of a bit at a specific position in a byte.
 * @param _byte Pointer to the byte to read (const unsigned char*).
 * @param _position Position of the bit to get (0-7, 0 is the least significant bit) (int).
 * @return Bit value (0 or 1) if successful, -1 if position is invalid (int).
 * @condition _byte must not be NULL.
 */
int __ac_getBit(const unsigned char* _byte, int _position);

/**
 * Prints all bits of the data to the screen.
 * @param _data Pointer to the data to print (const unsigned char*).
 * @param _dataSize Size of the data in bytes (size_t).
 * @return None (void).
 * @condition If _dataSize > 0, _data must not be NULL.
 */
void __ac_printBits(const unsigned char* _data, size_t _dataSize);

/**
 * Converts a byte to a binary string representation (e.g., "01010101").
 * @param _byte The byte to convert (unsigned char).
 * @param _binaryStr Character array to store the binary string, must be at least 9 chars (8 bits + null terminator).
 * @return None (void).
 * @condition _binaryStr must not be NULL and must have space for at least 9 characters.
 */
void __ac_byteToBinaryString(unsigned char _byte, char* _binaryStr);

// Bit shift and rotate functions

/**
 * Shifts all bits in the data to the left by a specified number of positions.
 * @param _data Pointer to the data to shift (unsigned char*).
 * @param _dataSize Size of the data in bytes (size_t).
 * @param _positions Number of positions to shift left (int).
 * @return None (void).
 * @condition If _positions <= 0 or _dataSize = 0, function does nothing; if _dataSize > 0, _data must not be NULL.
 */
void __ac_shiftLeft(unsigned char* _data, size_t _dataSize, int _positions);

/**
 * Shifts all bits in the data to the right by a specified number of positions.
 * @param _data Pointer to the data to shift (unsigned char*).
 * @param _dataSize Size of the data in bytes (size_t).
 * @param _positions Number of positions to shift right (int).
 * @return None (void).
 * @condition If _positions <= 0 or _dataSize = 0, function does nothing; if _dataSize > 0, _data must not be NULL.
 */
void __ac_shiftRight(unsigned char* _data, size_t _dataSize, int _positions);

/**
 * Rotates all bits in the data to the left by a specified number of positions.
 * @param _data Pointer to the data to rotate (unsigned char*).
 * @param _dataSize Size of the data in bytes (size_t).
 * @param _positions Number of positions to rotate left (int).
 * @return None (void).
 * @condition If _positions <= 0 or _dataSize = 0, function does nothing; if _dataSize > 0, _data must not be NULL.
 */
void __ac_rotateLeft(unsigned char* _data, size_t _dataSize, int _positions);

/**
 * Rotates all bits in the data to the right by a specified number of positions.
 * @param _data Pointer to the data to rotate (unsigned char*).
 * @param _dataSize Size of the data in bytes (size_t).
 * @param _positions Number of positions to rotate right (int).
 * @return None (void).
 * @condition If _positions <= 0 or _dataSize = 0, function does nothing; if _dataSize > 0, _data must not be NULL.
 */
void __ac_rotateRight(unsigned char* _data, size_t _dataSize, int _positions);

// New features

/**
 * Calculates a simple checksum by summing all bytes in the data.
 * @param _data Pointer to the data to checksum (const unsigned char*).
 * @param _dataSize Size of the data in bytes (size_t).
 * @return Sum of all bytes (unsigned int). Note: This is a basic checksum; consider CRC for better integrity.
 * @condition If _dataSize > 0, _data must not be NULL.
 */
unsigned int __ac_calculateChecksum(const unsigned char* _data, size_t _dataSize);

/**
 * Converts the endianness of the data by reversing the byte order of each group of 'numberSize' bytes.
 * @param _data Pointer to the data to convert (unsigned char*).
 * @param _dataSize Total size of the data in bytes (size_t).
 * @param _numberSize Size of each number in bytes (e.g., 2 for 16-bit, 4 for 32-bit) (size_t).
 * @return None (void).
 * @condition If _dataSize is not a multiple of _numberSize, some data may not be converted; if _dataSize > 0, _data must not be NULL.
 */
void __ac_convertEndianness(unsigned char* _data, size_t _dataSize, size_t _numberSize);

/**
 * Finds the first occurrence of a pattern in the data.
 * @param _data Pointer to the data to search (const unsigned char*).
 * @param _dataSize Size of the data in bytes (size_t).
 * @param _pattern Pointer to the pattern to find (const unsigned char*).
 * @param _patternSize Size of the pattern in bytes (size_t).
 * @return Position of the first occurrence (int), or -1 if not found. Note: Returns 0 if _patternSize = 0.
 * @condition If _patternSize > _dataSize, returns -1; if _dataSize or _patternSize > 0, respective pointers must not be NULL.
 */
int __ac_findPattern(const unsigned char* _data, size_t _dataSize, const unsigned char* _pattern, size_t _patternSize);

/**
 * Counts the number of set bits (1s) in the entire data block.
 * @param _data Pointer to the data (const unsigned char*).
 * @param _dataSize Size of the data in bytes (size_t).
 * @return Number of set bits (size_t).
 * @condition If _dataSize > 0, _data must not be NULL.
 */
size_t __ac_countSetBits(const unsigned char* _data, size_t _dataSize);

/**
 * Finds the position of the first set bit (starting from the left, most significant bit).
 * @param _data Pointer to the data (const unsigned char*).
 * @param _dataSize Size of the data in bytes (size_t).
 * @return Position of the first set bit (int, 0 is the MSB of the first byte), or -1 if none found.
 * @condition If _dataSize > 0, _data must not be NULL.
 */
int __ac_findFirstSetBit(const unsigned char* _data, size_t _dataSize);

/**
 * Finds the position of the last set bit (starting from the right, least significant bit).
 * @param _data Pointer to the data (const unsigned char*).
 * @param _dataSize Size of the data in bytes (size_t).
 * @return Position of the last set bit (int, 0 is the MSB of the first byte), or -1 if none found.
 * @condition If _dataSize > 0, _data must not be NULL.
 */
int __ac_findLastSetBit(const unsigned char* _data, size_t _dataSize);

/**
 * Creates a new BinaryData structure with the specified size.
 * @param _size Size of the data to allocate (size_t).
 * @return Pointer to the new BinaryData structure, or NULL if allocation fails.
 * @condition _size must be >= 0; reports error if allocation fails.
 */
BinaryData_* __ac_createBinaryData(size_t _size);

/**
 * Destroys the BinaryData structure and frees its memory.
 * @param _bd Pointer to the BinaryData structure to destroy (BinaryData*).
 * @return None (void).
 * @condition Safe to pass NULL; no action taken if NULL.
 */
void __ac_destroyBinaryData(BinaryData_* _bd);

/**
 * Creates a copy of the BinaryData structure.
 * @param _src Pointer to the source BinaryData structure to copy (const BinaryData*).
 * @return Pointer to the new copied BinaryData structure, or NULL if allocation fails or src is NULL.
 * @condition If _src is NULL, returns NULL and reports error.
 */
BinaryData_* __ac_copyBinaryData(const BinaryData_* _src);


#ifdef __cplusplus
}
#endif

#endif