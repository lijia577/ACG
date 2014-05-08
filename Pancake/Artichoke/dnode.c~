#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"dnode.h"
#include"io.h"

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



void appendNL(NL *p){
	if(brlhead==NULL){
		brlhead=p;
		brltail=p;
	}else{
		brltail->next=p;
		brltail=p;
	}
}

NL* isInList(NL *bnlhead, char *name){
	NL *handle=bnlhead;
	while(handle!=NULL){
		if(strcmp(handle->data->name,name)==0) return handle;
		handle=handle->next;
	}
	return NULL;
}



void printNL(NL *bnlhead){
	NL *handle=bnlhead;
	while(handle!=NULL){
		//printf("%s-, total count is: %d \n",handle->data->name,handle->data->totalcount);
		handle=handle->next;
	}
}


void inOrdTreeTrans(BNT* node){
    if (node == NULL) return;
    inOrdTreeTrans(node->left);
    printf("%s ", node->data->data->name);
    inOrdTreeTrans(node->right);
}

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

//construct BRL
void NLtoRLconverter(NL *bnlhead, NL **brlhead){
	NL *handle= bnlhead;
	int count=1;
	
	while(handle!=NULL){
		insertInOrderBRL(brlhead,constructorNL(handle->data));
		handle=handle->next;
		count++;
	}
	
}


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


BNT* sortedListToBSTRecur(NL **head_ref, int n){
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
 
 
BNT* sortedListToBST(NL *bnlhead){
    
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

void sortedInsertNL(NL **bnlhead, int year, int  localrank, int boynum, char *boyname){

	YearNode *aNode = YearNodeConstructor(year, localrank,  boynum);
	NL *temp=isInList(*bnlhead,boyname);
	NL *current;
	
	if(temp!=NULL){//name is already on the list
		(temp->data->totalcount) += (aNode->count);
		appendYearNode(&(temp->data->yearPointer), aNode);
		//printf("Name is on list %s \n", temp->data->name);
		
	}else{//the name is new to the list
		//printf("Name is NOT on list %s \n", boyname);
		
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


int searchRank(NL *brlhead, int num){
int res=0;
	NL *handle=brlhead;
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


