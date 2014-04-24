#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int a;
	int b;

}part;

part p1[2]= {{10,20},{30,40}};


void gp (void *p, size_t n, size_t size){
	char * handle; //this has to be fucking char and i donno why
	for(handle=p ; handle < (char *)(p+n*size); handle+=size){ //!! This line
		if(size==sizeof(int)){
			printf("%d ", *((int *)handle));
		}else if(size==sizeof(part)){
			printf("%d ", ((part *)handle)->a);
		}else{
			printf("%f", *((double *)handle));
		}
	}
}


void main(){
	double num=10.3;
	gp(p1,2,sizeof(part));

}
