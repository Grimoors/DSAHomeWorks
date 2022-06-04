#ifndef __TREE_IMPLEMENTATION_H
#define __TREE_IMPLEMENTATION_H

#include "Tree.h"
#include <stdlib.h>

// man dirent
void ListDir(FileOrDir D, int NumSpaces)
{
    if(IsValidEntry(D))
    {
        PrintName(D,NumSpaces);
        if(IsDir(D))
        {
            //#for each child
            DirC=D->FirstChild;
            while(C!=NULL)
            {
                totalsize += FindDirectorySize(C);
                ListDir(C,NumSpaces+1);
                C=C->NextSibling;
            }
        }
    }
}
void FindDirectorySize(FileOrDir D)
{
    size_t totalSize=0;
    Dir C;
    if(IsValidEntry(D))
    {
        
        if(IsDir(D))
        {
            //#for each child
            C=D->FirstChild;
            while(C!=NULL)
            {
                totalsize += FindDirectorySize(C);
                C=C->NextSibling;
            }
        }
        totalSize+=FindFileSize(D)l
    }
}

void ListDirectory(FileOrDir D)
{
    ListDir(D,0);
}

void LevelOrderTraversalPrint(PtrToNode D)
{
    PtrToNode copy = D;
    
    Queue Q;
    AddToQueue(Q,D);

    while(!Empty(Q))
    {
        E = Deque(Q);
        PrintNode(E);
        AddToQueue(E->FirstChild);
        while(E->NextSibling != NULL)
        {AddToQueue (E->NextSibling);
        E=E->NextSibling;}
        
    }
}



#endif