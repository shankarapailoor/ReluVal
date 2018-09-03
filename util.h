//
// Created by shankara on 9/3/18.
//

#ifndef RELUVAL_UTIL_H
#define RELUVAL_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define AllocVec(type, ptr, size) \
do { \
    *ptr = (type *) calloc(size, sizeof(type)); \
    if (!(*ptr)) { \
        perror("calloc"); \
        exit(1); \
    } \
} while(0)\

#define AllocArray(type, ptr, row, col) \
do { \
    int j; \
    *ptr = (type **) calloc(row, sizeof(type *)); \
    if (!(*ptr)) { \
        perror(__FUNCTION__); \
        exit(1); \
    } \
    for(j = 0; j < row; j++) { \
        AllocVec(type, &((*ptr)[j]), col); \
    } \
} while(0)\

#define FreeArray(ptr, row) \
do { \
    int i; \
    for(i = 0; i < row; i++) { \
        free((*ptr)[i]); \
    } \
    free(*ptr); \
} while(0)\

#endif //RELUVAL_UTIL_H
