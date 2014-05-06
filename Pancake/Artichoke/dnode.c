#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NAME_LEN 20

struct totalRank {
	//Hold the total rank for each baby, used once for a baby,links to the year rank
	int trank; //total rank
	char name[NAME_LEN+1];
	int totalcount; //total count
	struct yearRank *yearPointer;
};
typedef struct totalRank DNode;


struct yearRank {
	//Structure to hold the year rank for each individual
	int year;
	int rank;
	int count;
	struct yearRank *next;
};
typedef struct yearRank YearNode;


struct tagA{
	DNode *data;
	struct tagA *next;
};
typedef struct tagA BNL;

BNL *bnlhead = NULL;
BNL *bnltail= NULL;


BNL* constructorBNL (DNode *data){
	BNL *newList;
	if( ( newList = (BNL*) malloc(sizeof(BNL)) )!=NULL){
		newList->data= data;
		newList->next=NULL;
	}else{
		printf("Mem loc error\n");
		exit(0);
	}
	return newList;
}

void appendBNL(BNL *p){
	if(bnlhead==NULL){
		bnlhead=p;
		bnltail=p;
	}else{
		bnltail->next=p;
		bnltail=p;
	}
}

//the strcmp is not working. The program think that tutu Tutu and Tom and Sida are the same. 
void insertInOrderBNL(BNL *p){
	BNL *handle=bnlhead;
	while(handle!=NULL){
	 //char a[20],b[20];
		//printf("here is %s  ", handle->data->name);
		printf("there is %s %d \n", p->data->name,strcmp(handle->data->name,p->data->name));
		if(strcmp(handle->data->name,p->data->name)!=0){
			appendBNL(p);
		}
		handle=handle->next;
	}
	puts("you should insert this node before some place");
	return;
}



void printBNL(){
	BNL *handle=bnlhead;
	while(handle!=NULL){
		printf("%s\n",handle->data->name);
		handle=handle->next;
	}
}

DNode* DNodeConstructor(YearNode *aNode, int boynum, char *boyname){
	DNode *newList;
	if( ( newList = (DNode*) malloc(sizeof(DNode)) )!=NULL){
		newList->trank = 0;
		strcpy(newList->name,boyname);
		newList->totalcount = boynum;
		newList->yearPointer=aNode;
	}else{
		printf("Mem loc error\n");
		exit(0);
	}
	return newList;
}


YearNode* YearNodeConstructor(int year, int localrank, int boynum){
	YearNode *newList;
	if( ( newList = (YearNode*) malloc(sizeof(YearNode)) )!=NULL){
		newList->year = year;
		newList->rank = localrank;
		newList->count= boynum;
		newList->next =NULL;
	}else{
		printf("Mem loc error\n");
		exit(0);
	}
	return newList;
}





