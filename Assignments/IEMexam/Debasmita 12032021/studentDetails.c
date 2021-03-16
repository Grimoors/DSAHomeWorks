#include <stdlib.h>
#include<string.h>
#include<strings.h>
#include<stdio.h>
#include<malloc.h>

typedef struct Student Student;
typedef Student *PtrToStudent;

struct Student
{
    char *name;
    char *rollNo;
    char *sec;
};
void takeInput(PtrToStudent S, long int i)
{
    printf("for the %ldth student ->\n", i);
    char name[10000], rollNo[10000], sec[10000];
    printf("Input The name of the student\n");
    fflush(stdin);
    fflush(stdout);
    scanf("%s", name);
    printf("Input The Roll Number of the student:\n");
    fflush(stdin);
    fflush(stdout);
    scanf("%s", rollNo);
    printf("Input the Section of the Student\n");
    fflush(stdin);
    fflush(stdout);
    scanf("%s", sec);
    S->name = (char *)malloc(strlen(name));
    S->rollNo = (char *)malloc(strlen(rollNo));
    S->sec = (char *)malloc(strlen(sec));
    strcpy(S->name,name);
    strcpy(S->rollNo,rollNo);
    strcpy(S->sec,sec);

}

void printDetailsOfStudent(PtrToStudent S,long int i)
{
    printf("for the %ldth student ->\n", i);

    printf("Name=  %s\nRollNo= %s\nSec= %s\n\n",S->name,S->rollNo,S->sec);

}

int main()
{
    printf("Input Number of students\n");

    fflush(stdin);
    fflush(stdout);
    long int N;
    scanf("%ld", N);
    PtrToStudent M = (PtrToStudent)malloc(sizeof(Student) * N);

    for (long int i = 0; i < N; i++)
    {
        takeInput(&M[i], i);
    }

    printf("Input was taken, now printing output");

    for (long int i = 0; i < N; i++)
    {
        printDetailsOfStudent(&M[i],i);
    }

    printf("\n\nOutput was given succesfully, Terminating");
    return 0;
}