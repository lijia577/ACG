#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp= *a;
	*a=*b;
	*b=temp;
}

void transpose(int a[], int s, int t, int len){
    if(s==len/2-1) return;
	for(int i = s+1; i<len/2; i++) swap(&a[i], &a[((t-s)/2)+i]);
	transpose(a, s+1, t-1,len);
}

//Interesting thoguht but we will hang there. 
void arithmetictranspose(int *a, int len){
int n = len/2;
  for (int i = 1; i < n; i++) { // my step no.
    for (int j = 0; j < i; j++) { // no. of swaps
      swap(&a[n-i+2*j],&a[n-i+2*j+1]);
    }
  }
}

void main(){
	int a[] = {1,2,3,4,5,6,1,2,3,4,5,6};
	transpose(a,0,11,12);
	//arithmetictranspose(a,6);
	  for(int i=0; i<12; i++){
		printf("%d ", a[i]);
	  }
	  puts("");
}
