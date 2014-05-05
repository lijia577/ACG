#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void arralloc(int **a, int n){
	*a=(int *)malloc(sizeof(int)*n);
}

//width m, height n, try to go back this
void matrixAllocation(int ***a ,int m, int n){
	*a= (int **) malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++){ // especially this line. 
		*(*a+i) = (int *) malloc(sizeof(int)*m);
	}
}

void load(char *fn, int *a, int *count){
	int i=0; 
	FILE *fp;
	char str[60];
	fp=fopen(fn,"r");
	
	if(fp == NULL) {
      perror("Error opening file");
 	  exit(0); 
    }
   
   //THE FOLLOWING IS IMPORTANT
    while( fgets (str, 60, fp)!=NULL ) {
      /* writing content to stdout */
      if(*count>0){
      	sscanf(str, "%d", &a[i]);
      	//puts(str);
      	(*count)--;
      	i++;
      }
    }//end while
    fclose(fp);

} 

void loadbyscanf(char *fn, int *a, int *count){
	FILE *fp;
	fp=fopen(fn,"r");
	
	if(fp == NULL) {
      perror("Error opening file");
 	  exit(0); 
    }
	
	int temp=0;
	
	// THE FOLLOWING LINE IS IMPORTANT
	while(fscanf(fp, "%d", &temp)>0){
		a[*count]=temp;
		(*count)++;
	}
	fclose(fp);
}

void main(){
	int a[10];
	int count=3;
	//load("test",a,&count);
	
	for(int i=0; i<3; i++){
		//	printf("%d\n",a[i]);
	}
	
	count=0;
	loadbyscanf("test",a,&count);
	for(int i=0; i<count; i++){
			printf("%d\n",a[i]);
	}
	
	
	puts("=============");
	int *arr=NULL;
	int **brr=NULL;
	arralloc(&arr, 4);
	
	matrixAllocation(&brr,4,3);
	
	for(int i=0; i<4; i++){
		arr[i]=10;
	}
	
	for(int i=0; i<4; i++){
		printf("%d\n",arr[i]);
	}
	
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			brr[i][j]=20;
		}
	}
	
	puts("***********");
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			printf("%d ",brr[i][j]);
		}
		printf("\n");
	}
}






