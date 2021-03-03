#include <stdio.h>
#include <stdlib.h>

#ifndef __COMPLEX_DOUBLE_ELEMENTS__
#define __COMPLEX_DOUBLE_ELEMENTS__

struct complex
{
    long int N;
    double* _values;
};

typedef struct complex complex;

#endif