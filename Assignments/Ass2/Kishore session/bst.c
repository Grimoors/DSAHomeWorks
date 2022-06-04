#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef struct node
{
    int key;
    int count;
    struct node* root;
    struct node* parent;
    struct node* leftDown;
    struct node* rightDown;
}node;


node *makenode(int key, node*rootOfNew,node*parentOfNew)
{
    node *new = malloc (sizeof(node));
    new->root=rootOfNew;
    new ->parent=parentOfNew;
    new->leftDown=NULL;
    new->rightDown=NULL;
    new ->key = key;
    return new;
}

node* insert (node* curr, int key)
{
    if(curr==NULL)
    {
        return makenode(key,curr->root,curr->parent);
    }
    if(key< curr->key)
    {
        curr->left = insert(curr->left,key);    
    }
    else
    {
        curr->right = insert(curr->right,key);    
    }
}

void print (node * curr)
{
    printf("%d",curr->key);
}
void  inorderAscending (node * curr)
{
    inorderAscending(curr->leftDown);
    print(curr);
    inorderAscending(curr->rightDown);
}
void  preorderAscending(node* curr)
{
    print(curr);
    preorderAscending(curr->leftDown);
    preorderAscending(curr->rightDown);
}
void postorderAscending(node*curr)
{
    postorderAscending(curr->leftDown);
    postorderAscending(curr->rightDown);
    print (curr);
}



int main(void)
{
    node *root =NULL;
    root = insert(root,7);
}