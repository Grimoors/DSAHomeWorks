#include "Polynomial_1.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct PolyInput PolyInput;
struct PolyInput
{
  /* data */
  Poly A;
  char *Name;
  PolyInput *NextInput;
};

int main()
{
  PolyInput *Inputs;
  Inputs = (PolyInput *)malloc(sizeof(PolyInput));

  char _Command[30];
  printf("\n Input your Command :- (exit kills the loop)\n");
  while (1)
  {
  _StartLabel:
    fflush(stdout);
    fflush(stdin);
    scanf("%s", _Command);

    if (strcmp("exit", _Command) == 0)
    {
      return 0;
    }

    else
    {
      if (strcmp("AddPolynomials", _Command) == 0)
      {
        char name1[10];
        char name2[10];
        char name3[10];
        scanf("%[A-Z] %[A-Z] &[A-Z] ", name1, name2, name3);
        int AlreadyExists1 = 0;
        int AlreadyExists2 = 0;
        int AlreadyExists3 = 0;

        PolyInput* ForA,ForB,ForC;
        while (Inputs->NextInput != NULL)
        {
          if (strcmp(name1, Inputs->NextInput->Name) == 0)
          {
            AlreadyExists1 = 1;
            ForA=Inputs->NextInput;
          }
          if (strcmp(name2, Inputs->NextInput->Name) == 0)
          {
            AlreadyExists2 = 1;
            ForB =Inputs->NextInput;
          }
          if (strcmp(name3, Inputs->NextInput->Name) == 0)
          {
            AlreadyExists3 = 1;
       
          }
          Inputs=Inputs->NextInput;
        }
        if (AlreadyExists)
        {
          AddTerm(Inputs->NextInput->A, x, y);
        }
        else
        {
          Inputs->NextInput = (PolyInput *)malloc(sizeof(PolyInput));
          Inputs->NextInput->Name = (char *)malloc(sizeof(char) * 10);
          Inputs->NextInput->Name = name;
          Inputs->NextInput->A = InitPoly();
          AddTerm(Inputs->NextInput->A, x, y);
        }

        printf("\n Input your Command :- (exit kills the loop)\n");
        goto _StartLabel;
      }
      else
      {
        if (strcmp("SubtractPolynomials", _Command) == 0)
        {

          printf("\n Input your Command :- (exit kills the loop)\n");
          goto _StartLabel;
        }
        else
        {
          if (strcmp("DeleteTermByExponent", _Command) == 0)
          {
            printf("\n Input your Command :- (exit kills the loop)\n");
            goto _StartLabel;
          }
          else
          {
            if (strcmp("GetMiddle", _Command) == 0)
            {

              printf("\n Input your Command :- (exit kills the loop)\n");
              goto _StartLabel;
            }
            else
            {
              if (strcmp("DeleteAllTerms", _Command) == 0)
              {
                printf("\n Input your Command :- (exit kills the loop)\n");
                goto _StartLabel;
              }
              else

              {
                if (strcmp("DeletePoly", _Command) == 0)
                {
                  printf("\n Input your Command :- (exit kills the loop)\n");
                  goto _StartLabel;
                }
                else
                {
                  if (strcmp("PrintPoly", _Command) == 0)
                  {
                    char name[10];
                    scanf("%[A-Z]", name);
                    int AlreadyExists = 0;
                    while (Inputs->NextInput != NULL)
                    {
                      if (strcmp(name, Inputs->NextInput->Name) == 0)
                      {
                        AlreadyExists = 1;
                        break;
                      }
                      Inputs=Inputs->NextInput;
                    }
                    if (AlreadyExists)
                    {
                      PrintPoly(Inputs->NextInput->A);
                    }
                    else
                    {
                      printf("\nPolynomial Does not exist\n");
                    }
                    printf("\n Input your Command :- (exit kills the loop)\n");
                    goto _StartLabel;
                  }
                  else

                  {
                    if (strcmp("AddTerm", _Command) == 0)
                    {
                      char name[10];
                      double y;
                      unsigned long int x;
                      scanf("%[A-Z] %ul %lf", name, x, y);
                      int AlreadyExists = 0;
                      while (Inputs->NextInput != NULL)
                      {
                        if (strcmp(name, Inputs->NextInput->Name) == 0)
                        {
                          AlreadyExists = 1;
                          break;
                        }
                        Inputs=Inputs->NextInput;
                      }
                      if (AlreadyExists)
                      {
                        AddTerm(Inputs->NextInput->A, x, y);
                      }
                      else
                      {
                        Inputs->NextInput = (PolyInput *)malloc(sizeof(PolyInput));
                        Inputs->NextInput->Name = (char *)malloc(sizeof(char) * 10);
                        Inputs->NextInput->Name = name;
                        Inputs->NextInput->A = InitPoly();
                        AddTerm(Inputs->NextInput->A, x, y);
                      }

                      printf("\n Input your Command :- (exit kills the loop)\n");
                      goto _StartLabel;
                    }
                    else
                    {
                      printf("\nInvalid command.\n \n Input your Command :- (exit kills the loop) \n There Exists a Stack 'S' of complex Numbers of 2 dimentions in this program.\n Please use The following three functions -: \n1. push x y | where the complex number is = x+iy, The complex number is pushed onto the stack. \n2.pop  | The topmost complex Number is popped. \n3.exit |Ends the program ) \n");
                      goto _StartLabel;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    printf("\n Input your Command :- (exit kills the loop)\n");
  }

  return 0;
}

// int main()
// {
//     Poly P = NULL;
//     Poly P2 = NULL;
//     Poly P3=NULL;
//     Poly P4 = NULL;

//     P = InitPoly();
//     P2= InitPoly();
//     P3=InitPoly();
//     P4=InitPoly();

//     AddTerm(P,0,69);
//     AddTerm(P,1,10);
//     // PrintPoly(P);
//     AddTerm(P,2,22);
//     //PrintPoly(P);
//     AddTerm(P,5,13);
//     //PrintPoly(P);
//     AddTerm(P,4,30);
//     //PrintPoly(P);
//     AddTerm(P,6,13);
//     //PrintPoly(P);
//     AddTerm(P,5,23);
//     PrintPoly(P);

//     printf("\nThe Polynomial P has been printed\n");

//     AddTerm(P2,1,10);
//     AddTerm(P2,2,22);
//     //AddTerm(P2,5,13);
//     AddTerm(P2,4,30);
//     AddTerm(P2,6,13);
//     //AddTerm(P2,5,23);
//       PrintPoly(P2);
//     printf("\nThe Polynomial P2 has been printed\n");

//     AddPolynomials(P,P2,P3);

//       printf("\nThe Polynomial P3  has beenadded \n");

//     PrintPoly(P3);

//     printf("\nThe Polynomial P3 = P+P2 has been printed\n");

//     SubtractPolynomials(P,P2,P4);

//           printf("\nThe Polynomial P4  has beenadded \n");
//           PrintPoly(P4);
//           DeleteTermByExponent(P4,5);
//           PrintPoly(P4);

//     printf("\nThe Polynomial P4 = P-P2 has been printed\n");

//     // DeleteTerm(P2,2);
//     // DeleteTerm(P2,1);

//     return 0;
// }