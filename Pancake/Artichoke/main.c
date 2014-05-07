#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"
#include"dnode.h"
#include"io.h"

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
	
	//puts("------------------");
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
    
  	puts("\nCheck for the male baby data.");
    int searchForRank=2380;
    puts(" ");
    if(!searchRank(brlhead, searchForRank)) puts("There is no baby name with this rank.");
    
    
    puts("\nCheck for the female baby data.");
    if(!searchRank(grlhead, searchForRank)) puts("There is no baby name with this rank.");
	//printf("counting is %d\n", counting);
	return 0;
	fclose(fp);
}











