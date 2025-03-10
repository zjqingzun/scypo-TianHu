#include <stdio.h>




#ifndef FILE_H
#define FILE_H

#ifdef __cplusplus
extern "C" {
#endif


// Function Declarations
FILE* __fileOpen(const char* _fileName, const char* _mode);
void __fileClose(FILE* _fp);

void __fileWriteString(FILE* _fp, const char* _str);
void __fileWriteCharacter(FILE* _fp, char _char);

void __fileReadByLine(FILE* _fp);
void __fileReadByCharacter(FILE* _fp);


#ifdef __cplusplus
}
#endif

#endif // FILE_H