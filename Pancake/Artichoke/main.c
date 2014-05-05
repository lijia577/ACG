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


struct fRankList{ 
	//female Rank List
	struct DNode *next;
};
typedef struct fRankList fRankNode;

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
			printf("%d %s %d %s %d \n", localrank,  (char *)&boyname, boynum , (char *)&girlname, girlnum);
			
			
		}//end while fgets	
		
		
		//switch to another file.
		year++;
		fclose(fp);
		sprintf(str,"testfile/%d",year);
		//end of swith to antoher file
	}
	

	


return 0;
}
