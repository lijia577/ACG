#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void print(int *a, int n){
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
	}puts("");
}

int add(int a, int b){
	return a+b;
}

int main(){
	void (*fp) (int *a, int n);
	int (*fp1) (int a, int b);
	int a[3] = {1,2,3};
	//print(a,3);
    fp=print;
    fp1=add;
   // (*fp)(a,fp1());
   printf("%d\n",fp1(2,3));
return 0;
}
