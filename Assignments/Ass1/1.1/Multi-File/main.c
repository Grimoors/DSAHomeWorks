/*
*
*  HERE THE THING IS CALLED.
*
*
*/

#ifndef __Main_Func_Complex_Numbers__
#define __Main_Func_Complex_Numbers__

#include <stdio.h>
#include "complex.h"


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
    {
        complex a; _initializeComplexNumber(N, &a); _inputComplexNumber(&a);
        complex b; _initializeComplexNumber(N, &b); _inputComplexNumber(&b);
        complex c; _initializeComplexNumber(N, &c);
        _addComplexNumber(&a, &b, &c);
        _printComplexNumber(&c);
        _freeComplexNumber(&a);
        _freeComplexNumber(&b);
        _freeComplexNumber(&c);
        break;
    }

    case 'S':
    case 's':
    {
        complex a; _initializeComplexNumber(N, &a); _inputComplexNumber(&a);
        complex b; _initializeComplexNumber(N, &b); _inputComplexNumber(&b);
        complex c; _initializeComplexNumber(N, &c);
        _subtractComplexNumber(&a, &b, &c);
        _printComplexNumber(&c);
        _freeComplexNumber(&a);
        _freeComplexNumber(&b);
        _freeComplexNumber(&c);
        break;
    }

    case 'M':
    case 'm':
    {
        complex a; _initializeComplexNumber(N, &a); _inputComplexNumber(&a);
        //complex b; _initializeComplexNumber(N, &b); _inputComplexNumber(&b);
        complex c; _initializeComplexNumber(N, &c);
        double modulus = _modulusOfComplexNumber(&a);
        printf("\nThe Modulus of the complex number entered is = %ld \n ",modulus);
        _freeComplexNumber(&a);
        //_freeComplexNumber(&b);
        _freeComplexNumber(&c);
        break;
    }

    case 'D':
    case 'd':
    {
        complex a; _initializeComplexNumber(N, &a); _inputComplexNumber(&a);
        complex b; _initializeComplexNumber(N, &b); _inputComplexNumber(&b);
        complex c; _initializeComplexNumber(N, &c);
        double dot_prod = _dotProdOfComplexNumber(&a, &b);
        printf("\nThe Dot Product of the complex number entered is = %ld \n",dot_prod);
        _freeComplexNumber(&a);
        _freeComplexNumber(&b);
        _freeComplexNumber(&c);
        break;
    }
    }
    return 0;
}

#endif 