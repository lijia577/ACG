#include"dnode.h"
#include <stdio.h>
#include <stdlib.h>

//print out result given a DNode
void print(DNode *res){
	printf("%s : total rank(%d), totla count(%d) \nHistogram---------------------------\n", res->name, res->trank, res->totalcount);
	YearNode *handle = res->yearPointer;
	while(handle!=NULL){
		printf("%d ", handle->year);
		int n = (handle->count)/300;
		while (n--) putchar('.');
		
		printf("%d(%d)\n", handle->count, handle->rank);
		handle=handle->next;
	}
	puts("");
}

//prompt message
void usage(){
	puts("Option is invalid, remember to provide either rank or name, or both. ");
	printf("Usage: proj8.out [-g gender] [-r rank] [-n name]\n");
	exit(2);
}
