#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printbits(unsigned int x) {
  unsigned char v = (char) x;
  int i; 
  for(i = 7; i >= 0; i--) putchar('0' + ((v >> i) & 1));
  puts("");
}

//retrieve bit field s-t, assume index starts with 0, t>=s, with integer num.
unsigned int retrieve (unsigned int num, int s, int t){ 
	unsigned int p= (unsigned int)pow(2,t-s+1);	
	return (num>>(s))&(p-1);
}

//set bit field s-t with store, store boundary not checked
//assume index starts with 0, t>=s, with integer num, clear it first
unsigned int setbitfield(unsigned int num, int store, int s, int t){
	unsigned int p= (unsigned int)pow(2,t-s+1);	
	return num&~((p-1)<<s)|(store<<s);
}

//clear bit field s-t, assume index starts with 0, t>=s, with integer num.
unsigned int clearbitfield(unsigned int num, int s, int t){
	unsigned int p = (unsigned int)pow(2,t-s+1);
	return num&~((p-1)<<s);
}

//tog bit field s-t, assume index starts with 0, t>=s, with integer num.
unsigned int togbitfield(unsigned int num, int s, int t){
	unsigned int p= (unsigned int ) pow(2,t-s+1);
	return num^((p-1)<<s);
}


//this f is from textbook and it does not do what it suppose to do..
unsigned int f(unsigned int i, int m, int n){
    return (i>>(m+1-n)) & ~(~0<<n);
}


int main(){
	unsigned int i=63;
	printbits(i);
    //WARN: it's very important clear up the space by using i&~(7<<4) before hand 
	//i = i&~(7<<4)|(5<<4); //store 101(which is decimal 7)  to 4-6 position 
	
	i=0;
	i |=(1<<4);
	i |=(1<<6);
	i |=(1<<7);
	printbits(i);
	//retriving bit 4-6 from i; remember you need to get others unaffected.
	int j = (i>>4) & 7;
	
	printbits(j);
	
	puts("------------");
	i=0;
	printbits(i);
	i=setbitfield(i,7,1,3);
	//i= clearbitfield(i,4,5);
	//i= togbitfield(i,0,3);
	printbits(i);
	return 0;
}

