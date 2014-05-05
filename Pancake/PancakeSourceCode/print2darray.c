#include <stdio.h>
#include <stdlib.h>

void f1(int *a){ //flattens it, you know the width is 4
	int i,j;
	for(i=0; i<3;i++){
	    for(j=0;j<4;j++){
	    	printf("%02d ",*(a+3*i+j));
	    
	   }puts("");
	}
}



int main(){
	int a[3][4],i,j,c=0;
	for(i=0;i<3;i++){
		for(j=0;j<4;j++,c++){
			a[i][j]=c;
		}
	}
	
	f1((int *)a); //you need to cast the pointer because the type of A is really int *[4]

return 0;
}
