#include <iostream>




// Function Declarations
#ifndef SECRUST_H
#define SECRUST_H

#ifdef __cplusplus
extern "C" {
#endif

int __secrustHash(const unsigned char *data, size_t len);

#ifdef __cplusplus
}
#endif

#endif