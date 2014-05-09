#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"dnode.h"
#include"io.h"
//Tree constructor
BNT* constructorTree(NL *data){
    BNT* node;
  	if( ( node = (BNT*) malloc(sizeof(BNT)+1) )!=NULL){
    	node->data = data;
    	node->left = NULL;
   		node->right = NULL;
 	}else{
 		printf("Mem loc error\n");
 		exit(0);
 	}
    return node;
}

//Name list constructor
NL* constructorNL (DNode *data){
	NL *newList;
	if( ( newList = (NL*) malloc(sizeof(NL)+1 ) )!=NULL){
		newList->data= data;
		newList->next=NULL;
	}else{
		printf("Mem loc error\n");
		exit(0);
	}
	return newList;
}


//check if a name is already in a Name List
NL* isInList(NL *bnlhead, char *name){
	NL *handle=bnlhead;
	while(handle!=NULL){
		if(strcmp(handle->data->name,name)==0) return handle;
		handle=handle->next;
	}
	return NULL;
}


//print a name list
void printNL(NL *bnlhead){
	NL *handle=bnlhead;
	while(handle!=NULL){
		//printf("%s-, total count is: %d \n",handle->data->name,handle->data->totalcount);
		handle=handle->next;
	}
}

//Inserting node into Name List in order.
void insertInOrderBRL(NL **brlhead, NL *new_node){
	NL *current;
	if (*brlhead == NULL || ((*brlhead)->data->totalcount <new_node->data->totalcount) ){
        new_node->next = *brlhead;
        *brlhead = new_node;
    }else{
        
        current = *brlhead;
        while (current->next!=NULL && ((current->next->data->totalcount >new_node->data->totalcount)) ){
            current = current->next; 
        	    
        }
        
        new_node->next = current->next;
        current->next = new_node;
    }
}

//providing the total rank
void rankRL(NL *brlhead){
	NL *handle=brlhead;
	int rank=1;
	int pRank=1;
	int c=1;
	int prevCount=brlhead->data->totalcount;
	
	while(handle!=NULL){
		//printf("%s: total count is: %d ",handle->data->name,handle->data->totalcount);
		if(prevCount==handle->data->totalcount){
			handle->data->trank=pRank;
		}else{
			handle->data->trank=c;
			rank++;
		}
		pRank=handle->data->trank;
		c++;
		prevCount=handle->data->totalcount;
		handle=handle->next;
		//printf("rank is: %d\n",rank);
	}
}

//Name list to Rank list converter
void NLtoRLconverter(NL *bnlhead, NL **brlhead){
	NL *handle= bnlhead;
	int count=1;
	
	while(handle!=NULL){
		insertInOrderBRL(brlhead,constructorNL(handle->data));
		handle=handle->next;
		count++;
	}
	
}

//DNode Constructor
DNode* DNodeConstructor(YearNode *aNode, int boynum, char *boyname){
	DNode *newList;
	if( ( newList = (DNode*) malloc(sizeof(DNode)+1) )!=NULL){
		newList->trank = 0;
		strcpy(newList->name,boyname);
		newList->totalcount = boynum;
		newList->yearPointer=aNode;
	}else{
		printf("Mem loc error\n");
		exit(0);
	}
	return newList;
}

//YearNode Constructor
YearNode* YearNodeConstructor(int year, int localrank, int boynum){
	YearNode *newList;
	if( ( newList = (YearNode*) malloc(sizeof(YearNode)+1) )!=NULL){
		newList->year = year;
		newList->rank = localrank;
		newList->count= boynum;
		newList->next =NULL;
	}else{
		printf("Mem loc error\n");
		exit(0);
	}
	return newList;
}


int countLNodes(NL *bnlhead){
    int count = 0;
    NL *temp = bnlhead;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

//converting a Name list into a tree
BNT* sortedListToBSTRecur(NL **head, int n){
    /* Base Case */
    if (n <= 0)
        return NULL;
 
    // Recursively construct the left subtree 
    BNT *left = sortedListToBSTRecur(head, n/2);
 
    // Allocate memory and link
    BNT *root = constructorTree((*head));
    root->left = left;
 
    //Change head pointer of Linked List for parent recursive calls 
    *head = (*head)->next;
 
    // Recursively construct the right subtree 
    root->right = sortedListToBSTRecur(head, n-n/2-1);
 
    return root;
}
 
//helper function call
BNT* sortedListToBST(NL *bnlhead){
    int n = countLNodes(bnlhead);
    return sortedListToBSTRecur(&bnlhead, n);
}


//Binary search tree search function. recursively checks left and right
DNode* BSTsearch(BNT ** root, char *str){
	if(!(*root)) return NULL;
	if(strcmp(str,(*root)->data->data->name)<0 ) {
		BSTsearch(&((*root)->left), str);
	}else if(strcmp(str,(*root)->data->data->name)>0 ) {
		BSTsearch(&((*root)->right), str);
	}else{
		return (*root)->data->data;
	}
}

//apend a YearNode at the end of some given yearnode
void appendYearNode(YearNode **p, YearNode *aNode){
	YearNode *handle = *p;
	while(handle->next!=NULL){
		handle=handle->next;
	}
	handle->next=aNode;
}

//Construct a complete node and insert in order into some list. 
void sortedInsertNL(NL **bnlhead, int year, int  localrank, int boynum, char *boyname){

	YearNode *aNode = YearNodeConstructor(year, localrank,  boynum);
	NL *temp=isInList(*bnlhead,boyname);
	NL *current;
	
	if(temp!=NULL){//name is already on the list
		(temp->data->totalcount) += (aNode->count);
		appendYearNode(&(temp->data->yearPointer), aNode);
		//Name is on list
		
	}else{//the name is new to the list
		DNode *anotherNode = DNodeConstructor(aNode, boynum ,boyname);
		NL *new_node=constructorNL(anotherNode);
		//case where insertion happens before head.
		if (*bnlhead == NULL || strcmp((*bnlhead)->data->name,new_node->data->name)>=0 ){
       		new_node->next = *bnlhead;
        	*bnlhead = new_node;
        }else{
        	current =*bnlhead;
        	 while (current->next!=NULL && strcmp(current->next->data->name, new_node->data->name)<0){
            	current = current->next;
             }
        	 new_node->next = current->next;
             current->next = new_node;
        }  
	}
	
}

//doing the rank search iteratively.
int searchRank(NL *brlhead, int num){
int res=0;
	NL *handle=brlhead;
	while(handle!=NULL && handle->data->trank<=num){
		if(handle->data->trank ==num){
			res=1;
			print(handle->data);
		}
		handle=handle->next;
	}
	return res;
}


