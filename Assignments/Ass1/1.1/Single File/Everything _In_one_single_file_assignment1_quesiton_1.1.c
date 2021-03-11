#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>

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
    double *_values;
};

typedef struct complex* complx;
typedef struct complex complex;

//contents of complex.h
/*
*
*           THESE ARE BASICALLY HEADERS
*
*
*/

void _initializeComplexNumber(long int , complx );// input size followed by pointer to "empty" complex number.
void _inputComplexNumber(complx );
/* This is unnecessary *///complex _resizeComplexNumber(complex a , long int N);
void _addComplexNumber (complx , complx , complx );// such that c = a+b, where + is complex addition. Pointers to a,b,c are inputted to function.
void _subtractComplexNumber (complx , complx , complx ); //such that c = a-b, where - is complex subtraction. Pointers to a,b,c are inputted to the function.
double _modulusOfComplexNumber(complx );
double _dotProdOfComplexNumber(complx , complx );


void _printComplexNumber(complx );
void _freeComplexNumber(complx );

// contents of complex.c
/*
*
*
*   CONTAINS VARIOUS IMPLEMENTATIONS
*
*/

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

// contents of main.c
/*
*
*  HERE THE THING IS CALLED.
*
*
*/

int main()
{
    long int N = 0;
    printf("Please input #3 letters followed by a spacebar and an integer entry to proceed. \n");
    char Operation[3] = {'\0', '\0', '\0'};
    scanf("%c%c%c %ld", &Operation[0], &Operation[1], &Operation[2], &N);
    //scanf("%3s %ld", Operation, &N);
    //scanf("%[A-Z] %ld", Operation, &N);//We are defining the Valid characters to input
            //Whatever is in the square brakets is called "acceptable input"!!
            //Takes care of things automatically.
    //scanf("%[a-zA-Z] %ld", Operation, &N); {//CodeVault - C}
    //scanf("%[^0-9] %ld", Operation, &N);

    switch (Operation[0])
    {
    case 'A':
    case 'a':
    {
        complex a; _initializeComplexNumber(N, &a); _inputComplexNumber(&a);
        printf ("\n Input was read as -> \n");
        for(int i=0;i<a.N;i++)
        {
            printf("%lf ",a._values[i]);
        }
        puts(" ");
        complex b; _initializeComplexNumber(N, &b); _inputComplexNumber(&b);
        printf ("\n Input was read as -> \n");
        for(int i=0;i<a.N;i++)
        {
            printf("%lf ",a._values[i]);
        }
        puts(" ");
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
        printf ("\n Input was read as -> \n");
        for(int i=0;i<a.N;i++)
        {
            printf("%lf ",a._values[i]);
        }
        puts(" ");
        complex b; _initializeComplexNumber(N, &b); _inputComplexNumber(&b);
        printf ("\n Input was read as -> \n");
        for(int i=0;i<a.N;i++)
        {
            printf("%lf ",a._values[i]);
        }
        puts(" ");
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
        printf ("\n Input was read as -> \n");
        for(int i=0;i<a.N;i++)
        {
            printf("%lf ",a._values[i]);
        }
        puts(" ");
        //complex b; _initializeComplexNumber(N, &b); _inputComplexNumber(&b);
        complex c; _initializeComplexNumber(N, &c);
        double modulus = _modulusOfComplexNumber(&a);
        printf("\nThe Modulus of the complex number entered is = %lf \n ",modulus);
        _freeComplexNumber(&a);
        //_freeComplexNumber(&b);
        _freeComplexNumber(&c);
        break;
    }

    case 'D':
    case 'd':
    {
        complex a; _initializeComplexNumber(N, &a); _inputComplexNumber(&a);
        printf ("\n Input was read as -> \n");
        for(int i=0;i<a.N;i++)
        {
            printf("%lf ",a._values[i]);
        }
        puts(" ");
        complex b; _initializeComplexNumber(N, &b); _inputComplexNumber(&b);
        printf ("\n Input was read as -> \n");
        for(int i=0;i<a.N;i++)
        {
            printf("%lf ",a._values[i]);
        }
        puts(" ");
        complex c; _initializeComplexNumber(N, &c);
        double dot_prod = _dotProdOfComplexNumber(&a, &b);
        printf("\nThe Dot Product of the complex number entered is = %lf \n",dot_prod);
        _freeComplexNumber(&a);
        _freeComplexNumber(&b);
        _freeComplexNumber(&c);
        break;
    }
    }
    return 0;
}