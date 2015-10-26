#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MOD_HEAD 0
#define MOD_TAIL 1
#define NAME_SIZE 30
#define PHONE_SIZE 30

typedef struct Node {//node of a list
        char Name[NAME_SIZE];
        char Phone[PHONE_SIZE];
	
        struct Node * Prev;
        struct Node * Next;
} NODE;

typedef struct {//list
        NODE * Head;
        NODE * Tail;
        unsigned int Length;
} LIST;

LIST * ListInit();//create a list
int ListAdd(LIST *, char*, char*, int);//add element
void ListShow(LIST *);//display elements
int ListRemove(LIST *, char*);//remove element
NODE * ListFind(LIST *, char *);//search element
int ListFind_For_Remove(LIST *, char *);//search node by name for remove number