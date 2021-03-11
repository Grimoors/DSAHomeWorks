#include "Polynomial_1.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Poly InitPoly()
{
    PtrToTerm P = (PtrToTerm)malloc(sizeof(PolyTerm));
    assert(P != NULL);

    P->coeff = -1;
    P->Next = NULL;

    return P;
}

void AddTerm(Poly P, unsigned int expo, double coeff)
{

    PtrToTerm T;

    while (P->Next && P->Next->expo > expo)
    {
        //T = P->Next;
        P = P->Next;
    }
    if (P->Next == NULL || P->Next->expo < expo)
    {
        T = InitPoly();
        T->expo = expo;
        T->coeff = coeff;
        T->Next = P->Next;
        P->Next = T;
    }
    else
    {
        P->Next->coeff = coeff;
    }
}

void AddPolynomials(Poly A, Poly B, Poly C)
{ /*
  *  //Since the Polynomials are stored in Ascending order, we can write a code for this.
  *  // we will Take an empty Initialised poly C, and will add on elements in descending order.
  *  If some element is missing in one, present in other, we will add the one present in C.
  *  If some element is present in none, shall be skipped.
  * 
  * 
  * */

    // A = A->Next;
    // B = B->Next;
   
         printf("\nTest Print 1\n");


    unsigned long int exponent = 0;
    double coefficient = 0;

    int FlagA = 0, FlagB = 0;

    while (A->Next != NULL || B->Next != NULL)
    {
        //Exponent taken with pref to higher one in A & B.
        
        /*
        // if (A->expo >= B->expo && A != NULL)
        // {
        //     exponent = A->expo;
        // }
        // else
        // {
        //     if (B != NULL)
        //         exponent = B->expo;
        // }
        */


       
         printf("\nTest Print 2\n");
       int FlagNullChk=0;
        if(A->Next==NULL)
        {
            FlagNullChk=1;
             exponent=B->Next->expo;
             printf("The coefficient of B = %lf\n",B->Next->coeff);
        }
        if(B->Next==NULL)
        {
            FlagNullChk=1;
            exponent=A->Next->expo;
            printf("The coefficient of A = %lf\n",A->Next->coeff);
        }

        
         printf("\nTest Print 2a. Flag Null check = %d \n",FlagNullChk);
        if(FlagNullChk==0)
        {
           if(A->Next->expo>=B->Next->expo)
           {
               exponent=A->Next->expo;
           }
           else if(B->Next->expo>A->Next->expo)
           {
               exponent=B->Next->expo;
           }
           printf("\nTest Print 3j\n");
        }

        printf("The exponeent = %lu", exponent);
        

        FlagA = 0, FlagB = 0;
        //Coefficient is added according to presence;

        if (A->Next!=NULL && A->Next->expo == exponent)
        {
            FlagA = 1;
            coefficient+=A->Next->coeff;
            printf("\nTest Print 4\n");
        }
        if (B->Next!=NULL && B->Next->expo == exponent)
        {
            /* code */
            FlagB = 1;
            coefficient+=B->Next->coeff;
            printf("\nTest Print 5\n");
        }

        // coefficient = (FlagA * A->coeff) + (FlagB * B->coeff);

        AddTerm(C, exponent, coefficient);

        printf("To C, a term was added \n");
        printf ("Polynomial C == \n");
        PrintPoly(C);
        printf("\nTest Print 6\n");
        //Next term in both is cycled according to presence
        if (FlagA == 1)
        {
            A = A->Next;
            printf("\nTest Print 7\n");
        }
        if (FlagB == 1)
        {
            B = B->Next;
            printf("\nTest Print 8\n");
        }
    }
}
void SubtractPolynomials( Poly A,  Poly B,  Poly C)
{ /*
  *  //Since the Polynomials are stored in Ascending order, we can write a code for this.
  *  // we will Take an empty Initialised poly C, and will add on elements in ascending order.
  *  If some element is missing in one, present in other, we will subtract the one present in C.
  *  If some element is present in none, shall be skipped.
  * */

    A = A->Next;
    B = B->Next;

    unsigned long int exponent = 0;
    double coefficient = 0;

    int FlagA = 0, FlagB = 0;

    while (A != NULL || B != NULL)
    {
        //Exponent taken with pref to higher one in A & B.
        if (A->expo >= B->expo && A != NULL)
        {
            exponent = A->expo;
        }
        else
        {
            if (C != NULL || B != NULL)
                exponent = B->expo;
        }

        FlagA = 0, FlagB = 0;
        //Coefficient is added according to presence;

        if (A->expo >= exponent)
        {
            FlagA = 1;
        }
        if (B->expo >= exponent)
        {
            /* code */
            FlagB = 1;
        }
        coefficient = (FlagA * A->coeff) + (FlagB * B->coeff);

        AddTerm(C, exponent, coefficient);

        //Next term in both is cycled according to presence
        if (FlagA == 1)
        {
            A = A->Next;
        }
        if (FlagB == 1)
        {
            B = B->Next;
        }
    }
}

void DeleteTermByExponent(Poly P, unsigned int expo)
{
    PtrToTerm Prev = P;

    while (P->Next && P->Next->expo < expo)
    {
        Prev = P->Next;
        P = P->Next;
    }

    if (P->Next == NULL || P->Next->expo > expo)
    {
        printf("No polynomial term with exponent %d to delete, Nothing was done successfully\n", expo);
    }
    else
    {
        Prev = P->Next;
        P->Next = P->Next->Next;
        free(Prev);
    }
}

Poly GetMiddle(Poly P)
{
    PtrToTerm Output = NULL;

    return Output;
}
void DeleteAllTerms(Poly P)
{
}
void DeletePoly(Poly *P)
{
}
void PrintPoly(Poly P)
{
    P = P->Next;
    printf("\nThe Polynomial is printed as follows\n");
    while (P != NULL)
    {
        if(P->coeff!=0)
        printf("(%0.2lfx^%lu)+", P->coeff, P->expo);
        P = P->Next;
    }
    printf(" 0\n");
}
Poly GetQuartile(Poly P, int x)
{
    PtrToTerm Output = NULL;

    return Output;
}
