#include <stdio.h>
#include <string.h>
#include "stdlib.h"

inline int sum(int a, int b) {
    return a + b;
}

inline char *c_oncat(char *dest, size_t n) {
    size_t n1 = n+=2;
    char *newDest = (char *) malloc(n1);
    char a = 'a';
    strncpy(newDest, dest, n);
    strcat(newDest, &a);
    newDest[n] = '\0';
    return newDest;
}