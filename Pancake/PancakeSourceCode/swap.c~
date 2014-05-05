#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is an example demonstrate the pointer usage in C! Very important!
   Think about how to swap two string literals and swap two integers. What
   are the differences and why.
*/
void swap(int *a, int *b){
	int temp =*a;
	*a=*b;
	*b=temp;
}


void swaps(char **a, char **b){
	char *temp=*a;
	*a=*b;
	*b=temp;
}

void main(){
	char *s= "hah";
	char *t= "Oh mo";
	printf("%s and %s \n",s,t);
 	swaps(&s,&t);
	printf("%s and %s \n",s,t);
	int a=10;
	int b=5;
	printf("%d %d\n",a,b);
	swap(&a,&b);
	printf("%d %d\n",a,b);
}
