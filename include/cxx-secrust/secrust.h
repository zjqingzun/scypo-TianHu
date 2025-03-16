#include <iostream>




// Function Declarations
#ifndef SECRUST_H
#define SECRUST_H

#ifdef __cplusplus
extern "C" {
#endif

int __secrustHash(const unsigned char *_data, size_t _len);

#ifdef __cplusplus
}
#endif

#endif