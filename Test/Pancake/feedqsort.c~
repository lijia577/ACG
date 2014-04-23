#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int number;
	int b;
} part;

part inventory[3]= {{20,3},
					{10,34},
					{30,34} };

int cmp_inventory(const void *p, const void *q){
	 return ((part *) p)->number -((part *) q)->number; 
} 

void main(){
	//the line below is critical. Note that for cmp_inventory, you are feed it with anything.
	qsort(inventory,3,sizeof(part),cmp_inventory); 
	for (int i=0; i<3; i++){
		printf("%d\n",inventory[i].number);	
	}

}
