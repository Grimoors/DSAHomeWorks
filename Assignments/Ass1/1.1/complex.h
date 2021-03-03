//I assume 1 dimentional complex numbers to be real.

#ifndef __COMPLEX_NO__
#define __COMPLEX_NO__

#include "complex_double_elements.h"

complex _initializeComplexNumber(long int N);
complex _inputComplexNumber(complex a);
/* This is unnecessary *///complex _resizeComplexNumber(complex a , long int N);
complex _addComplexNumber(complex a, complex b);
complex _subtractComplexNumber(complex a, complex b);
double _modulusOfComplexNumber(complex a);
double _dotProdOfComplexNumber(complex a, complex b);


void _printComplexNumber(complex a);
void _freeComplexNumber(complex a);


#endif