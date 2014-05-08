#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dnode.h"

int nflag, rflag;

void treeNameSearch(char *name, BNT **root);
void freeTree(BNT* node);
void freeAleaf(BNT *leaf);
void freeList(NL *head);
void checking(char *gender, int *sex,int inputRank);

#endif
