#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<getopt.h>
#include"main.h"
#include"dnode.h"
#include"io.h"

int main(int argc, char **argv){

	int year=1900;
	FILE *fp;
	char str[30],line[60];
	char boyname[30];
	char girlname[30];
	int localrank;
	int boynum;
	int girlnum;
	
	extern char *optarg;
	int nflag=0;
	int rflag=0;
	char gender[20]={0};
	char inputName[20]={0};
	int inputRank=0;
	int sex=0;
	
	if(argc <2) usage();
	int option;
	while ((option = getopt(argc, argv, "g::r::n::")) != -1){
		switch (option) {
		case 'g':
			if(optarg!=NULL) strcpy(gender, optarg);
			break;
		case 'r':
			rflag++;
			inputRank=atoi(optarg);
			break;
	
		case 'n':
			//puts("Name");
			//printf("Name is :%s\n", optarg);
			strcpy(inputName, optarg);
			nflag++;
			break;
		
		default:
			usage();
			
		}
	}
	if(nflag==0 && rflag ==0) {puts("sdf");usage();}
	
	
	if(strlen(gender)==0) ; //puts("No Gender");
	else if(gender[0]!='m'&& gender[0]!='M'&& gender[0]!='f'&& gender[0]!='F'){
		puts("Invalid Gender input, use F or M. \nSee you next time!~~");
		exit(0);
	}
	
	if(rflag!=0 && inputRank <=0){
		puts("Invalid input rank. Rank should be non-negative number!\nSee you next time!~~");
		exit(0);
	}
	
	if(gender[0]=='m'||gender[0]=='M') sex=1;
	else if(gender[0]=='f'||gender[0]=='F') sex=2;
	
	printf("Inputs: name is: %s, gender is:%c, rank is %d, gender code is %d\n",inputName, gender[0], inputRank, sex);
	

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
				sortedInsertBNL( &bnlhead,  year,   localrank,  boynum,  boyname);
				sortedInsertBNL( &gnlhead,  year,   localrank,  girlnum, girlname);
			}//end while
			year++;
			fclose(fp);
		}//end of else
	}//enf of while year	
		

	BNLtoBRLconverter(bnlhead, &brlhead);
	BNLtoBRLconverter(gnlhead, &grlhead);
	rankBRL(brlhead);
	rankBRL(grlhead);
	
	BNT *bRoot = sortedListToBST(bnlhead);
	BNT *gRoot = sortedListToBST(gnlhead);
	
	
	if(strlen(inputName)!=0){
		if(sex==0){
			puts("checking male");
			treeNameSearch(inputName, &bRoot);
			puts("checking female");
			treeNameSearch(inputName, &gRoot);
		}else if(sex==1){
			treeNameSearch(inputName, &bRoot);
		}else if(sex==2){
			treeNameSearch(inputName, &gRoot);
		}
		
	}
	//end of BST search 

   //Search with rank
    if(inputRank>0){
    	if(sex==0){
			puts("\nCheck for the male baby data.");
   		 	if(!searchRank(brlhead, inputRank)) puts("There is no baby name with this rank.");
   		 	 puts("\nCheck for the female baby data.");
   			 if(!searchRank(grlhead, inputRank)) puts("There is no baby name with this rank.");
		}else if(sex==1){
			if(!searchRank(brlhead, inputRank)) puts("There is no baby name with this rank.");
		}else if(sex==2){
			if(!searchRank(grlhead, inputRank)) puts("There is no baby name with this rank.");
		}
    }//end rank

	return 0;
	//fclose(fp);
}

void treeNameSearch(char *name, BNT **root){
	DNode *res=BSTsearch(root,name);
	if(res==NULL) printf("%s does not exist in any file.\n", name);
		else print(res);
		puts("\n");

}










