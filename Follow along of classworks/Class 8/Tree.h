#ifndef __TREE_H
#define __TREE_H

typedef double ElementType;
typedef struct  Treenode* PtrToNode;

struct TreeNode
{
    /* data */
    ElementType dataInTreeNode;
    PtrToNode firstChild;
    PtrToNode nextSibling;
    PtrToNode parentNode;
};

#endif