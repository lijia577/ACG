#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//USE RECURSION TO CALCULATE  FIBONACCI SEQUENCE 


int swap(int*a, int *b){
	//int temp= *a;
	//*a=*b;
	//*b=temp;
	
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}

int factorial(int x){
	if(x<1) return 0;
	if(x==1) return 1;
	return x*(factorial(x-1));
}
	

int power(int base, int n){
	if(n==0) return 1;
	if(n==1) return base;
	else return base*power(base,n-1);
	//else return 
}


//Ugh?? what the heck?
int interleave(int a[], int len) {
  int n = len/2;
  for (int i = 1; i < n; i++) { // my step no.
    for (int j = 0; j < i; j++) { // no. of swaps
      swap(&a[n-i+2*j], &a[n-i+2*j+1]);
      	for(int i =0; i<10; i++){
			printf("%d ",a[i]);
		}puts("");
    }
  }
}

int main(){
	int x = power(0,0);
	//printf("%d\n",x);
	
	int a[10]={1,2,3,4,5,6,7,8,9,0};
	interleave(a, 10);
	
}
