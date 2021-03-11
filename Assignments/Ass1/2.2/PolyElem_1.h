#ifndef __POLYELEM
#define __POLYELEM

typedef struct PolyTerm PolyTerm;
typedef struct PolyTerm* PtrToTerm;

typedef struct PolyTerm* Poly;

struct PolyTerm {
    unsigned long int expo;
    double coeff;
    PtrToTerm Next;
};

#endif