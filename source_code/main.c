#include "Header.h"

int main(int argc, char* argv[])
{
        LIST * a;//list for Phone Directory
        NODE * i;//node of the list
        if(!(a = ListInit())) //create the List
		{
                printf("Error! List can't be created!\n");
                return 0;
        }
	char command_add[] = "add";
	char command_del[] = "del";
    char command_find[] = "find";
    char command_exit[] = "exit";
    char command[30];
    char name[30];
    char phone[30];
  	do {
		printf ("Enter command: \n");
     	gets (command);//command from user
     	if (strcmp (command,command_add) == 0)//add item into the list
		{
			printf ("Enter name: \n");
	     	gets (name);
       		printf ("Enter phone: \n");
	     	gets (phone);
			if (ListAdd(a,name,phone,MOD_TAIL))//create a new entry in the list and enter the data
			{
				printf("'%s' with phone: '%s' added\n", name,phone);
				printf("Telephone directory:\n\n");
				ListShow(a);//show all elements of the list
			}
		}else
     	if (strcmp (command,command_del) == 0)
		{
			printf ("Enter name: \n");
	     	gets (name);
			if (ListRemove(a,name))//remove
			{
				printf("'%s' removed\n", name);
				printf("Telephone directory:\n\n");
				ListShow(a);
			}
		}else
    	if (strcmp (command,command_find) == 0)
		{
			printf ("Enter name: \n");
	     	gets (name);
			if(!(i = ListFind(a,name))) //search
			{
				printf("'%s' Not Found!\n", name);			
			}
			else printf("'%s' with phone: '%s' found\n", i->Name,i->Phone);			
		}else
        if (strcmp (command,command_exit) == 0)//exit
		{
			break;
		}
  } while (1);
return 1;
}
