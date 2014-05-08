#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<getopt.h>
#include"main.h"
#include"dnode.h"
#include"io.h"

int main(int argc, char **argv){

	FILE *fp;
	char str[30], line[60], boyname[30], girlname[30];
	int localrank=0, boynum=0, girlnum=0, year=1900;
	
	extern char *optarg;
	nflag=0; rflag=0;
	char gender[20]={0},inputName[20]={0};
	int inputRank=0, sex=0, option;
	
	//handle command line argument
	if(argc <2) usage();//meaning there is no flag used 
	while ((option = getopt(argc, argv, "g::r::n::")) != -1){
		switch (option) {
		case 'g'://handle gender flag
			if(optarg!=NULL) strcpy(gender, optarg);
			break;
		case 'r'://handle rank flag
			if(optarg!=NULL) {
				rflag++;
				inputRank=atoi(optarg);
			}
			break;
	
		case 'n'://handle name flag
			if(optarg!=NULL){
				strcpy(inputName, optarg);
				nflag++;
			}
			break;
			
		default:
			usage();
		}
	}//end while
	
	checking(gender,&sex, inputRank); //check if all input are fine
	
	printf("Inputs: name is: %s, gender is:%c, rank is %d, gender code is %d\n",inputName, gender[0], inputRank, sex);
	
	//main loop
	while(year<2015){
		localrank=0; boynum=0; girlnum=0;
		
		sprintf(str,"babynames/names%d",year); //babynames/names
		fp = fopen(str,"r");
		
		if(fp==NULL) year++;
		else{
			while(fgets(line,60,fp)!=0){
				sscanf(line,"%d %s %d %s %d", &localrank, (char *)&boyname, &boynum, (char *)&girlname, &girlnum);
				sortedInsertNL( &bnlhead,  year,   localrank,  boynum,  boyname);
				sortedInsertNL( &gnlhead,  year,   localrank,  girlnum, girlname);
			}//end while
			year++;
			fclose(fp);
		}//end of else
	}//enf of while year	
		

	NLtoRLconverter(bnlhead, &brlhead);
	NLtoRLconverter(gnlhead, &grlhead);
	rankRL(brlhead);
	rankRL(grlhead);
	BNT *bRoot = sortedListToBST(bnlhead);
	BNT *gRoot = sortedListToBST(gnlhead);
	
	
	if(strlen(inputName)!=0){
		if(sex==0){
			puts("Check for the male baby data.");
			treeNameSearch(inputName, &bRoot);
			puts("Check for the male baby data.");
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

	freeTree(bRoot);
	freeTree(gRoot);
	freeList(brlhead);
	freeList(bnlhead);
	freeList(grlhead);
	freeList(gnlhead);
	return 0;
	
	
}//end main

void freeTree(BNT* node){
	if(node){
		freeTree(node->left);
		freeTree(node->right);
		freeAleaf(node);
	}
}

void freeAleaf(BNT *leaf){
	//BNT *handle = leaf;
	YearNode *node = leaf->data->data->yearPointer;
	YearNode *temp;
	while(node!=NULL){
		temp=node;
		node=node->next;
		free(temp);
	}
	free(leaf->data->data);
	free(leaf->data);
	free(leaf);
}

void freeList(NL *head){
	NL *node=head;
	NL *temp;
	while(node!=NULL){
		temp=node;
		node=node->next;
		free(temp);
	}
	head=NULL;
}
void treeNameSearch(char *name, BNT **root){
	DNode *res=BSTsearch(root,name);
	if(res==NULL) printf("The name %s does not exist any file.\n", name);
		else print(res);
		puts("\n");

}

void checking(char *gender, int *sex, int inputRank){
		if(nflag==0 && rflag ==0) usage();
		if(strlen(gender)==0) ; //puts("No Gender");
		else if(gender[0]!='m'&& gender[0]!='M'&& gender[0]!='f'&& gender[0]!='F'){
			puts("Invalid Gender input, use F or M. \nSee you next time!~~");
			exit(0);
		}
	
		if(rflag!=0 && inputRank <=0){
			puts("Invalid input rank. Rank should be non-negative number!\nSee you next time!~~");
			exit(0);
		}
	
		if(gender[0]=='m'||gender[0]=='M') *sex=1;
		else if(gender[0]=='f'||gender[0]=='F') *sex=2;
}
	









