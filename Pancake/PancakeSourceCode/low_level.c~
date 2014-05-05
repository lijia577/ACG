#include <stdio.h>
#include <stdlib.h>

void printbits(unsigned int x) {
  unsigned char v = (char) x;
  int i; 
  for(i = 7; i >= 0; i--) putchar('0' + ((v >> i) & 1));
  puts("");
}

void setbit(int a, int b){//given number a, set the b th bit to be 1;
	a |=(1<<b);
	printbits(a);
}

void clearbit(int a, int b){
	a &= ~(1<<b);
	printbits(a);
}

void togbit(int a, int b){
	a ^= (1<<b);
	printbits(a);
}

int main(){
	
	unsigned int i=8, j=9;
	printf("%d\n",i>>1+j>>1); //0 right shift i 11.
	
	i=1;
	printf("%d\n",i&~i);// 0 again.
	
	i=2;j=1;int k=0;
	printf("%d\n",~i&j^k);// 0 again.
	
	i=7;j=8;k=9;
	printf("%d\n",i^j&k);// 15 
	
	i=0;
	
	printbits(i);
	//setting a bit 
	i |= 1<<2;
	printbits(i);
	
	//clear a bit 
	i &= ~(1<<2);
	printbits(i);
	
	//toggling a bit
	i ^= (1<<6);
	printbits(i);
	
	//checking a bit
	if(i&(1<<6)) puts("Ture");
	
	puts("Write functions to set a bit, clear a bit, tog a bit, with prototype void foo(int i, int move);");

	int test=4;
	
	if(test&(1<<2)) togbit(test,1);
	
	test=15;
	//printbits(test);
	clearbit(test,4);
	
	return 0;
	
}
