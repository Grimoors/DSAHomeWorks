#include "BinaryTree.h"
#include <stdio.h>

SearchTree Insert (SearchTree T, ElementType X)
{
    if(T==NULL)
        T= MakeNode(X);
    else if (IsSmaller(X,T->Element )) // X< T->Element 
        T->Left= Insert (T->Left,X);
    else
        T->Right= Insert(T->Right,X);   //X> T-> Element

    return T;

/*             _____
*             |  T  |
*        _____|_____|_______________
        /           |               \
        |  T->Left  |   T->Right    |
*       \___________|_______________/
*
*                          6
                       ____|_____
*                     |          |
                      2          9
                   ___|___    ___|___
                  |       |  |       |
*/

}

Position Find(SearchTree T, ElementType X)
{
    if(T== NULL)
        return T;
    else if( IsEqual (X,T->Element))
        return T;
    else if(X<T->Element)
        return Find(T->Left,X);
    else
        return Find(T->Right,X);
}

Position Delete(SearchTree T,ElementType X)
{
    //Case 1 - does not exist

    //Case 2 - Exists
    //2a - No subtree
    //2b - Yes subtree
    if (IsSmaller(X,T->Element))//X<T->ELement
        T->Left=Delete(T->Left, X);
    else(IsGreater(X,T->Element))  //X>T->ELemnet
        T->Right=Delete(T->Right,X);
    else//Found the node we wanna delete
    {
        if(T->Left == NULL || T->Right == NULL)
        {
            TmpNode = T;
            if(T->Right==Null)
                T=T->Left;
            else if(T->Left==NULL)
                T=T->Right;
            DeleteNode(TmpNode);
        }
        else // node has 2 children (Subtrees)
        {
            
        }

        return T;
    }
}
