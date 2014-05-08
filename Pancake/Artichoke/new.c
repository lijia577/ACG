/*
	example of command line parsing via getopt
	usage: getopt [-dmp] -f fname [-s sname] name [name ...]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void usage(){
	puts("Option is invalid, remember to provide either rank or name, or both. ");
	printf("Usage: proj8.out [-g gender] [-r rank] [-n name]\n");
	exit(2);
}


int main(int argc, char **argv){
	extern char *optarg;
	int nflag=0;
	int rflag=0;
	
	char gender[20]={0};
	int sex=0;
	char inputName[20]={0};
	int inputRank=0;
	
	if(argc <2) usage();
	int option;
	while ((option = getopt(argc, argv, "g::r::n::")) != -1){
		switch (option) {
		case 'g':
			//puts("Gender");
			//printf("optarg : %s \n", optarg);
			//printf("Gender is :%s\n", optarg);
			strcpy(gender, optarg);
			break;
		case 'r':
			//puts("Rank");
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
	
	//if(strlen(inputName)==0) puts("No name");
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
}




