#include <iostream>




// Function Declarations
#ifndef CIPH_H
#define CIPH_H

#ifdef __cplusplus
extern "C" {
#endif

int __ciphEncrypt(const unsigned char *data, size_t len);

#ifdef __cplusplus
}
#endif

#endif