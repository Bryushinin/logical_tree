#ifndef LOGIC_HEADER_H_INCLUDED
#define LOGIC_HEADER_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>
using namespace std;

typedef struct link
{
 char cont;
 link* left;
 link* right;
} tree;

char* Read();
tree* Atom(char* st);
tree* Term(char* st);
tree* Form(char* st);
tree* Convert(char* st);
void Print(tree* A, int n);
int Computing2(tree* A);

#endif // LOGIC_HEADER_H_INCLUDED
