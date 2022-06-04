/*
*
*
*   CONTAINS VARIOUS IMPLEMENTATIONS
*
*/

#ifndef __Complex_Number_Library_Functions__
#define __Complex_Number_Library_Functions__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

void _initializeComplexNumber(long int N, complx num)// input size followed by pointer to "empty" complex number.
{
    num->N=N; // Sets dimention
    num->_values=(double*)malloc(sizeof(double)*num->N); //allocates memory for the array.
}


void _inputComplexNumber(complx _ToSet)
{
    puts(" ");
    printf("Please enter N = %ld space seperated integers to input a Complex number of %ld dimentions\n",_ToSet->N,_ToSet->N);
    for(long int i=0;i<_ToSet->N;i++)
    {
        scanf("%lf",&_ToSet->_values[i]);// takes the complex number and inputs values to it.
    }
}

void _addComplexNumber (complx a, complx b, complx c)// such that c = a+b, where + is complex addition. Pointers to a,b,c are inputted to function.
{
    printf ("\n The input to the subtract Function was -> \n");
    puts("a = ");
    for(int i=0;i<a->N;i++)
        {
            printf("%lf ",a->_values[i]);
        }
    puts(" b = ");
    for(int i=0;i<b->N;i++)
        {
            printf("%lf ",b->_values[i]);
        }
    puts(" c= ");
    for(int i=0;i<c->N;i++)
        {
            printf("%lf ",c->_values[i]);
        }
    puts(" ");
    for(long int i=0;i<a->N;i++)
    {
        c->_values[i]=a->_values[i]+b->_values[i];
    }
}

void _subtractComplexNumber (complx a, complx b, complx c) //such that c = a-b, where - is complex subtraction. Pointers to a,b,c are inputted to the function.
{
    printf ("\n The input to the subtract Function was -> \n");
    puts("a =");
    for(int i=0;i<a->N;i++)
        {
            printf("%lf ",a->_values[i]);
        }
    puts(" b = ");
    for(int i=0;i<b->N;i++)
        {
            printf("%lf ",b->_values[i]);
        }
    puts(" c= ");
    for(int i=0;i<c->N;i++)
        {
            printf("%lf ",c->_values[i]);
        }
    puts("");
    for(long int i=0;i<a->N;i++)
    {
        c->_values[i]=a->_values[i]-b->_values[i];
    }
}

double _modulusOfComplexNumber (complx a) // takes input of a pointer to a complex number and returns the modulus value
{

    printf ("\n The input to the Modulus Function was -> \n");
    for(int i=0;i<a->N;i++)
        {
            printf("%lf ",a->_values[i]);
        }
    puts(" ");

    double sum =0.0;
    for(long int i=0;i<(a->N);i++)
    {
        sum=sum + ((a->_values[i])*(a->_values[i]));
    }
    return sqrt(sum);
}

double _dotProdOfComplexNumber (complx a, complx b)// takes input of a pointer to 2 complex numbers and returns the dot product.
{
    printf ("\n The input to the Dot product Function was -> \n");
    for(int i=0;i<a->N;i++)
        {
            printf("%lf ",a->_values[i]);
        }
    puts(" ");
    for(int i=0;i<b->N;i++)
        {
            printf("%lf ",b->_values[i]);
        }
    puts(" ");
    double sum=0;
    for(long int i=0;i<a->N;i++)
    {
        sum+=(a->_values[i] * b->_values[i]);
    }
    return sum;
}

void _printComplexNumber(complx a)
{
    puts(" ");
    puts("The Complex number which is the answer is : ");
    for(long int i=0; i<a->N;i++)
    {
        printf("%lf ",a->_values[i]);
    }
}
void _freeComplexNumber(complx ab)
{
    // for(long int i=a.N-1; i>=0; i--)
    // {
    //     free(a._values[i]);
    // }
    free(ab->_values);
    //free(&(ab->N)); //automatically freed as the program kills this on exit from function stack
    free(ab);
}

#endif