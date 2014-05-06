#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NAME_LEN 20
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
	
	sprintf(str,"testfile/%d",year);
	while((fp = fopen(str,"r"))!=NULL){
		
		while((fgets(str,sizeof(str), fp))!=NULL){
			sscanf(str,"%d %s %d %s %d", &localrank, (char *)&boyname, &boynum, (char *)&girlname, &girlnum);
			//printf("%d %s %d %s %d \n", localrank,  (char *)&boyname, boynum , (char *)&girlname, girlnum);
			
			//Construct BNLlist 
			YearNode *aNode = YearNodeConstructor(year, localrank,  boynum);
			DNode *newList = DNodeConstructor(aNode, boynum ,(char *) &boyname);
			insertInOrderBNL(&bnlhead,constructorBNL(newList)); 
			//end construct BNLlist
			
			//printf("newList trank: %d, name:%s,totalcount:%d, and that: %d \n", 
			//		newList->trank, newList->name, newList->totalcount, newList->yearPointer->year);
		}//end while fgets	
		
			
		//switch to another file.
		year++;
		fclose(fp);
		sprintf(str,"testfile/%d",year);
		//end of swith to antoher file
	}
	
	printBNL();
	
	BNLtoBRLconverter();
	puts("=========");
	printBRL();
	
	//now you have two linkedlist BRL and BNL 

	return 0;
}












