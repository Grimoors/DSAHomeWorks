#ifndef __POLYELEM
#define __POLYELEM

typedef PolyTerm Poly;

struct PolyTerm
{
    unsigned int expo;
    double coeff;
    struct  PolyTerm* Next;


};
#endif