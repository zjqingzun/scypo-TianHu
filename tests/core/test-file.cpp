#include "../../app/core/file.h"

int main() {
    // Create a test file
    FILE* fp = __fileOpen("test.txt", "w");
    if (fp == NULL) return 1;

    // Write test data
    __fileWriteString(fp, "123 45.67 true Hello\n");
    __fileWriteString(fp, "89.12 false World\n");
    __fileWriteString(fp, "1.23 4.56 7.89\n");  // Test data for double array
    __fileWriteString(fp, "TestString");  // Test data for fixed-length string
    __fileClose(fp);

    // Read and test
    fp = __fileOpen("test.txt", "r");
    if (fp == NULL) return 1;

    // Test integer reading
    int num = __fileReadInteger(fp);
    printf("Read integer: %d\n", num);

    // Test float reading
    float fnum = __fileReadFloat(fp);
    printf("Read float: %.2f\n", fnum);

    // Test boolean reading
    int bool_val = __fileReadBoolean(fp);
    printf("Read boolean: %d\n", bool_val);

    // Test word reading
    char* word = __fileReadWord(fp);
    if (word != NULL) {
        printf("Read word: %s\n", word);
        free(word);
    }

    // Test reading until delimiter
    char* delim_str = __fileReadUntilDelimiter(fp, '\n');
    if (delim_str != NULL) {
        printf("Read until newline: %s\n", delim_str);
        free(delim_str);
    }

    // Test reading double array
    double darray[3];
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {  // Skip the "false World" line
        int count = __fileReadDoubleArray(fp, darray, 3);
        printf("Read %d doubles: %.2f %.2f %.2f\n", count, darray[0], darray[1], darray[2]);
    }

    // Test reading fixed length string
    char* fixed_str = __fileReadStringN(fp, 10);  // Read "TestString"
    if (fixed_str != NULL) {
        printf("Read fixed length string: %s\n", fixed_str);
        free(fixed_str);
    }

    // Test EOF detection
    printf("EOF reached: %d\n", __fileIsEOF(fp));

    __fileClose(fp);
    return 0;
}