#include "../../app/core/file.h"
#include "../../app/core/str.h"




// main()
int main() {
    // Create a test file
    FILE* _fp = __fileOpen("test.txt", "w");
    if (_fp == NULL) return 1;

    // Write test data
    __fileWriteString(_fp, "123 45.67 true Hello\n");
    __fileWriteString(_fp, "89.12 false World\n");
    __fileWriteString(_fp, "1.23 4.56 7.89\n");  // Test data for double array
    __fileWriteString(_fp, "TestString");  // Test data for fixed-length string
    __fileClose(_fp);

    // Read and test
    _fp = __fileOpen("test.txt", "r");
    if (_fp == NULL) return 1;

    // Test integer reading
    int _num = __fileReadInteger(_fp);
    printf("Read integer: %d\n", _num);

    // Test float reading
    float _fnum = __fileReadFloat(_fp);
    printf("Read float: %.2f\n", _fnum);

    // Test boolean reading
    int _boolVal = __fileReadBoolean(_fp);
    printf("Read boolean: %d\n", _boolVal);

    // Test word reading
    char* _word = __fileReadWord(_fp);
    if (_word != NULL) {
        printf("Read word: %s\n", _word);
        free(_word);
    }

    // Test reading until delimiter
    char* _delimStr = __fileReadUntilDelimiter(_fp, '\n');
    if (_delimStr != NULL) {
        printf("Read until newline: %s\n", _delimStr);
        free(_delimStr);
    }

    // Test reading double array
    double _darray[3];
    char _buffer[256];
    if (fgets(_buffer, sizeof(_buffer), _fp) != NULL) {  // Skip the "false World" line
        int count = __fileReadDoubleArray(_fp, _darray, 3);
        printf("Read %d doubles: %.2f %.2f %.2f\n", count, _darray[0], _darray[1], _darray[2]);
    }

    // Test reading fixed length string
    char* _fixedStr = __fileReadStringN(_fp, 10);  // Read "TestString"
    if (_fixedStr != NULL) {
        printf("Read fixed length string: %s\n", _fixedStr);
        free(_fixedStr);
    }

    // Test EOF detection
    printf("EOF reached: %d\n", __fileIsEOF(_fp));

    __fileClose(_fp);
    return 0;
}