#include <stdio.h>
#include <stdlib.h>

/* this program is used to test if the current system is big or little endian
   the idea is to use unsigned int 4 bytes, 32 bit. Cast it into char. 	
   
   You machine is little endian, which means:
   The address looks like: 1003, 1002, 1001, 1000.
   
   
*/


void main(){
	unsigned int i= 1;
	char *c = (char *) &i;
	
	if(*c) printf("Little Endian \n");
	else printf("Big Endian\n");

}
