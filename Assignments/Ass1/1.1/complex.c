#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"
#include "complex_double_elements.h"

complex _initializeComplexNumber(long int N)
{
    complex num;
    num.N=N;
    num._values=(double*)malloc(sizeof(double)*num.N);
    return num;
}


complex _inputComplexNumber(complex _ToSet)
{
    puts(" ");
    printf("Please enter N = %ld space seperated integers to input a Complex number of %ld dimentions\n",_ToSet.N,_ToSet.N);
    for(long int i=0;i<_ToSet.N;i++)
    {
        scanf("%ld",&_ToSet._values[i]);
    }
    return _ToSet;
}

complex _addComplexNumber (complex a, complex b)
{
    complex c;
    c.N=a.N;
    c._values = (double*)malloc(sizeof(double)*c.N);
    for(long int i=0;i<a.N;i++)
    {
        c._values[i]=a._values[i]+b._values[i];
    }
    return c;
}

complex _subtractComplexNumber (complex a, complex b)
{
    complex c;
    c.N=a.N;
    c._values = (double*)malloc(sizeof(double)*c.N);
    for(long int i=0;i<a.N;i++)
    {
        c._values[i]=a._values[i]-b._values[i];
    }
    return c;
}

double _modulusOfComplexNumber (complex a)
{
    double sum =0;
    for(long int i=0;i<a.N;i++)
    {
        sum+=(a._values[i]*a._values[i]);
    }
    return sqrt(sum);
}

double _dotProdOfComplexNumber (complex a, complex b)
{
    double sum=0;
    for(long int i=0;i<a.N;i++)
    {
        sum+=(a._values[i] * b._values[i]);
    }
    return 0;
}

void _printComplexNumber(complex a)
{
    puts(" ");
    puts("The Complex number which is the answer is : ");
    for(long int i=0; i<a.N;i++)
    {
        printf("%d ",a._values[i]);
    }
}
void _freeComplexNumber(complex ab)
{
    // for(long int i=a.N-1; i>=0; i--)
    // {
    //     free(a._values[i]);
    // }
    free(ab._values);
    // free(a.N); //automatically freed as the program kills this on exit from function stack
    // free(a);
}