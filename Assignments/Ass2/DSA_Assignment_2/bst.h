#ifndef __BST_H__
#define __BST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
int data;
int height;
//int depth;
struct Node* left;
struct Node* right;
//int count;
//struct Node* root;
//struct Node* parent;
    //struct Node* leftDown;
    //struct Node* rightDown;
};


//Practice Code start
Node *makeNode(int data); //Node *rootOfNew, Node *parentOfNew)
Node *insert(Node *curr, int data);
void print(Node *curr);
void inorderAscending(Node *curr);
void preorderAscending(Node *curr);
void postorderAscending(Node *curr);
//practice code end


//Problem 1
void bstsort(Node *T);

//Problem 2
int finddepth(Node *T, Node *P);

//Problem 3
int height(Node *T);

//Problem 4
int isbst(Node *T);

//Problem 5
//int totalDepth(Node *Tester, int StartDepth);
Node *randomBST(int N);
void avgDepth();

//Problem 6
void inRange(Node *root, int k1, int k2);

#endif