#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NAME_LEN 20
#include"dnode.c"
//#include"bst.c"

int main(){
	int year=2011;
	FILE *fp;
	char str[30];
	
	char boyname[30];
	char girlname[30];
	int localrank;
	int boynum;
	int girlnum;
	
	sprintf(str,"testfile/%d",year);
	//YearNode *a = YearNodeConstructor(2012, 100,  3);
	//YearNode *b =  YearNodeConstructor(2013, 3,  34);
	//appendYearNode(&a, b);
	//printf("Hope you are find: %d\n",a->next->year);
	
	puts("****************");
	while((fp = fopen(str,"r"))!=NULL){
		
		while((fgets(str,sizeof(str), fp))!=NULL){
			sscanf(str,"%d %s %d %s %d", &localrank, (char *)&boyname, &boynum, (char *)&girlname, &girlnum);
			//printf("%d %s %d %s %d \n", localrank,  (char *)&boyname, boynum , (char *)&girlname, girlnum);
			
			//Construct BNLlist 
			//YearNode *aNode = YearNodeConstructor(year, localrank,  boynum);
			//DNode *newList = DNodeConstructor(aNode, boynum ,(char *) &boyname);
			//insertInOrderBNL(&bnlhead,constructorBNL(newList),aNode); 
			//end construct BNLlist
			sortedInsertBNL( &bnlhead,  year,   localrank,  boynum,  boyname);
			
			//printf("newList trank: %d, name:%s,totalcount:%d, and that: %d \n", 
					//newList->trank, newList->name, newList->totalcount, newList->yearPointer->year,1);
		}//end while fgets	
		
			
		//switch to another file.
		year++;
		fclose(fp);
		sprintf(str,"testfile/%d",year);
		//end of swith to antoher file
	}
	
	printBNL();
	puts("=============================");
	
	BNLtoBRLconverter();
	printBRL();
	
	
	BNT *root = sortedListToBST(bnlhead);
	inOrdTreeTrans(root);
	puts("--------------");
	
	
	//this is BST search
	char s[20]="Sida";
	DNode *res=BSTsearch(&root,s);

	printf("\n\nRes for %s: Name: %s, total Rank is: %d , total count is: %d \nYear is [%d,%d,%d] \nYear is [%d,%d,%d] \n",s, res->name, res->trank, res->totalcount, res->yearPointer->year, res->yearPointer->rank, res->yearPointer->count,res->yearPointer->next->next->year,res->yearPointer->next->next->rank, res->yearPointer->next->next->count);
	//end of BST search 

    YearNode *node=res->yearPointer;
    
	
	//while(1){
	   // printf("	Year is: %d, rank is :%d, count is: %d\n", node->year, node->rank, node->count);
	   // if(node->next == NULL) puts("XX");
		//node=node->next;
		//if(node==NULL) break;	
	//}
	



	return 0;
}












