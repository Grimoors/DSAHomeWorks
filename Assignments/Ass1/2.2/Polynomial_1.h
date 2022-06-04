#ifndef __POLYNOMIAL_1
#define __POLYNOMIAL_1

#include "PolyElem_1.h"

Poly InitPoly();

void AddTerm(Poly P,unsigned int expo,double coeff);


void AddPolynomials(const Poly A,const Poly B, Poly C); 
void SubtractPolynomials(const Poly A,const Poly B, const Poly C);
void DeleteTermByExponent(Poly P,unsigned int expo);
Poly GetMiddle(Poly P);
void DeleteAllTerms(Poly P);
void DeletePoly(Poly* P);
void PrintPoly(Poly P);
Poly GetQuartile(Poly P, int x);

#endif