//In the spirit of preparing for the exam for the paradigm class
//This is a double linkedlist. With regular operations such as the 
//following:  
//append at the end, 
//search for int
//delete a node 
//insert after
//clear


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//this is how to typedef a linked list. llnodetag is used so that you can refer to our self in the struct to say *next.
typedef struct llnodetag{
	int data;
	struct llnodetag * next;
}llNode;

llNode *head = NULL;90
llNode *tail= NULL;


//The syntax of malloc is node = (llNode*) malloc(sizeof(llNode))  if you don't know where to put *, think about int*


llNode* constructor (int x){
	llNode *newList;
	if( ( newList = (llNode*) malloc(sizeof(llNode)) )!=NULL){
		newList->data=x;
		newList->next=NULL;
	}else{
		printf("Mem loc error\n");
		exit(0);
	}
	return newList;
}

//when think about append, always draw a graph and think about head tail and etc.
void append(llNode *p){
	if(head==NULL){
		head=p;
		tail=p;
	}else{
		tail->next=p;
		tail=p;
	}
}

void printlist(){
	llNode *handle=head;
	while(handle!=NULL){
		printf("%d\n",handle->data);
		handle=handle->next;
	}
}

//Try to make sure what happens if the search node is not here
void delete(llNode *p){
	if(head==NULL) return;
	llNode *prv, *cur;
	if((head==p)&&(tail==p)){//p is the only node in this list
		head=tail=NULL;
	}else if(p==head){ //p is the head
		head =p->next;
	}else{
		for(prv=NULL,cur=head; cur!=p; prv=cur, cur=cur->next){
			if(cur ==tail){ //very important
				printf("The node you want to delete does not exist.\n");
				return;
			}	
		}
		//cur is what you want to delete, then delete it. 
		prv->next=cur->next;
	}	
	free(p);//don't forget to free mem
}

//insert p1 after p2, here the only exception case you need to think is just tail
void insertafter(llNode *p1, llNode *p2){
	if(p2==tail){
		tail->next=p1;
		tail=p1;
	}else{
		p1->next=p2->next;
		p2->next=p1;	
	}
}

llNode *search (int x){
	llNode *handle;
	for(handle =head ; handle!=NULL; handle = handle->next){
		if(handle->data ==x) return handle;
	}
	return NULL;
}

//stare at this like crazy! You will need this sooner or later!
void clear(){
	llNode* h1, *h2;
	for(h1=head; h1!=NULL; h1 = h2){
	    h2 = h1->next;
	    free(h1);
	}
	head =tail =NULL;
}

llNode* insertbeforeit(llNode *head, int x){
	llNode *p;
	if( ( p= (llNode*)malloc(sizeof(llNode))) ==NULL ){
		puts("Error"); exit(0);
	}
	p->next= head;
	p->data=x;
	return p;
}

void insertbefore(llNode **head, int x){
	llNode *p;
	if((p=(llNode*)malloc(sizeof(llNode)))==NULL){
		puts("Error!");
		exit(0);
	}
	p->data=x;
	p->next=*head;
	*head=p;
	//printf("there\n");
}

void main(){
	llNode *node1= constructor(1);
	llNode *node2= constructor(2);
	llNode *node3= constructor(3);
	llNode *node4= constructor(4);
	llNode *node5= constructor(5);
	append(node1);
	append(node2);
	append(node3);
	append(node4);
	
	printlist();
	//search(1);
	insertbefore(&head,10);
	head= insertbeforeit(head, 20);
	printlist();
}

