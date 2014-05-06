#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NAME_LEN 20
#include"dnode.c"
//#include"bst.c"

int main(){
	int year=2010;
	FILE *fp;
	char str[30];
	
	char boyname[30];
	char girlname[30];
	int localrank;
	int boynum;
	int girlnum;
	
	sprintf(str,"testfile/%d",year);
	while((fp = fopen(str,"r"))!=NULL){
		
		while((fgets(str,sizeof(str), fp))!=NULL){
			sscanf(str,"%d %s %d %s %d", &localrank, (char *)&boyname, &boynum, (char *)&girlname, &girlnum);
			//printf("%d %s %d %s %d \n", localrank,  (char *)&boyname, boynum , (char *)&girlname, girlnum);
			
			//Construct BNLlist 
			YearNode *aNode = YearNodeConstructor(year, localrank,  boynum);
			DNode *newList = DNodeConstructor(aNode, boynum ,(char *) &boyname);
			insertInOrderBNL(&bnlhead,constructorBNL(newList),aNode); 
			//end construct BNLlist
			
			printf("*****newList trank: %d, name:%s,totalcount:%d, and that: %d ************\n", 
					newList->trank, newList->name, newList->totalcount, newList->yearPointer->year,1);
		}//end while fgets	
		
			
		//switch to another file.
		year++;
		fclose(fp);
		sprintf(str,"testfile/%d",year);
		//end of swith to antoher file
	}
	
	printBNL();
	
	puts("=========");
	BNLtoBRLconverter();
	printBRL();
	
	
	BNT *root = sortedListToBST(bnlhead);
	inOrdTreeTrans(root);
	puts("--------------");
	
	
	//this is BST search
	char s[20]="Brad";
	DNode *res=BSTsearch(&root,s);

	printf("\n\nRes for %s: Name: %s, total Rank is: %d , total count is: %d\n ",s, res->name, res->trank, res->totalcount);
	//end of BST search 

    YearNode *node=res->yearPointer;
    
	
	//while(1){
	    printf("	Year is: %d, rank is :%d, count is: %d\n", node->year, node->rank, node->count);
	    if(node->next == NULL) puts("XX");
		//node=node->next;
		//if(node==NULL) break;	
	//}
	



	return 0;
}












