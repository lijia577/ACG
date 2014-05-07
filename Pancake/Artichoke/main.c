#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"
#include"dnode.h"
#include"dnode.c"


int main(){

	int year=1900;
	FILE *fp;
	char str[30],line[60];
	char boyname[30];
	char girlname[30];
	int localrank;
	int boynum;
	int girlnum;
	
	int pCount=0;
	

	while(year<2015){
		boynum=0;
		girlnum=0;
		localrank=0;
		
		sprintf(str,"babynames/names%d",year); //babynames/names
		fp = fopen(str,"r");
		
		if(fp==NULL) year++;
		
		else{
			while(fgets(line,60,fp)!=0){
				sscanf(line,"%d %s %d %s %d", &localrank, (char *)&boyname, &boynum, (char *)&girlname, &girlnum);
				pCount++;
				sortedInsertBNL( &bnlhead,  year,   localrank,  boynum,  boyname);
				sortedInsertBNL( &gnlhead,  year,   localrank,  girlnum, girlname);
			}//end while
			year++;
			fclose(fp);
		}//end of else
	}//enf of while year	
		
	//printf("pCount is %d",pCount);
	//puts("Name should be in alpaphetical order");
	//printBNL(bnlhead);
	//puts("");
	//printBNL(gnlhead);
	//puts("----------------------");
	
	//puts("Rank should be in order");
	BNLtoBRLconverter(bnlhead, &brlhead);
	BNLtoBRLconverter(gnlhead, &grlhead);
	rankBRL(brlhead);
	rankBRL(grlhead);
	
	puts("------------------");
	BNT *bRoot = sortedListToBST(bnlhead);
	BNT *gRoot = sortedListToBST(gnlhead);
	//printf("\nIn order transversal of tree: ");
	//inOrdTreeTrans(bRoot);
	//puts("");
	
	//printf("\nIn order transversal of tree: ");
	//inOrdTreeTrans(gRoot);
	//puts("");
	
	
	//this is BST search
	//puts("\nHere comes the BT search");
	char s[20]="Sd";
	DNode *res=BSTsearch(&bRoot,s);
	if(res==NULL) printf("%s does not exist in any file.\n", s);
	else print(res);
	puts("\n");
	char g[20]="Alyssa";
	DNode *gre=BSTsearch(&gRoot,g);
	if(gre==NULL) printf("%s does not exist in any file.", g);
	else print(gre);
	
	//end of BST search 

   //Search with rank
  	puts("\nHere comes the Rank search");
    int searchForRank=1;
    puts("boy");
    searchRank(brlhead, searchForRank);
    puts("girl");
    searchRank(grlhead, searchForRank);
	//printf("counting is %d\n", counting);
	return 0;
	fclose(fp);
}

void print(DNode *res){
	printf("%s : total rank(%d), totla count(%d) \nHistogram---------------------------\n", res->name, res->trank, res->totalcount);
	YearNode *handle = res->yearPointer;
	while(handle!=NULL){
		printf("%d ", handle->year);
		int n = (handle->count)/300;
		while (n--) putchar('.');
		
		printf("%d(%d)\n", handle->count, handle->rank);
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








