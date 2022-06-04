# Instructions
1. Add bst.c and bst.h in this folder
2. All function declarations, structs and header files must be declared in the file bst.h
3. bst.c must have only one header- bst.h
4. main.c has the following 5 functions (corresponding to problem 1, 2, 3, 4 and 6 resp):
test_bstsort();
test_finddepth();
test_height();
test_isbst();
test_inRange();
Uncomment only the function you want to run, while keeping the other functions commented
5. Run the script merge.sh as ```bash merge.sh```. This will generate a file a2.c
6. a2.c is what you need to submit
7. Every function must print the required output 
8. Problem specific instructions:
a. Problem 1: The output has to be in ascending order
b. Problem 5: Evaluation will be manual
c. Problem 6: The elements have to be in sorted ascending order


Problem 1

-- void bstsort(Node*T)  

-> Takes the Pointer to a node of a tree as input
-> Implements an Inorder Traversal to print the 
tree in ascending order. 
-> code is recursive.


        +++ Time Complexity Analysis +++

        Time is O(N) , (Inorder traversal)

        ++++++++++++++++++++++++++++++++


Problem 2

-- int finddepth( Node* T, Node*P)

-> Takes two Pointers to a node of a tree as input.
-> Returns an integer value, the depth of node P 
relative to node T; as output. An output of -1 
signifies that the node P was not a subtree of the 
node T.
-> Postorder Traversal is implemented, in a recursive form.
->two versions are provided, one is for Binary search trees and another is for general Binary Trees(commented out.).


        +++ Time Complexity Analysis +++

        Time is O(N) , (postorder traversal)

        ++++++++++++++++++++++++++++++++


Problem 3

-- int height (Node* T)

-> Takes the Pointer to a node of a tree as input
-> Returns an integer value, the height of the Node T taken as input
, with respect to the deepest 'leaf' of the binary search trees
-> postorder traversal is implemented, recursively.

        +++ Time Complexity Analysis +++

        Time is O(N) , (postorder traversal)

        ++++++++++++++++++++++++++++++++

Problem 4

--int isbst(Node * T)

-> Takes the Pointer to a node of a tree as input
-> Returns an integer value, when 0, the Subtree of T is not a binary search tree, and 1 if the subtree of T is a binary search tree.
-> postorder traversal is implemented, recursively.


        +++ Time Complexity Analysis +++

        Time is O(N) , (postorder traversal)

        ++++++++++++++++++++++++++++++++

Problem 5 




![ViveksImage](.\Figure_1.png)





OBSERVATIONS :-__________________-

            N[0]=10    N[1]=50  N[2]=100  N[3]=1000
M[0]=10   =>  4.000000 9.900000 12.300000 22.200000
M[1]=50   =>  4.600000 9.680000 12.280000 21.280000
M[2]=100  =>  4.630000 9.980000 12.380000 21.240000
M[3]=1000 =>  4.531000 9.734000 12.268000 21.080000

              -__________________-


 
-- Node* randomBST(int N)

-> Generated a matrix of size N, arr is randomized.
-> The array is traversed linearly and the insert function is called to insert the randomised array to the outpus
-> input taken is the size of the array needed, and the return type is a pointer to a node with a subtree of N things. 


        +++ Time Complexity Analysis +++

        first For is O(n)
        second for is O(n)

        third for is O(n), but each iteration calles insert, but that is a log(N) operation.

        hence it is O(n*log(n))

        overall complexity is O(N*log(N))

        ++++++++++++++++++++++++++++++++

-- avgDepth()

-> Does not need input
-> Has hardcoded Matrices for M and N.
-> Calls randomBST and height
-> prints a 4 x 4 matrix for the avg depth values, with M[m] corresponding to the rows and N[n] corresponding to the columns


        +++ Time Complexity Analysis +++

        first loop is 4 iterations
            second loop is 4 iterations
                third loop is O(M[m]), worst case is 1000.
                    This is calling random bst and height.
                    They are O(N*log(N)) and O(N)
                
        second loop is 4
            third loop is 4

        Hence overall is O(M*(N*log(N)+N))

        ++++++++++++++++++++++++++++++++


Problem 6

-- void inRange(Node *root, int k1, int k2)


-> No return value, Takes in the Pointer to a node of a tree as input
-> Prints the values of the tree which are in the range k1<=x<=k2 in a space seperated fashion.
-> inorder traversal is done, code is recursive



        +++ Time Complexity Analysis +++

        Time is O(N) , (inorder traversal)

        ++++++++++++++++++++++++++++++++

