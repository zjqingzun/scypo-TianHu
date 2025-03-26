// include <string.h>
#ifndef STRING_H
#define STRING_H
// config/src/prog-import.json - AC0007

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


// Function Declarations
// Function declarations for reading various data types
int    __fileReadInteger(FILE* _fp);
float  __fileReadFloat(FILE*   _fp);
double __fileReadDouble(FILE*  _fp);
long   __fileReadLong(FILE*    _fp);
char*  __fileReadWord(FILE*    _fp);
int    __fileReadIntegerArray(FILE* _fp, int* _array, int _size);
int    __fileReadFloatArray(FILE* _fp, float* _array, int _size);

// Additional function declarations
char* __fileReadStringN(FILE* _fp, int _length);
int   __fileReadDoubleArray(FILE* _fp, double* _array, int _size);
char* __fileReadUntilDelimiter(FILE* _fp, char _delimiter);
int   __fileReadBoolean(FILE* _fp);
int   __fileIsEOF(FILE* _fp);

#ifdef __cplusplus
}
#endif

#endif