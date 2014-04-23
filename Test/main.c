#include "main.h"
#include "init.h"
#include "io.h"
#include "makeMove.h"

int main(){

	srand(time(NULL));

	printf("\n\nWelcome to Othello!\n\n");
	

	initialize();
	
	int turn=1;
	
	//moveExist(X);
	while(countMs()){
	//clear();
		if(turn){		
		
			puts("X is playing!");
			
			moveExist(X);
			print();
			getEntry();
			flipIt(X,O,row,col,FLIPONLY);
			turn=!turn;
		}else{
		
			puts("O is playing!");
			moveExist(O);
			print();
			getEntry();
			flipIt(O,X,row,col,FLIPONLY);
			
			turn=!turn;
		}
		scoreKeep();
		print();
	
	}
	

	return 0;
}
