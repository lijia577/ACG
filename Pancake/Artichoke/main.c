#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"
#include"dnode.h"
#include"dnode.c"


int main(){
	int year=2010;
	FILE *fp;
	char str[30];
	
	char boyname[30];
	char girlname[30];
	int localrank;
	int boynum;
	int girlnum;
	
	int pCount=0;
	
	sprintf(str,"testfile/%d",year);
	
	
	puts("****************");
	while((fp = fopen(str,"r"))!=NULL){
		
		while((fgets(str,sizeof(str), fp))!=NULL){
			sscanf(str,"%d %s %d %s %d", &localrank, (char *)&boyname, &boynum, (char *)&girlname, &girlnum);
			
			if(str[0]!=' ' && strlen(str)>5){//this line detects empty line
				//printf("\n   year is %d \n", year);
				sortedInsertBNL( &bnlhead,  year,   localrank,  boynum,  boyname);
			}
			
		}//end while fgets	
		
			
		//switch to another file.
		year++;
		fclose(fp);
		sprintf(str,"testfile/%d",year);
		//end of swith to antoher file
	}
	
	printBNL(bnlhead);
	puts("=============================");
	
	BNLtoBRLconverter(bnlhead);
	rankBRL(brlhead);
	
	
	BNT *bRoot = sortedListToBST(bnlhead);
	inOrdTreeTrans(bRoot);
	puts("--------------");
	
	
	//this is BST search
	char s[20]="Brad";
	DNode *res=BSTsearch(&bRoot,s);
	print(res);
	//end of BST search 

   //Search with rank
    int searchForRank=2;
    searchRank(brlhead, searchForRank);

	return 0;
}

void print(DNode *res){
	printf("%s : total rank(%d), totla count(%d) \nHistogram---------------------------\n", res->name, res->trank, res->totalcount);
	YearNode *handle = res->yearPointer;
	while(handle!=NULL){
		printf("%d     %d(%d)\n", handle->year, handle->count, handle->rank);
		handle=handle->next;
	}
}

void searchRank(BRL *brlhead, int num){
	BRL *handle=brlhead;
	while(handle!=NULL && handle->data->trank<=num){
		if(handle->data->trank ==num){
			printf("%d %s %d \n",handle->data->totalcount, handle->data->name, handle->data->trank );
		}
		handle=handle->next;
	}
}








