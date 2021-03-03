#include <stdio.h>
#include "complex_double_elements.h"
#include "complex.h"
#include "complex.c"

int main()
{
    long int N = 0;
    printf("Please input #3 letters followed by a spacebar and an integer entry to proceed. \n");
    char Operation[3] = {'\0', '\0', '\0'};
    scanf("%c%c%c %ld", &Operation[0], &Operation[1], &Operation[2], &N);

    switch (Operation[0])
    {
    case 'A':
    case 'a':
        {complex a = _initializeComplexNumber(N);
        complex b = _initializeComplexNumber(N);
        a=_inputComplexNumber(a);
        b=_inputComplexNumber(b);
         complex c3 = _initializeComplexNumber(N);
       c3 = _addComplexNumber(a, b);
        _printComplexNumber(c3);
        _freeComplexNumber(a);
        _freeComplexNumber(b);
        _freeComplexNumber(c3);
        break;}

    case 'S':
    case 's':
        {complex a = _initializeComplexNumber(N);
        complex b = _initializeComplexNumber(N);
                a=_inputComplexNumber(a);
        b=_inputComplexNumber(b);
        complex c3 = _initializeComplexNumber(N);
        c3 = _subtractComplexNumber(a, b);
        _printComplexNumber(c3);
        _freeComplexNumber(a);
        _freeComplexNumber(b);
        _freeComplexNumber(c3);
        break;}

    case 'M':
    case 'm':
       { complex a = _initializeComplexNumber(N);
                a=_inputComplexNumber(a);
                 complex c3 = _initializeComplexNumber(N);
        complex c3 = _modulusOfComplexNumber(a);
        _printComplexNumber(c3);
        _freeComplexNumber(a);
        _freeComplexNumber(c3);
        break;}

    case 'D':
    case 'd':
        {complex a = _initializeComplexNumber(N);
         a=_inputComplexNumber(a);
         complex b = _initializeComplexNumber(N);
                a=_inputComplexNumber(a);
         complex c3 = _initializeComplexNumber(N);
         c3 = _dotProdOfComplexNumber(a,b);
        _printComplexNumber(c3);
        _freeComplexNumber(a);
           _freeComplexNumber(b);
        _freeComplexNumber(c3);
        break;}
    }
    return 0;
}