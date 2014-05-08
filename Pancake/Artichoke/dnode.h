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


struct tagA{
	DNode *data;
	struct tagA *next;
};
typedef struct tagA BNL;

struct tagB{
	DNode *data;
	struct tagA *next;
};
typedef struct tagA BRL;

struct TNode{
    BNL *data;
    struct TNode* left;
    struct TNode* right;
};
typedef struct TNode BNT;


BRL *brlhead ;
BRL *brltail;
BRL *grlhead ;
BRL *grltail;
BNL *bnlhead ;
BNL *bnltail;
BNL *gnlhead ;
BNL *gnltail;

int searchRank(BRL *brlhead, int num);
BRL* constructorBRL (DNode *data);
void appendBRL(BRL *p);
void insertInOrderBRL(BRL **brlhead, BRL *new_node);
void rankBRL(BRL *brlhead);


void BNLtoBRLconverter(BNL *bnlhead, BRL **brlhead);


BNT* constructorTree(BNL *data);
void inOrdTreeTrans(BNT* node);
BNL* constructorBNL (DNode *data);
BNL* isInList(BNL *bnlhead, char *name);
void printBNL(BNL *bnlhead);
int countLNodes(BNL *bnlhead);

DNode* DNodeConstructor(YearNode *aNode, int boynum, char *boyname);
YearNode* YearNodeConstructor(int year, int localrank, int boynum);

DNode* BSTsearch(BNT ** root, char *str);
BNT* sortedListToBSTRecur(BNL **head_ref, int n);
BNT* sortedListToBST(BNL *bnlhead);

void sortedInsertBNL(BNL **bnlhead, int year, int  localrank, int boynum, char *boyname);

#endif 

