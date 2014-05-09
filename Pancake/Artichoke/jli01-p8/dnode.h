#ifndef THIS_ONE
#define THIS_ONE

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

//Singly linked list 
struct tagA{
	DNode *data;
	struct tagA *next;
};
typedef struct tagA NL;

//Tree
struct TNode{
    NL *data;
    struct TNode* left;
    struct TNode* right;
};
typedef struct TNode BNT;

//different lists used 
NL *brlhead ;
NL *brltail;
NL *grlhead ;
NL *grltail;
NL *bnlhead ;
NL *bnltail;
NL *gnlhead ;
NL *gnltail;

int searchRank(NL *head, int num);


void insertInOrderRL(NL **head, NL *new_node);
void rankRL(NL *head);


void NLtoRLconverter(NL *head, NL **anotherhead);


BNT* constructorTree(NL *data);

NL* constructorNL (DNode *data);
NL* isInList(NL *head, char *name);
void printNL(NL *head);
int countLNodes(NL *head);

DNode* DNodeConstructor(YearNode *aNode, int boynum, char *boyname);
YearNode* YearNodeConstructor(int year, int localrank, int boynum);

DNode* BSTsearch(BNT ** root, char *str);
BNT* sortedListToBSTRecur(NL **head, int n);
BNT* sortedListToBST(NL *head);

void sortedInsertNL(NL **head, int year, int  localrank, int boynum, char *boyname);

#endif 

