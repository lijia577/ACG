#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//unsigned int has 4 byte, 32 bits.  That's partially explained the sizeof person
typedef struct guy{
	unsigned int married:1;
	unsigned int a:32;
	unsigned int num_kids:3;
	char *name;
}Person;

void main(){
	Person p1;
	printf("%ld\n",sizeof(p1));
	
	int a; 
	unsigned int b;
	char c;
	char *d;
	
	printf("size of int : %ld\n",sizeof(a));
	printf("size of unsigned int : %ld\n",sizeof(b));
	printf("size of char : %ld\n",sizeof(c));
	printf("size of char* : %ld\n",sizeof(d));
	
	//Indeed, there is nothing different btw using a bit fields v.s using a normal struct field...
	p1.name="Jia Li";
	p1.married=1;
	p1.num_kids=7;
	if(1){
		printf("%s\n",p1.name);
		printf("%d\n",p1.num_kids);
		printf("%d\n",p1.married);
	}	
}
