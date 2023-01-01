//Code for Circular linked list
#include<stdio.h>
#include<conio.h>
#include<String.h>
#include<malloc.h>
#define MAX 100

struct studinfo{
	int index;
	int marks;
	char name[MAX];
	struct studinfo *next;
}*start;
void create_LinkedList();//Function for create a LINKEDLIST and store node as end of linklist as much as we want
void insert_at_FirstNode();//during the execution, if we want to add NODE at starting of the LINKEDLIST 

void traverse();//This function will return remain full LINKEDLIST to us
//These some variable decalared as Gloable variable
struct studinfo *newnode, *ptr, *store, *last, *restore;
char ch;
//we declare main function, every task will be operate from here
main()
{
	int c;
	start=NULL;
	restore=start;
	//do-while loop run till we take a choice as 13
	//it will be exit when we choose 13
	do{
		printf("\n\n\t+--------------------------------------------------------------------------------------------------------+");
		printf("\n\t|                               >>>Enter choice for linklist operations<<<                               |");
		printf("\n\t|                                                                                                        |");
		printf("\n\t| 1. For create linklist...                       | 8.  DELETE NODE from Strating point.                 |");
		printf("\n\t| 2. For Insert NODE at First..                   | 9.  DELETE NODE from End of the LINKLIST.            |");
		printf("\n\t| 3. For Insert NODE at last..                    | 10. DELETE NODE BY NAME from LINKLIST.               |");
		printf("\n\t| 4. For Insert NODE at After any NODE By NAME    | 11. DELETE NODE BY INDEX from LINKLIST.              |");
		printf("\n\t| 5. For Insert NODE at Before any NODE By NAME   |------------------------------+-----------------------+");
		printf("\n\t| 6. For Insert NODE at After any NODE By INDEX   | 12. For Traverse LINKEDLIST..| Click 0 for restore   |");
		printf("\n\t| 7. For Insert NODE at Before any NODE By INDEX  | 13. FOR EXIT...              | One Last DELETED NODE |");
		printf("\n\t+-------------------------------------------------+------------------------------+-----------------------+");
		printf("\n\nEnter a choice that you want to do..= ");
		scanf("%d",&c);
		
		switch(c)
		{
			case 1:create_LinkedList();break;
			
			case 2:insert_at_FirstNode();break;
//			
//			case 3:insert_at_EndNode(); break;
//			
//			case 4:insert_at_After_Node_By_Name();break;
//			
//			case 5:insert_at_Before_Node_By_Name();break;
//			
//			case 6: insert_at_After_Node_By_Index();break;
//			
//			case 7: insert_at_Before_Node_By_Index();break;
//			
//			case 8:delete_from_Start();break;
//			
//			case 9:delete_from_End();break;
//			
//			case 10:delete_Node_from_Anywhere_By_Name();break;
//			
//			case 11:delete_Node_from_Anywhere_By_Index();break;
			
			case 12: traverse();break;
			
			case 13: printf("\n\n\t......Hope you enjoy it.....");break;
			
			//case 0:restore_one_last_deleted_Node();break;
			
			default: printf("\n\nPlease Enter right choice: ");
			
		}
	}while(c!=13);
	
}
//@create_LinkedList() function will create a LINKLIST and add NODE next to next continuesly
void create_LinkedList()
{
	do{
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\nEnter a new record: marks and name = ");
		scanf("%d%s",&newnode -> marks,newnode->name);
		newnode -> next = NULL;
		
		if(start == NULL)
		{
		start = newnode;
		newnode->index=1;
		newnode->next=start;
		last=newnode;
		
		printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
		}
		else
		{
			
			ptr=last;
			ptr->next=newnode;
			newnode->next=start;
			last=newnode;
				
			
			
			newnode->index=ptr->index+1;
			printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");		
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
	
}
//End of the @create_LinkedList() function
//@insert_at_FirstNode function will add new NODE at First NODE or Front of the LINKLIST
void insert_at_FirstNode()
{
		
	
	do{
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\nEnter a new record: marks and name = ");
		scanf("%d%s",&newnode -> marks,newnode->name);
		newnode -> next = NULL;
		
		if(start == NULL)
		{
		start = newnode;
		newnode->index=1;
		newnode->next=start;
		last=newnode;
		printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
		}else
		{
			
			ptr=start;
			start = newnode;
			newnode->next = ptr;
			newnode->index=1;
			last->next=start;
			while(ptr->next!=start)
			{
				ptr->index+=1;
				ptr=ptr->next;
			}
			ptr->index+=1;
			printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
		
	}
//End of the @insert_at_FirtNode
//Created function to traverse the each node of the linked list
	void traverse()
	{
		struct studinfo *ptr;
		if(start == NULL)
		{
			printf("\n\n\t\t**** list is empty***");
			return;
		}
		ptr = start;
		printf("\n\t*-----------------------------------------*\n");

		do
		{
			printf("\t|Record: INDEX: %d, MARKS: %d and NAME: %s\n",ptr->index,ptr -> marks,ptr->name);
			ptr = ptr->next;
		}while(ptr!=start);
		printf("\t*-----------------------------------------*\n\n\t>>>>>>>>>>>Press Enter to Continue<<<<<<<<<<<");

		getch();
	}
//End of the @traverse function
	