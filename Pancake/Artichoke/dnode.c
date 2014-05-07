#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"dnode.h"
#include"io.h"

BNT* constructorTree(BNL *data){
    BNT* node;
  	if( ( node = (BNT*) malloc(sizeof(BNT)) )!=NULL){
    	node->data = data;
    	node->left = NULL;
   		node->right = NULL;
 	}else{
 		printf("Mem loc error\n");
 		exit(0);
 	}
    return node;
}

void inOrdTreeTrans(BNT* node){
    if (node == NULL) return;
    inOrdTreeTrans(node->left);
    printf("%s ", node->data->data->name);
    inOrdTreeTrans(node->right);
}


BNL* constructorBNL (DNode *data){
	BNL *newList;
	if( ( newList = (BNL*) malloc(sizeof(BNL)) )!=NULL){
		newList->data= data;
		newList->next=NULL;
	}else{
		printf("Mem loc error\n");
		exit(0);
	}
	return newList;
}


BRL* constructorBRL (DNode *data){
	BRL *newList;
	if( ( newList = (BRL*) malloc(sizeof(BRL)) )!=NULL){
		newList->data= data;
		newList->next=NULL;
	}else{
		printf("Mem loc error\n");
		exit(0);
	}
	return newList;
}

void appendBRL(BRL *p){
	if(brlhead==NULL){
		brlhead=p;
		brltail=p;
	}else{
		brltail->next=p;
		brltail=p;
	}
}

BNL* isInList(BNL *bnlhead, char *name){
	BNL *handle=bnlhead;
	while(handle!=NULL){
		if(strcmp(handle->data->name,name)==0) return handle;
		handle=handle->next;
	}
	return NULL;
}



void printBNL(BNL *bnlhead){
	BNL *handle=bnlhead;
	while(handle!=NULL){
		//printf("%s-, total count is: %d \n",handle->data->name,handle->data->totalcount);
		handle=handle->next;
	}
}



void insertInOrderBRL(BRL **brlhead, BRL *new_node){
	BRL *current;
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

void rankBRL(BRL *brlhead){
	BRL *handle=brlhead;
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

//construct BRL
void BNLtoBRLconverter(BNL *bnlhead, BNL **brlhead){
	BNL *handle= bnlhead;
	int count=1;
	
	while(handle!=NULL){
		insertInOrderBRL(brlhead,constructorBRL(handle->data));
		handle=handle->next;
		count++;
	}
	
}


DNode* DNodeConstructor(YearNode *aNode, int boynum, char *boyname){
	DNode *newList;
	if( ( newList = (DNode*) malloc(sizeof(DNode)) )!=NULL){
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


YearNode* YearNodeConstructor(int year, int localrank, int boynum){
	YearNode *newList;
	if( ( newList = (YearNode*) malloc(sizeof(YearNode)) )!=NULL){
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


int countLNodes(BNL *bnlhead){
    int count = 0;
    BNL *temp = bnlhead;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}


BNT* sortedListToBSTRecur(BNL **head_ref, int n){
    /* Base Case */
    if (n <= 0)
        return NULL;
 
    /* Recursively construct the left subtree */
    BNT *left = sortedListToBSTRecur(head_ref, n/2);
 
    /* Allocate memory for root, and link the above constructed left
       subtree with root */
    BNT *root = constructorTree((*head_ref));
    root->left = left;
 
    /* Change head pointer of Linked List for parent recursive calls */
    *head_ref = (*head_ref)->next;
 
    /* Recursively construct the right subtree and link it with root
      The number of nodes in right subtree  is total nodes - nodes in
      left subtree - 1 (for root) which is n-n/2-1*/
    root->right = sortedListToBSTRecur(head_ref, n-n/2-1);
 
    return root;
}
 
 
BNT* sortedListToBST(BNL *bnlhead){
    
    int n = countLNodes(bnlhead);
    return sortedListToBSTRecur(&bnlhead, n);
}

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

void appendYearNode(YearNode **p, YearNode *aNode){
	YearNode *handle = *p;
	while(handle->next!=NULL){
		handle=handle->next;
	}
	handle->next=aNode;
}

void sortedInsertBNL(BNL **bnlhead, int year, int  localrank, int boynum, char *boyname){

	YearNode *aNode = YearNodeConstructor(year, localrank,  boynum);
	BNL *temp=isInList(*bnlhead,boyname);
	BNL *current;
	
	if(temp!=NULL){//name is already on the list
		(temp->data->totalcount) += (aNode->count);
		appendYearNode(&(temp->data->yearPointer), aNode);
		//printf("Name is on list %s \n", temp->data->name);
		
	}else{//the name is new to the list
		//printf("Name is NOT on list %s \n", boyname);
		
		DNode *anotherNode = DNodeConstructor(aNode, boynum ,boyname);
		BNL *new_node=constructorBNL(anotherNode);
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


int searchRank(BRL *brlhead, int num){
int res=0;
	BRL *handle=brlhead;
	while(handle!=NULL && handle->data->trank<=num){
		if(handle->data->trank ==num){
			res=1;
			//printf("%s : total rank(%d), total count(%d) \n",handle->data->name,handle->data->trank , handle->data->totalcount ); 
			print(handle->data);
		}
		handle=handle->next;
	}
	return res;
}


