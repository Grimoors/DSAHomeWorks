#include "Polynomial.h"
#include <stdlib.h>
#include <limits.h>
Poly InitPoly()
{
    Poly P = (Poly)malloc(sizeof(Pterm));
    assert(P!=NULL);

    P-> expo= INT_MAX;
    P-> Next = NULL;
    return P;
}


void AddTerm