#include"dnode.h"
#include <stdio.h>

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
