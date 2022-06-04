#ifndef __POLYELEM
#define __POLYELEM

typedef struct PolyTerm* Poly;

struct PolyTerm
{
    unsigned int expo;
    double coeff;
    struct  PolyTerm* Next;


};
#endif