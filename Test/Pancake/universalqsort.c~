#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct  {
	char* name;//char * is 8!
	int id;
	float grade;
}student;

void swap(int *a, int *b){
    int temp= *a;
    *a=*b;
	*b=temp;
}

int cpName(const void *p, const void *q){
	return strcmp( ((student *)p)->name,  ((student *)q)->name );
	//return 1;
}

int cpGrade(const void *p, const void *q){
	if((((student *)p)->grade - ((student *)q)->grade)>0){
		return 1;
	}else if((((student *)p)->grade - ((student *)q)->grade)<0){
		return -1;
	}else return 0;
}



void qsortuniversal(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *)){

}

void qsorty(int a[], int l, int u, )){
	if(l>u) return;
	int t = a[l];
	int i=l;
	int j=u+1;
	while(1){
		do{i++;}while(i<=u && a[i]<=t);
		do{j--;}while(a[j]>t);
		if(i>j) break;
		swap(&a[i], &a[j]);
	}
	swap(&a[l], &a[j]);
	qsorty(a,l,j-1);
	qsorty(a,j+1,u);
}

int main(){
	student *s1;
	if( (s1=(student*)malloc(sizeof(student)))==NULL ){
		puts("Allocation mem eror!");exit(0);
	} 
	
    s1->id=1;
    s1->grade=10.0;
    s1->name="B";
    
    student *s2;
    if( (s2=(student*)malloc(sizeof(student)))==NULL ){
		puts("Allocation mem eror!");exit(0);
	} 
	
    s2->name="A";
    s2->grade=9.5;
    
   //printf("%d\n", cpGrade(s1,s2));
    
    
    int a[10] = {9,3,4,5,3,3,1,2,3,10};
    int i=0;
	while(i<10){
	 printf("%d\n", a[i]);
	 i++;
	 }
	//swap(&arr[0],&arr[1]);
	qsorty(a,0,9);
	
	
	puts("");
	i=0;
	while(i<10){
	 printf("%d\n", a[i]);
	 i++;
	 }
    //
 //   int i=0;
   
}
