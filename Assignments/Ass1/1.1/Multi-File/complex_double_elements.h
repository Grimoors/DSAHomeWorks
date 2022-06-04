#include <stdio.h>
#include <stdlib.h>

#ifndef __COMPLEX_DOUBLE_ELEMENTS__
#define __COMPLEX_DOUBLE_ELEMENTS__


//I assume 1 dimentional complex numbers to be completely real.


//contents of complex_double_elements.h
/*
*
*           DEFINIES THE COMPLEX NO. AS AN INTEGER ENTRY WITH AN ASSOCIATED WITH A DOUBLE ARRAY
                                    this defines dimentions of complex no.              this stores the elements.

           //Diagram of Struct\\
            ________________
             |   complex  |
        _____|____________|__________
       |   int N | double* _values   |  //This pointer will be made to point to a one dimentional array.
*      |_________|___________________|
*
            I also define a complx with is equivalent to complex * 
*/


struct complex
{
    long int N;
    double* _values;
};

typedef struct complex* complx;
typedef struct complex complex;

#endif