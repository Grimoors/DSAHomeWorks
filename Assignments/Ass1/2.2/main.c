#include "Polynomial_1.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct PolyInput PolyInput;
struct PolyInput
{
  /* data */
  Poly A;
  char *Name;
  PolyInput *NextInput;
};

///
int main()
{
    // Poly P = NULL;
    // Poly P2 = NULL;
    // Poly P3=NULL;
    // Poly P4 = NULL;
    Poly A= NULL;
    Poly B=NULL;
    Poly C=NULL;

    A=InitPoly();
    B=InitPoly();
    C=InitPoly();
    // P = InitPoly();
    // P2= InitPoly();
    // P3=InitPoly();
    // P4=InitPoly();

    AddTerm(A,4,5);
    AddTerm(A,3,4);
    AddTerm(A,1,2);
    AddTerm(A,0,7);

    //Poly B: -7.2x3 + 4x2 - 4

    AddTerm(B,3,-7.2);
    AddTerm(B,2,4);
    AddTerm(B,0,-4);

    AddTerm(A,7,-3.2);
  AddTerm (B,6,3);
  PrintPoly (A);
  PrintPoly (B);
  //PrintPoly (P);
  AddPolynomials (A ,B, C);
  PrintPoly (C);

    // AddTerm(P,0,69);
    // AddTerm(P,1,10);
    // // PrintPoly(P);
    // AddTerm(P,2,22);
    // //PrintPoly(P);
    // AddTerm(P,5,13);
    // //PrintPoly(P);
    // AddTerm(P,4,30);
    // //PrintPoly(P);
    // AddTerm(P,6,13);
    // //PrintPoly(P);
    // AddTerm(P,5,23);
    // PrintPoly(P);

    // printf("\nThe Polynomial P has been printed\n");

    // AddTerm(P2,1,10);
    // AddTerm(P2,2,22);
    // //AddTerm(P2,5,13);
    // AddTerm(P2,4,30);
    // AddTerm(P2,6,13);
    // //AddTerm(P2,5,23);
    //   PrintPoly(P2);
    // printf("\nThe Polynomial P2 has been printed\n");

    // AddPolynomials(P,P2,P3);

    //   printf("\nThe Polynomial P3  has beenadded \n");

    // PrintPoly(P3);

    // printf("\nThe Polynomial P3 = P+P2 has been printed\n");

    // SubtractPolynomials(P,P2,P4);

    //       printf("\nThe Polynomial P4  has beenadded \n");
    //       PrintPoly(P4);
    //       DeleteTermByExponent(P4,5);
    //       PrintPoly(P4);

    // printf("\nThe Polynomial P4 = P-P2 has been printed\n");

    // DeleteTerm(P2,2);
    // DeleteTerm(P2,1);

    return 0;
}