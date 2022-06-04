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
int totalDepth(Node *Tester, int StartDepth);
Node *randomBST(int N);
void avgDepth();

//Problem 6
void inRange(Node *root, int k1, int k2);

#endif
#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>

Node* test_init_node(int data);

Node* test_bst_insert(Node* root, int data);

Node* test_findInBST(Node* root, int data);

Node* test_create_binarySearchTree();

Node* test_findInBT(Node* root, int data);

Node* test_bt_insert(Node* root, int data);

Node* test_create_binaryTree();

Node* test_bt_insertV(Node* root, int data, int l);

Node* test_create_binaryTreeV();

void test_bstsort();

void test_finddepth();

void test_height();

void test_isbst();

void test_inRange();

#endif


int main(){
    // test_bstsort();

    // test_finddepth();

    // test_height();

    test_isbst();

    // test_inRange();

    return 0;
}

//Practice Code start
Node *makeNode(int data) //Node *rootOfNew, Node *parentOfNew)
{
    //  printf("entered makenode\n");
    Node *new = (Node *)malloc(sizeof(Node));
    // new->root = rootOfNew;
    // new->parent = parentOfNew;
    new->left = NULL;
    new->right = NULL;
    new->data = data;
    //new->depth = rootOfNew->depth + 1;
    //rootOfNew->height++;
    // printf("exited makenode\n");
    return new;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return makeNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
    //       printf("entered insert\n");
    //     if (curr == NULL)
    //     {
    //         return makeNode(data);
    //     }
    //     else
    //     {
    //         if (data < curr->data)
    //         {
    //             curr->left = insert(curr->left, data);
    //         }
    //         else
    //         {
    //             curr->right = insert(curr->right, data);
    //         }
    //     }

    //   printf("exit insert\n");
    //     return curr;
    //      //printf("exit insert\n");
}

void print(Node *curr)
{
    printf("%d", curr->data);
}
void inorderAscending(Node *curr)
{
    inorderAscending(curr->left);
    print(curr);
    inorderAscending(curr->right);
}
void preorderAscending(Node *curr)
{
    print(curr);
    preorderAscending(curr->left);
    preorderAscending(curr->right);
}
void postorderAscending(Node *curr)
{
    postorderAscending(curr->left);
    postorderAscending(curr->right);
    print(curr);
}
//practice code end

//***************************************************************************************//
//***************************************************************************************//
//***************************************************************************************//
//***************************************************************************************//
//***************************************************************************************//
//***************************************************************************************//

//Problem 1
void bstsort(Node *T)
{
    if (T == NULL)
        return;
    //if (T->left != NULL)
    bstsort(T->left);

    printf("%d ", T->data);

    //if (T->right != NULL)
    bstsort(T->right);
}

//Problem 2

// //For Binary Search Tree

int finddepth(Node *T, Node *P)
{
    if ((T->data > P->data) && (T->left != NULL))
    {
        int k = finddepth(T->left, P);
        if (k != -1)
        {
            return k + 1;
        }
    }

    else
    {
        if (T->data < P->data && T->right != NULL)
        {
            int k = finddepth(T->right, P);
            if (k != -1)
            {
                return k + 1;
            }
        }
        else
        {
            if (T->data == P->data)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
    }
}

//For General Binary trees - Hug the left wall until leaf reached, then go up and right method

// int finddepth(Node *T, Node *P)
// {
//     if (T->data = P->data)
//     {
//         return 0;
//     }
//     else
//     {
//         if (T->left != NULL)
//         {
//             int l = finddepth(T->left, P);
//             if (l != -1)
//             {
//                 return l + 1;
//             }
//         }
//         else{}
//         if (T->right != NULL)
//         {
//             int r = finddepth(T->right, P);
//             if (r != -1)
//             {
//                 return r + 1;
//             }
//         }
//         else{}
//         return -1;
//     }
// }

//Problem 3

int height(Node *T)
{
    int l = 0, r = 0;
    if (T->left == NULL && T->right == NULL)
    {
        return 0;
    }
    else
    {
        /* code */
    }

    if (T->left != NULL) //finds height of left child if exists
    {
        l = height(T->left);
    }
    if (T->right != NULL) //finds height of right child if exists
    {
        r = height(T->right);
    }
    if (l > r) // returns height of tallest child +1;
    {
        return l + 1;
    }
    else
    {
        return r + 1;
    }
}

//Problem 4

int isbst(Node *T)
{
    //Checks if left subtree is a bst
    int flagl = 0;
    if (T->left != NULL)
    {
        flagl = isbst(T->left);
    }
    else
    {
        flagl = 1;
    }
    //checks if right subtree is a bst
    int flagr = 0;
    if (T->right != NULL)
    {
        flagr = isbst(T->right);
    }
    else
    {
        flagr = 1;
    }
    //checks if current node is a bst
    int lchk = 0, rchk = 0, flagc = 0;
    if (T->left != NULL)
    {
        if (T->data > T->left->data)
        {
            lchk = 1;
        }
        else
        {
            lchk = 0;
        }
    }
    else
    {
        lchk = 1;
    }
    if (T->right != NULL)
    {
        if (T->data < T->right->data)
        {
            rchk = 1;
        }
        else
        {
            rchk = 0;
        }
    }
    else
    {
        rchk = 1;
    }
    if (rchk == 1 && lchk == 1)
    {
        flagc = 1;
    }

    if (flagc == 1 && flagl == 1 && flagr == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Problem 5
int totalDepth(Node *Tester, int StartDepth)
{
    //printf("entered totalDepth\n");
    int tempL = 0, tempR = 0;
    if (Tester->left != NULL)
    {
        tempL = totalDepth(Tester->left, StartDepth + 1);
    }
    if (Tester->right != NULL)
    {
        tempR = totalDepth(Tester->right, StartDepth + 1);
    }
    //printf("exiting totalDepth\n");
    return (tempL + tempR + StartDepth + 1);
}
Node *randomBST(int N)
{

    Node *output = NULL;
    int arr[N];
    int i, j;

    for (i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    for (i = 0; i < N; i++)
    {
        j = rand() % N;
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }

    for (i = 0; i < N; i++)
    {
        output = insert(output, arr[i]);//
        //printf("%d ", arr[i]);
    }
    //printf("Printing sorted array");
    //bstsort(output);
    //printf("Output array generated and exiting RandomBST\n");

    return output;

    // printf("entered randomBST\n");
    // Node *output = NULL;
    // int *memoizationMatrix;
    // memoizationMatrix = (int *)malloc(sizeof(int) * N);
    // printf("defined variables\n");
    // for (int i = 0; i < N; i++)
    // {
    //     memoizationMatrix[i] = 0;
    // }
    // printf("set the memo Matrix to 0\n");
    // srand(time(0));
    // int randFailCount = 0;
    // int quadProber = 1;
    // printf("set the random fuctions\n");
    // for (int i = 0; i < N; i++)
    // {
    //     int k = rand() % N;
    //     if (memoizationMatrix[k] == 1)
    //     {
    //         if (randFailCount < 10)
    //         {
    //             i--;
    //             randFailCount++;
    //             continue;
    //         }
    //         else
    //         {
    //             while (1)
    //             {
    //                 k = (k + (quadProber * quadProber)) % N;
    //                 quadProber++;
    //                 randFailCount++;
    //                 if (memoizationMatrix[k] == 0)
    //                 {
    //                     break;
    //                 }
    //             }
    //             memoizationMatrix[k] = 1;
    //             output = insert(output, k + 1);
    //             printf("Node made \n");
    //         }
    //     }
    //     else
    //     {
    //         memoizationMatrix[k] = 1;
    //         output = insert(output, k + 1);
    //         printf("Node made \n");
    //     }
    /*  Generate random number between 0 to N-1
    Check if it has been generated before
    If it has been retry
    On 10 fails  switch to quadratic probing
    
    Insert generated random number to tree
    
    Traverse tree till a null pointer is found:
    Insert the element.


    At the end of this, return Root node.
        */
    //printf("exiting randomBST\n");
    // return output;
}
void avgDepth()
{
    //printf("entered avgDepth\n");
    int M[4] = {10, 50, 100, 1000};
    int N[4] = {10, 50, 100, 1000};
    double matrixOfAvgDepth[4][4] = {0};
    Node *Tester = NULL;
    //printf("defined the variables\n");
    for (int m = 0; m < 4; m++)
    {

        for (int n = 0; n < 4; n++)
        {
            int d_total = 0;

            for (int i = 0; i < M[m]; i++)
            {
                /*  Calls the upper function   */
                Tester = randomBST(N[n]);
                //printf("Output array generated and entered avg Depth again\n");
                //bstsort(Tester);
                //printf("\n");
                d_total += height(Tester);
            }

            matrixOfAvgDepth[m][n] = (((double)d_total) / ((((double)M[m]))));
        }
    }
    for (int m = 0; m < 4; m++)
    {
        for (int n = 0; n < 4; n++)
        {
            printf("%lf ", matrixOfAvgDepth[m][n]);
        }
        printf("\n");
    }
    //printf("exited avgDepth\n");
}

//Problem 6
void inRange(Node *root, int k1, int k2)
{
    //Deals with left subtree
    if (root->left != NULL)
    {
        inRange(root->left, k1, k2);
    }

    //Deals with current node
    if (root->data >= k1 && root->data <= k2)
    {
        print(root);
        printf(" ");
    }

    //Deals with right subtree
    if (root->right != NULL)
    {
        inRange(root->right, k1, k2);
    }
}

int main(void)
{
    // Node *root = NULL;
    // *root = malloc(sizeof(Node));
    // root->root = root;
    // root->depth = 0;
    // root->parent = NULL;
    // root->count = 1;
    // root->data = 0;
    // root->height = 0;
    // root->left = NULL;
    // root->right = NULL;
    // root = insert(root, 7);

    Node *Test1 = NULL;
    Test1 = insert(Test1, 1);
    Test1 = insert(Test1, 2);
    Test1 = insert(Test1, 3);
    Test1 = insert(Test1, 4);
    Test1 = insert(Test1, 5);
    Test1 = insert(Test1, 6);

    inRange(Test1,2,4);
    // Test1=test_bst_insert(Test1, -23);
    // Test1=test_bst_insert(Test1, -2);
    // Test1=test_bst_insert(Test1, -22);
    // Test1=test_bst_insert(Test1, 23);

    // printf("\n%d\n", isbst(Test1));

    // Node *FindThis = test_findInBST(Test1, 5);

    // printf("\n%d\n", finddepth(Test1, FindThis));

    // printf("\n%d\n", height(FindThis));

    // //test_finddepth(Test1, FindThis);
    // Node *TestBST1 = randomBST(10);

    // avgDepth();
}

Node* test_init_node(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* test_bst_insert(Node* root, int data){
    if(root == NULL) return test_init_node(data);
    if(data < root->data) root->left = test_bst_insert(root->left, data);
    else root->right = test_bst_insert(root->right, data);
    return root;
}

Node* test_findInBST(Node* root, int data){
    if(root == NULL) return NULL;
    if(data == root->data) return root;
    if(data < root->data) return test_findInBST(root->left, data);
    return test_findInBST(root->right, data);
}

Node* test_create_binarySearchTree(){
    Node* root = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 0, data; i < n; i++){
        scanf("%d", &data);
        root = test_bst_insert(root, data);
    }
    return root;
}

Node* test_findInBT(Node* root, int data){
    if(root == NULL) return NULL;
    if(data == root->data) return root;
    Node* p = test_findInBT(root->left, data);
    if(p == NULL){
        p = test_findInBT(root->right, data);
    }
    return p;
}

Node* test_bt_insert(Node* root, int data){
    if(root == NULL) return test_init_node(data);
    if(root->data == data) return root;
    if(root->left == NULL){
        root->left = test_init_node(data);
        return root->left;
    }
    root->right = test_init_node(data);
    return root->right;
}

Node* test_create_binaryTree(){
    int n;
    scanf("%d", &n);
    Node* pointers[n + 1];
    for(int i = 1; i <= n; i++){
        pointers[i] = NULL;
    }
    pointers[1] = test_bt_insert(pointers[1], 1);
    for(int i = 0, u, v; i < n - 1; i++){
        scanf("%d%d", &u, &v);
        pointers[u] = test_bt_insert(pointers[u], u);
        pointers[v] = test_bt_insert(pointers[u], v);
    }
    return pointers[1];
}

Node* test_bt_insertV(Node* root, int data, int l){
    if(root == NULL) return test_init_node(data);
    if(root->data == data) return root;
    if(!l){
        root->left = test_init_node(data);
        return root->left;
    }
    root->right = test_init_node(data);
    return root->right;
}

Node* test_create_binaryTreeV(){
    int n;
    scanf("%d", &n);
    int data[n + 1];
    Node* pointers[n + 1];
    for(int i = 1; i <= n; i++){
        scanf("%d", data + i);
        pointers[i] = NULL;
    }
    pointers[1] = test_bt_insertV(pointers[1], data[1], 0);
    for(int i = 0, u, v, l; i < n - 1; i++){
        scanf("%d%d%d", &u, &v, &l);
        pointers[u] = test_bt_insertV(pointers[u], data[u], 0);
        pointers[v] = test_bt_insertV(pointers[u], data[v], l);
    }
    return pointers[1];
}

void test_bstsort(){
    Node* root = test_create_binarySearchTree();
    bstsort(root);
}

void test_finddepth(){
    Node* root = test_create_binaryTree();
    int data;
    scanf("%d", &data);
    Node* p = test_findInBT(root, data);
    finddepth(root, p);
}

void test_height(){
    Node* root = test_create_binaryTree();
    height(root);
}

void test_isbst(){
    Node* root = test_create_binaryTreeV();
    isbst(root);
}

void test_inRange(){
    Node* root = test_create_binarySearchTree();
    int k1, k2;
    scanf("%d%d", &k1, &k2);
    inRange(root, k1, k2);
}