#include <stdio.h>
#include <stdlib.h>

int main(){
int dump=0;
char g_name[20],b_name[20],file_name[20],line[60];
int b_num, g_num;
int count=0;
int year=1900;
int first;
FILE * fin;
while(year<2015){
    	//reset stuff
        g_num=0;
        b_num=0;
        first =0;
       
        
        //open names file
        sprintf(file_name,"babynames/names%d",year);
        fin=fopen(file_name,"r");
                    
        // if file is missing
        if (fin==NULL) year++;
                    
        // otherwise
        else{
        	//fprintf(fout,"babynames/names%d\n",year);
            // read all the lines from the file
            while(fgets(line,60,fin)!=0){
            	// convert lines to arguments 
            	//puts("sdf");       
            	sscanf(line,"%d %s %d %s %d", &dump, b_name, &b_num, g_name, &g_num);
            	count++;
         }//end while
         year++;
		 fclose(fin);
         //rank boy and girl for current year
        }// end of else
    }//end of while(year)
printf("count is %d",count);
return 0;
}
