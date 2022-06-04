//I assume 1 dimentional complex numbers to be real.

#ifndef __COMPLEX_NO_HEADER__
#define __COMPLEX_NO_HEADER__

#include "complex_double_elements.h"

void _initializeComplexNumber(long int N, complx num);// input size followed by pointer to "empty" complex number.
void _inputComplexNumber(complx _ToSet);
/* This is unnecessary *///complex _resizeComplexNumber(complex a , long int N);
void _addComplexNumber (complx a, complx b, complx c);// such that c = a+b, where + is complex addition. Pointers to a,b,c are inputted to function.
void _subtractComplexNumber (complx a, complx b, complx c); //such that c = a-b, where - is complex subtraction. Pointers to a,b,c are inputted to the function.
double _modulusOfComplexNumber(complx a);
double _dotProdOfComplexNumber(complx a, complx b);


void _printComplexNumber(complx a);
void _freeComplexNumber(complx a);


#endif