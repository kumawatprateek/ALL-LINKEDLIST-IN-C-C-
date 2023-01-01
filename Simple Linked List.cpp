//Code single linked list
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
//We create Some function and variable globally beacause they used many time in program 
void createlist();//Function run when we want to make LINKEDLIST first time
void insert_at_FirstNode();//during the execution, if we want to add NODE at starting of the LINKEDLIST 
void insert_at_EndNode();//and if we want to add NODE at last or Ending of the LINKEDLIST
void insert_at_After_Node_By_Name();//if we want to add NODE to The next of any particular NODE that we want
void insert_at_Before_Node_By_Name();//if we want to add NODE to The previous of any particular NODE that we want
void insert_at_After_Node_By_Index();//we can add any NODE after our choosed NODE by using INDEX to identified NODE
void insert_at_Before_Node_By_Index();//we can add any NODE before our choosed NODE by using INDEX to identified NODE
void delete_from_Start();//If we want to delete a NODE from starting of the LINKEDLIST
void delete_from_End();//If we want to delete a NODE from Ending point of the LINKEDLISt
void delete_Node_from_Anywhere_By_Name();//We can delete any NODE from this LINKEDLIST by USING STUDENT NAME
void delete_Node_from_Anywhere_By_Index();//If we Know the INDEX of any NODE in this LINKEDLIST then we can delete NODE by USING INDEX
void traverse();//This function will return remain full LINKEDLIST to us
void restore_one_last_deleted_Node();//This function will give you Last NODE that deleted by you.
//These some variable decalared as Gloable variable
struct studinfo *newnode, *ptr, *store,*restore;
char ch;
//Main function
int main()
{
	int c,nn;
	
	//crlscr
	
	start = NULL;
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
			case 1:createlist();break;
			
			case 2:insert_at_FirstNode();break;
			
			case 3:insert_at_EndNode(); break;
			
			case 4:insert_at_After_Node_By_Name();break;
			
			case 5:insert_at_Before_Node_By_Name();break;
			
			case 6: insert_at_After_Node_By_Index();break;
			
			case 7: insert_at_Before_Node_By_Index();break;
			
			case 8:delete_from_Start();break;
			
			case 9:delete_from_End();break;
			
			case 10:delete_Node_from_Anywhere_By_Name();break;
			
			case 11:delete_Node_from_Anywhere_By_Index();break;
			
			case 12: traverse();break;
			
			case 13: printf("\n\n\t......Hope you enjoy it.....");break;
			
			case 0:restore_one_last_deleted_Node();break;
			
			default: printf("\n\nPlease Enter right choice: ");
			
		}
	}while(c!=13);
	
}
//End of @main function
//Create function for the linear list until choice is 'n'
//@createlist function create a linklist and also will be stored New NODE in End of the LINKLIST
void createlist()
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
		printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
		}
		else
		{
			ptr = start;
			while (ptr -> next!=NULL)
				ptr =ptr->next;
				
			ptr->next=newnode;
			
			newnode->index=ptr->index+1;
			printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");		
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
}
//end of @createlist function
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
		store = newnode;
		newnode->index=1;
		printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
		}else
		{
			store = start;
			ptr=start;
			start = newnode;
			newnode->next = store;
			newnode->index=1;
			while(ptr->next!=NULL)
			{
				ptr->index+=1;
				ptr=ptr->next;
			}
			ptr->index+=1;
			store = newnode;
			printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
		
	}
//End of the @insert_at_FirtNode
//@insert_at_EndNode funtion will be add new NODE at end of linklist
void insert_at_EndNode()
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
		printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
		}
		else
		{
			ptr = start;
			while (ptr -> next!=NULL)
				ptr =ptr->next;
				
			ptr->next=newnode;
			newnode->index=ptr->index+1;
			printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
	}
//End of the @insert_at_EndNode
//@insert_at_After_Node_By_Name funtion will be add new NODE in somewhere between of linklist
void insert_at_After_Node_By_Name()
{
	
	
	
	char C_name[MAX];
do{
		printf("\n\nInsert Previous NODE name where you want to store next new NODE: ");
		scanf("%s",&C_name);
		
		
		if(start == NULL)
		{
		printf("\n>>>>>>Empty LIST! Atleast Enter One NODE<<<<<<");
		
		}else
		{
			ptr = start;
			int a = strcmp(ptr->name,C_name);
		
			//start = newnode;
			while(a!=0 && ptr->next!=NULL)
			{
				ptr = ptr->next;
				a = strcmp(ptr->name,C_name);
			}
			
			if(a==0)
			{
				newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
				printf("\nEnter a new record: marks and name = ");
				scanf("%d%s",&newnode -> marks,newnode->name);
				newnode -> next = NULL;
				newnode->next = ptr->next;
				ptr->next=newnode;
				newnode->index=ptr->index;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
					ptr->index+=1;
				}
				printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
				return;
			}
			
			
			printf("\n\t>>>>>>There is no available NODE to this name: %s \n",C_name);
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
	
}
//End of the @insert_at_After_Node_By_Name() function
//@insert_at_Before_Node_By_Name() will add an NODE before NODE which we want
void insert_at_Before_Node_By_Name()
{
		char C_name[MAX];
do{
		printf("\n\nInsert NEXT NODE name where you want to store new NODE: ");
		scanf("%s",&C_name);
		
		
		if(start == NULL)
		{
		printf("\n>>>>>>Empty LIST! Atleast Enter One NODE<<<<<<");
		
		}else
		{
			ptr = start;
			int a = strcmp(ptr->name,C_name);
		
			//start = newnode;
			while(a!=0 && ptr->next!=NULL)
			{
				store = ptr;
				ptr = ptr->next;
				a = strcmp(ptr->name,C_name);
			}
			
			if(a==0)
			{
				newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
				printf("\nEnter a new record: marks and name = ");
				scanf("%d%s",&newnode -> marks,newnode->name);
				newnode -> next = NULL;
				newnode->next = store->next;
				store->next=newnode;
				newnode->index=ptr->index;
				while(ptr->next!=NULL)
				{
					ptr->index+=1;
					ptr=ptr->next;
				}
				ptr->index+=1;
				printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
				return;
			}
			
			printf("\n\t>>>>>>There is no available NODE to this name: %s \n",C_name);
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
}
//End of the @insert_at_Before_Node_By_Name() funcion
//@insert_at_After_Node_By_Index() will add an NODE before NODE which we want
void insert_at_After_Node_By_Index()
{
	
	
	int ind;
do{
		printf("\n\nInsert Previous NODE INDEX where you want to store next new NODE: ");
		scanf("%d",&ind);
		
		
		if(start == NULL)
		{
		printf("\n>>>>>>Empty LIST! Atleast Enter One NODE<<<<<<");
		
		}else
		{
			ptr = start;
			
		
			//start = newnode;
			while(ptr->index!=ind && ptr->next!=NULL)
			{
				ptr = ptr->next;
				
			}
			
			if(ptr->index==ind)
			{
				newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
				printf("\nEnter a new record: marks and name = ");
				scanf("%d%s",&newnode -> marks,newnode->name);
				newnode -> next = NULL;
				newnode->next = ptr->next;
				ptr->next=newnode;
				newnode->index=ptr->index;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
					ptr->index+=1;
				}
				printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");

				return;
			}
			
			
			printf("\n\t>>>>>>There is no available NODE to this INDEX: %d \n",ind);
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
}
//End of the @insert_at_After_Node_By_Index() funcion
//@insert_at_Before_Node_By_Index() will add an NODE before NODE which we want
void insert_at_Before_Node_By_Index()
{
		int ind;
do{
		printf("\n\nInsert NEXT NODE INDEX where you want to store new NODE: ");
		scanf("%d",&ind);
		
		
		if(start == NULL)
		{
		printf("\n>>>>>>Empty LIST! Atleast Enter One NODE<<<<<<");
		
		}else
		{
			ptr = start;
			
		
			//start = newnode;
			while(ptr->index!=ind && ptr->next!=NULL)
			{
				store = ptr;
				ptr = ptr->next;
				
			}
			
			if(ptr->index==ind)
			{
				newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
				printf("\nEnter a new record: marks and name = ");
				scanf("%d%s",&newnode -> marks,newnode->name);
				newnode -> next = NULL;
				newnode->next = store->next;
				store->next=newnode;
				newnode->index=ptr->index;
				while(ptr->next!=NULL)
				{
					ptr->index+=1;
					ptr=ptr->next;
				}
				ptr->index+=1;
				printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
				return;
			}
			
			printf("\n\t>>>>>>There is no available NODE to this INDEX: %d \n",ind);
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
}
//End of the @insert_at_Before_Node_By_Index() funcion
//@delete_from_Start() will be delete a NODE from Starting point
void delete_from_Start()
{
	if(start==NULL)
	{
		printf("\n\n\t\t**** list is empty***");
		return;
	}
	restore=start;
	ptr = start;
	store = ptr->next;
	start = store;
	printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
	while(store->next!=NULL)
	{
		store->index-=1;
		store=store->next;
	}
	store->index-=1;
}
//End of the @delete_from_Start()
//@delete_from_End() Function will delete one NODE from the end of the LINKLIST
void delete_from_End()
{
	restore=start;
	ptr =start;
	if(start==NULL)
	{
		printf("\n\n\t\t**** list is empty***");
		return;
	}
	else if(ptr->next==NULL)
	{
		start=NULL;
		printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");

	}
	else
	{
		while(ptr->next!=NULL)
		{
			store=ptr;
			ptr = ptr->next;
		}
		store->next = NULL;
		printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");

	}
}
//End of the @delete_from_End()
//@delete_Node_from_Anywhere_By_Name() Function ask us that write a name of the NODE which you want to DELETE
void delete_Node_from_Anywhere_By_Name()
{
	char S_name[MAX];
	printf("\nWrite NAME of the STUDENT that you want to delete from LINKLIST: ");
	scanf("%s",&S_name);
	
	if(start == NULL)
	{
		printf("\n\n\t\t**** list is empty***");
		return;
	}
	else
	{
		restore=start;
		ptr = start;
		int a = strcmp(ptr->name,S_name);
		if(a==0)
		{
			if(ptr->next==NULL)
			{
				
				start=NULL;
				printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
				return;
			}
			ptr = start;
			store = ptr->next;
			start = store;
			
			printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
			while(store->next!=NULL)
			{
				store->index-=1;
				store=store->next;
			}
			store->index-=1;
			return;		
		}
		//start = newnode;
		while(a!=0 && ptr->next != NULL)
		{
			store = ptr;
			ptr = ptr->next;
			a = strcmp(ptr->name,S_name);
			
		}
		if(a==0)
		{
			if(ptr->next==NULL)
			{
				store->next=NULL;
				printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
				return;
			}
			store->next=ptr->next;
			printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
			while(ptr->next!=NULL)
			{
				ptr->index-=1;
				ptr=ptr->next;
			}
			ptr->index-=1;
			return;
		}
		printf("\n\t>>>>>>There is no available NODE to this name: %s \n",S_name);
		
	
			
	}
	
}
//End of @delete_Node_from_Anywhere_By_Name()
//@delete_Node_from_Anywhere_By_Index() Function ask us that write a name of the NODE which you want to DELETE
void delete_Node_from_Anywhere_By_Index()
{
	int ind;
	printf("\nWrite INDEX of the NODE that you want to delete from LINKLIST: ");
	scanf("%d",&ind);
	
	if(start == NULL)
	{
		printf("\n\n\t\t**** list is empty***");
		return;
	}
	else
	{
		restore=start;
		ptr = start;
		
		if(ptr->index==ind)
		{
			if(ptr->next==NULL)
			{
				start=NULL;
				printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
				return;
			}
			ptr = start;
			store = ptr->next;
			start = store;
			printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
			while(store->next!=NULL)
			{
				store->index-=1;
				store=store->next;
			}
			store->index-=1;
			return;		
		}
		//start = newnode;
		while(ptr->index!=ind && ptr->next != NULL)
		{
			store = ptr;
			ptr = ptr->next;
			
			
		}
		if(ptr->index==ind)
		{
			if(ptr->next==NULL)
			{
				store->next=NULL;
				printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
				return;
			}
			store->next=ptr->next;
			printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
			while(ptr->next!=NULL)
			{
				ptr->index-=1;
				ptr=ptr->next;
			}
			ptr->index-=1;
			return;
		}
		printf("\n\t>>>>>>There is no available NODE to this INDEX: %d \n",ind);
		
	
			
	}
}
//End of @delete_Node_from_Anywhere_By_Index()
//@restore_one_last_deleted_Node() function will give you LAST NODE that you delete last time
//This function can restore only one LAST NODE that Deleted 
void restore_one_last_deleted_Node()
{
	if(start==restore)
	{
		printf("\n\n\t\t\tERROR!!->> (This function can restore only one last deleted node)\n\n\t\t\t\t  Maybe you tried to restore multiple NODE\n\t\t\t\t\t\tOR\n\t\t\t\t  There is no any Deleted NODE available.");
		return;
	}
	start=restore;
	printf("\n\n\t\t\t>>>>>>>>You seccessfully restored your last Deleted NODE<<<<<<<<");
	return;
}
//End of the function @restore_one_last_deleted_Node()
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

		while(ptr != NULL)
		{
			printf("\t|Record: INDEX: %d, MARKS: %d and NAME: %s\n",ptr->index,ptr -> marks,ptr->name);
			ptr = ptr->next;
		}
		printf("\t*-----------------------------------------*\n\n\t>>>>>>>>>>>Press Enter to Continue<<<<<<<<<<<");

		getch();
	}
//End of the @traverse function
	

