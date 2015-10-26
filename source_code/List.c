#include "Header.h"

LIST * ListInit(){
        LIST * tmp = (LIST *) malloc(sizeof(LIST));
        if(!tmp) return NULL;
        else{
                tmp->Head = NULL;
                tmp->Tail = NULL;
                tmp->Length = 0;
                return tmp;
        }
}

int ListAdd(LIST * ptr, char * name, char * phone,int mode){
NODE * tmp = (NODE *) malloc(sizeof(NODE));
if(!tmp) return 0;
else {
		strncpy(tmp->Name,name,NAME_SIZE);
		strncpy(tmp->Phone,phone,PHONE_SIZE);
        tmp->Prev = NULL;
        tmp->Next = NULL;

        switch(mode){
        case MOD_HEAD:
                if(ptr->Head){
                        tmp->Next = ptr->Head;
                        ptr->Head->Prev = tmp;
                        ptr->Head = tmp;
                }
                else {
                        ptr->Head = ptr->Tail = tmp;
                }
                break;
        case MOD_TAIL:
                if(ptr->Tail){
                        tmp->Prev = ptr->Tail;
                        ptr->Tail->Next = tmp;
                        ptr->Tail = tmp;
                }
                else {
                        ptr->Head = ptr->Tail = tmp;
                }
                break;
     }
}
ptr->Length++;
return 1;
}


void ListShow(LIST * ptr){
NODE * i;
int c = 1;
if(!ptr->Length) return;
for(i = ptr->Head; i; i = i->Next, c++) {
        printf("Name:%s ",i->Name);
		printf(" Phone:%s\n\n",i->Phone);
}
}

int ListRemove(LIST * ptr, char * name){
NODE * tmp, * c;
unsigned int i;
int num = 0;

num = ListFind_For_Remove(ptr,name);	
if((num > ptr->Length) || (num == 0)) return 0;
else {
        if(num == 1){
                tmp = ptr->Head;
                ptr->Head = ptr->Head->Next;
                ptr->Length--;
                free(tmp);
                return 1;
        }
        else if(num == ptr->Length){
                for(tmp = ptr->Head; tmp->Next->Next; tmp = tmp->Next);
                c = tmp->Next;
                tmp->Next = NULL;
                free(c);
                ptr->Length--;
                return 1;
        }
        else {
                for(i = 1, tmp = ptr->Head; i < --num; i++) tmp = tmp->Next;
                c = tmp->Next;
                tmp->Next = tmp->Next->Next;
                free(c);
                ptr->Length--;
                return 1;
        }
}
}

NODE * ListFind(LIST * ptr, char * name){
NODE * tmp, * result = NULL;
for(tmp = ptr->Head; tmp; tmp = tmp->Next) {
		if(strcmp(tmp->Name, name) == 0) {
                result = tmp;
                break;
        }
}
return  result;
}

int ListFind_For_Remove(LIST * ptr, char * name){
NODE * tmp, * result = NULL;
int i = 1;
for(tmp = ptr->Head; tmp; tmp = tmp->Next) {		if(strcmp(tmp->Name, name) == 0) {
                result = i;
                break;
        }
	i++;
}
return  result;
}