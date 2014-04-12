#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#define N 8
/* the main task is say you have

. . . . . . . . 
. . . . . . . .
. . . . . . . . 
. . . X 0 . . .
. . . 0 X . . . 
. . . . . . . .
. . . . . . . . 
. . . . . . . .

It is stored in a two D array with type X,O and null. Aussming that X is going to make a move. 
Figure out which . should be changed into ? 


meHelper explained 
For each X, explore eight directions:
step=1;
while(inBoard)
if ((step ==1 && current sign =(null or ?)) return (not this direction
if (cucurent sign is the same, in the case, X ) return (not this direction) 
//if (current sign is different, in the case, 0)keep going;
if (current sign is (null or ?) and step!=1) set current to be a question mark. 
 
 
Flip function:
Next, if the user choose one of the ? marks, then we should flip it. 
Again, assume that the current thing we are using is X, then explore 8 directrions: 
	for each direction:
		if the next token is X and step is 1, then not this direction;
		if the next token is NUll or Maybe, not this direction;
		if the next token is O, change it into X;
		if the next token is X and step is NOT 1, then stop. 
 
how to do computer Move:
Greedy, choose the step that can the flip the most token

*/

typedef enum  {X=1, O=2, M=3} token;

int board [N][N]={ {O,O,O,0,0,0,0,0},
                   {O,X,O,0,0,0,0,0},   
                   {O,O,O,0,0,0,0,0},    
                   {0,0,0,0,0,0,0,0},   
                   {0,0,0,0,0,0,0,0},  
                   {0,0,0,0,0,X,X,X}, 
                   {0,0,0,0,0,X,O,X},  
                   {0,0,0,0,0,X,X,X}  };
                   
char getTokenName(int t){
	switch(t){
		case X: return 'X';
		case O: return 'O';
		case M: return 'M';
		default: return '.';
	}
}

char getTokenNamer(int t){
	switch(t){
		case X: return 'X';
		case O: return 'O';
		//case M: return 'M';
		default: return '.';
	}
}


void print(){
printf("0 1 2 3 4 5 6 7 \n");
for(int i = 0; i<N ; i++){

		for( int j =0; j<N; j++){
		printf("%c ",getTokenName( board[i][j] ) );
		
		}
		printf("%d \n", i);
	}
}	

void printr(){
printf("0 1 2 3 4 5 6 7 \n");
for(int i = 0; i<N ; i++){

		for( int j =0; j<N; j++){
		printf("%c ",getTokenNamer( board[i][j] ) );
		
		}
		printf("%d \n", i);
	}
}

//move exist helper
int meCrawler(int t, int step, int m, int n){
    if( (step==1) && ((getTokenName(board[m][n]) == '.')||( getTokenName(board[m][n])  == 'M'))) return 1;
    if(board[m][n]==t) return 1;
    if( (step>1) && ((getTokenName(board[m][n]) == '.')||( getTokenName(board[m][n])  == 'M')) ){
	    board[m][n]=3;
		return 1;
	}
	return 0;
}

int moveExist (int t){//t indicates wethher this is a X or a O
	for(int i = 0; i<N ; i++){
		for( int j =0; j<N; j++){
			if(getTokenName( board[i][j] ) == getTokenName(t)){
				int m,n,step;
				
				//direction up
				m=i-1;
				step=1;
				while(m>=0){
					if(meCrawler(t,step,m,j)) break;
					step++;
					m--;
				}//end diretion up;

				//direction down
				m=i+1;
				step=1;
				while(m<N){
					if(meCrawler(t,step,m,j)) break;
					step++;
					m++;
				}//end diretion down;

               
				//direction left
				m=j-1;
				step=1;
				while(m>=0){
					//printf("token is: %c , step is %d\n",board step);
					if(meCrawler(t,step,i,m)) break;
					step++;
					m--;
				}//end diretion left;

				//direction right
				m=j+1;
				step=1;
				while(m<N){
					if(meCrawler(t,step,i,m)) break;
					step++;
					m++;
				}//end diretion right;
				
				//direction upleft
				m=i-1;
				n=j-1;
				step=1;
				while(m>=0){
					if(meCrawler(t,step,m,n)) break;
					step++;
					m--;
					n--;
				}//end diretion upleft;
				
				//direction downleft
				m=i+1;
				n=j-1;
				step=1;
				while(m<N && n>=0){
					if(meCrawler(t,step,m,n)) break;
					step++;
					m++;
					n--;
				}//end diretion downleft;
				
				//direction downright
				m=i+1;
				n=j+1;
				step=1;
				while(m<N && n<N){
					if(meCrawler(t,step,m,n)) break;
					step++;
					m++;
					n++;
				}//end diretion downright;
				
				//direction upright
				m=i-1;
				n=j+1;
				step=1;
				while(n<N && m>=0){
					if(meCrawler(t,step,m,n)) break;
					step++;
					m--;
					n++;
				}//end diretion upright;
				
			}//End of Eight Direction
			
		}
		printf("\n");
	}
} 


int fCrawler(int step, int t, int nt, int m, int n){
    if( (step==1) && ((getTokenName(board[m][n]) == '.')||( getTokenName(board[m][n])  == 'M'))) return 1;
   	if(board[m][n]==t) return 1; //if next is same as X, then break
   	if(board[m][n]==nt) board[m][n]=t;
   	if( (step>1) && (board[m][n]==t)) return 1;
   	return 0;
}

int flip(int t, int nt,int xloc, int yloc){ //t indicates X or O; nt is the opposite sign of X or O
	//the token at xloc yloc must be M. O
	if(board[xloc][yloc]!=M) return 1; //return 1 when the current location is not a maybe. 
	board[xloc][yloc]=t;
	
	//explore eight direction 
	    int m,n,step;
		
		//direction up
		m=xloc-1;
		n=yloc;
		step=1;
		while(m>=0){
			if(fCrawler(step, t, nt, m, n)) break;
			step++; m--;
		}//end diretion up;

		//direction down
		m=xloc+1;
		n=yloc;
		step=1;
		while(m<N){
			if(fCrawler(step, t, nt, m, n)) break;
			step++;
			m++;
		}//end diretion down;

               
		//direction left
		m=xloc;
		n=yloc-1;
		step=1;
		while(n>=0){
			if(fCrawler(step, t, nt, m, n)) break;
			step++;
			n--;
		}//end diretion left;

		//direction right
		m=xloc;
		n=yloc+1;
		step=1;
		while(n<N){
			if(fCrawler(step, t, nt, m, n)) break;
			step++;
			n++;
		}//end diretion right;		
	
	   //direction downright
		m=xloc+1;
		n=yloc+1;
		step=1;
		while(n<N && m<N){
			if(fCrawler(step, t, nt, m, n)) break;
			step++;
			n++;
			m++;
		}//end diretion downright;	
		
		//direction downleft
		m=xloc+1;
		n=yloc-1;
		step=1;
		while(m<N && n>=0){
			if(fCrawler(step, t, nt, m, n)) break;
			step++;
			n--;
			m++;
		}//end diretion downleft;	
		
		//direction upright
		m=xloc-1;
		n=yloc+1;
		step=1;
		while(n<N && m>=0){
			if(fCrawler(step, t, nt, m, n)) break;
			step++;
			n--;
			m++;
		}//end diretion upright;
		
	    //direction upright
		m=xloc-1;
		n=yloc-1;
		step=1;
		while(n>=0 && m>=0){
			if(fCrawler(step, t, nt, m, n)) break;
			step++;
			n--;
			m--;
		}//end diretion upright;
	
    return 0;
}


void main(){
	//print();
	//moveExist(1);
	//print();
	//flip(1,2,2,4);
	printr();
	moveExist(2);
	print();
    //printf("%c",getTokenName( board[0][0] ) );
}

