#include <stdio.h>

typedef int ElementType;
typedef struct AVLnode* AVLTree;
typedef AVLTree Position;
struct AVLnode
{
    /* data */
    ElementType Element;
    AVLTree Left;
    AVLTree Right;
    int Height;
};


int Height(Position P)
{
    if(P==NULL)
        return -1; //Height of a Nonexistent Leaf Node
    else 
        return P->Height;
}
AVLTree Insert(AVLTree T, ElementType X)
{
    if(T==NULL)
    {
        T=MakeNode(X);
    }
    else
    {
        if(X<T->Element)
        {
            T->Left=Insert(T->Left,X);
            //Check if AVL balance property has been violated
            //after insertion into left subtree
            if((Height(T->Left - Height(T->Right))==2))
            {
                //Case 1
                    if(X<T->Left->Element)
                    {
                        T=SingleRotateWithLeft(T);
                    }
                    else
                //Case 3
                    {
                        T=DoubleRotateWithLeft(T);
                    }
            }
        }
        else
        {
            if(X>T->Element)
            {
                T->Right=Insert(T->Right,X);
                //Check of AVL balance property has been violated
                //After insertion into left subtree
                if((Height(T->Left - Height(T->Right))==2))
                {
                    if(X < T->Right->Element)
                    {
                        //Case 4
                        T= DoubleRotateWithRight(T);
                    }
                    else
                    {
                        //Case 2
                        T=SingleRotateWithRight(T);
                    }
                }
                
            }
        }

    }
    //X==T->Element ---> do nothing 
                T->Height= max(Height(T->Left),Height(T->Right))+1;
}

Position SingleRotateWithLeft(Position k2)
{
    Position k1;
    k1= k2->Left;
    k2->Left== k1->Right;
    k1->Right = k2;

    k2->Height=max(Height(k2->Left),Height(k2->Right))+1;
    k1->Height=max(Height(k1->Left),Height(k1->Right))+1;

    return k1;
}
Position SingleRotateWithRight(Position k2)
{
   Position k1=k2->Right;
   k2->Right=k1->Left; 
   k1->Left=k2;

       k2->Height=max(Height(k2->Left),Height(k2->Right))+1;
    k1->Height=max(Height(k1->Left),Height(k1->Right))+1;
    return k1;
}

Position DoubleRotateWithLeft(Position k2)
{
    //Rotate between k3 and k1
    // Position k1=k2->Left;
    // Position k3;

    SingleRotateWithRight(k2->Left);

    //Rotate between K1 and K2
    return SingleRotateWithLeft(k2);
}

Position DoubleRotateWithLeft(Position k2)
{
    //Rotate between k3 and k1
    // Position k1=k2->Left;
    // Position k3;

    SingleRotateWithLeft(k2->Right);

    //Rotate between K1 and K2
    return SingleRotateWithRight(k2);
}