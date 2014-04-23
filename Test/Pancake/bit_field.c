#include <stdio.h>
#include <stdlib.h>

void printbits(unsigned int x) {
  unsigned char v = (char) x;
  int i; 
  for(i = 7; i >= 0; i--) putchar('0' + ((v >> i) & 1));
  puts("");
}


int main(){
	int i=63;
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
	return 0;
}

