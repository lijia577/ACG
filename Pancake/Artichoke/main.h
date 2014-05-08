#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dnode.h"

void treeNameSearch(char *name, BNT **root);
void freeTree(BNT* node);
void freeAleaf(BNT *leaf);
void freeList(BNL *head);

#endif
