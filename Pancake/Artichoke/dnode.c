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


struct tagA{
	DNode *data;
	struct tagA *next;
};
typedef struct tagA BNL;

BNL *bnlhead = NULL;
BNL *bnltail= NULL;


struct tagB{
	DNode *data;
	struct tagA *next;
};
typedef struct tagA BRL;

BRL *brlhead = NULL;
BRL *brltail= NULL;

struct TNode{
    BNL *data;
    struct TNode* left;
    struct TNode* right;
};
typedef struct TNode BNT;


//----------------------------------------

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

//the strcmp is not working. The program think that tutu Tutu and Tom and Sida are the same. 
void insertInOrderBNL(BNL **bnlhead, BNL *new_node){
	BNL *current;
	//special head case
	if (*bnlhead == NULL || strcmp((*bnlhead)->data->name,new_node->data->name)>0 ){
        new_node->next = *bnlhead;
        *bnlhead = new_node;
    }else if(  strcmp( (*bnlhead)->data->name, new_node->data->name)==0   ){
    	//puts("same + update");
    	((*bnlhead)->data->totalcount)+=(new_node->data->totalcount);
    	return;
    }else{
        /* Locate the node before the point of insertion */
        current = *bnlhead;
        while (current->next!=NULL &&  (strcmp(current->next->data->name, new_node->data->name)<=0) ){
            if(strcmp( current->next->data->name,  new_node->data->name)==0 ){
        		//puts("same & update");
        		(current->next->data->totalcount)+=(new_node->data->totalcount);
        		return;
       		}
       		//puts("sd");
            current = current->next;
            
        }
       
        new_node->next = current->next;
        current->next = new_node;
    }
}


void printBNL(){
	BNL *handle=bnlhead;
	while(handle!=NULL){
		printf("%s-, total count is: %d \n",handle->data->name,handle->data->totalcount);
		handle=handle->next;
	}
}

//BUG!!! BUG!!! 
void insertInOrderBRL(BRL **brlhead, BRL *new_node){
BNL *current;
	//special head case
	if (*brlhead == NULL || ((*brlhead)->data->totalcount <new_node->data->totalcount) ){
        new_node->next = *brlhead;
        *brlhead = new_node;
        puts("sdf");
    }else{
        /* Locate the node before the point of insertion */
        current = *brlhead;
        while (current->next!=NULL && ((current->next->data->totalcount >new_node->data->totalcount)) ){
            current = current->next; 
            
        }
        
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printBRL(){
	BRL *handle=brlhead;
	int count=1;
	while(handle!=NULL){
		printf("%s-, total count is: %d \n",handle->data->name,handle->data->totalcount);
		handle->data->trank=count;
		count++;
		handle=handle->next;
	}
}

//construct BRL
void BNLtoBRLconverter(){
	BNL *handle= bnlhead;
	int count=1;
	//case head 
	if(brlhead==NULL){
		appendBRL(constructorBRL(handle->data));
	}
	
	while(handle!=NULL){
		insertInOrderBRL(&brlhead,constructorBRL(handle->data));
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
		BSTsearch(&((*root)->left), str);
	}else{
		return (*root)->data->data;
	}
}


