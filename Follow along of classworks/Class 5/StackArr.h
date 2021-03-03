#ifndef __StackArr
#define __StackArr


typedef int ElementType;

struct StackInfo{
    long int MaxNumItems;
    long int TopId;
    ElementType *StackItem;
};
#endif