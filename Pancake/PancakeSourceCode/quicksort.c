#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap(int *a, int *b){
    int temp= *a;
    *a=*b;
	*b=temp;
}


void quick2(int *a,int l, int u){
        if (l>u) return ;
        int t=a[l];
        int i=l;
        int j=u+1;
        while(1){
                do{i++;}while(i<=u && a[i]<=t);
                do{j--;}while(a[j]>t);
                if(i>j) break;
                swap(&a[i],&a[j]);
        }
		swap(&a[l],&a[j]);
        quick2(a,l,j-1);
        quick2(a,j+1,u);
}


int main(){
	int i=0;
	int a[10] = {123,2,1,1,1,1,4,3,2,1};
	while(i<10){
	 printf("%d\n", a[i]);
	 i++;
	 }
	//swap(&arr[0],&arr[1]);
	quick2(a,0,9);
	
	
	puts("");
	i=0;
	while(i<10){
	 printf("%d\n", a[i]);
	 i++;
	 }
}
