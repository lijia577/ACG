#include <stdio.h>
#include <stdlib.h>
#include "main.h"

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

For each X, explore eight directions:
step=1;
while(inBoard)
if ((step ==1 && current sign =(null or >?)) return (not this direction
if (cucurent sign is the same, in the case, X ) return (not this direction) 
if (current sign is different, in the case, 0)keep going;
if (current sign is (null or ?) and step!=1) set current to be a question mark. 
 
 
 
Next, if the user choose one of the ? marks, then we should flip it. 
Again, assume that X is put, then explore 8 directrions: 
	if(there is X ahead), flipped all the way up untill X. 
 
 
how to do 

*/
void main(){
    
    
}

