// A simple C program for traversal of a linked list 
#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node_tag 
{ 
int data; 
struct Node_tag *next; 
} node; 


node * InsertAtStart(node *list_ptr)
{
	node *nptr ;
	
	nptr = (node *)malloc(sizeof(node)) ;
	
	printf("Enter data : ") ;
	scanf("%d" , &nptr->data) ;
	
	nptr->next = list_ptr ;
	list_ptr = nptr ;
	
	return list_ptr ;
}

node * InsertAtEnd(node * list_ptr)
{
	node * nptr = (node *)malloc(sizeof(node)) , * ptr ;
	
	ptr = list_ptr ;
	
	printf("Enter data : ") ;
	scanf("%d" , &nptr->data) ;
	
	
	if(list_ptr == NULL)
	{
		list_ptr = nptr ;
		list_ptr->next = NULL;
		
		return list_ptr ;
	}
	else
	{
		
		while(ptr->next  != NULL)
		ptr = ptr->next ;
	
		ptr->next = nptr ;
		nptr->next = NULL ;
	}
	
	return list_ptr;
}







node * CreateLinkedList(node *list_ptr )
{
	
	
	int option ,i ,num;
	int j;
	
	printf("Do you want to create a list : (1/0)");
	scanf("%d",&i) ;
	
	if(i)
	{
		printf("enter no. of elements to be added : ") ;
	scanf("%d",&num );
	
	for(j=0;j<num;j++)
	list_ptr = InsertAtStart(list_ptr) ;
	}
	else
	{
		printf("Enter option for 0 for end  and 1 for start  : ") ;
		scanf("%d" , &option) ;
	
	
	
		if(option)
		{
		
			{
				list_ptr = InsertAtStart(list_ptr) ;
			}
		
		}
		else
		{
		
			{
				list_ptr = InsertAtEnd(list_ptr) ;
			}
		}
	}
	
	return list_ptr ;
	
}

// This function prints contents of linked list 00000starting from 
// the given node 0
void printList( node * n) 
{ 
	while (n != NULL) 
	{ 
		printf(" %d ", n->data); 
		n = n->next; 
	} 
} 


node * DeleteFromStart(node * list_ptr)
{
	node * nptr ;
	
	nptr = list_ptr ;
	list_ptr = list_ptr->next ;
	
	free(nptr) ;
	
	return list_ptr ;
}

node * DeleteFromEnd(node * list_ptr)
{
	//node * nptr = (node *)malloc(sizeof(node)) ;
	node *ptr1 , *ptr2 ;
	
	ptr1 = list_ptr ;
	ptr2 = list_ptr ;
	
	if(ptr1->next == NULL)
	{
		list_ptr = NULL ;
		free(ptr1) ;
	}
	else
	{
		while(ptr1->next != NULL)
		{
			ptr1 = ptr1->next ;
			 if(ptr1->next != NULL)
			 {
	 			ptr2 = ptr2->next ;
			 }	
		}
		
		ptr2->next = NULL ;
		free(ptr1) ;
	}
	

	return list_ptr ;	
}

void DeleteList(node *list_ptr )
{
	int option ;
	printf("Press 1 to delete from start and 0 to delete from end : ") ;
	scanf("%d", &option) ;
	
	/*int num , i;
	printf("Enter no. of elements to be deleted : ") ;
	scanf("%d" , &num) ;*/
	
		if(list_ptr != NULL)
		{
			if(option)
			{
	
				list_ptr = DeleteFromStart(list_ptr) ;
			}
			else
			{
				list_ptr = DeleteFromEnd(list_ptr) ;
		
			}
		}

}




int main() 
{ 
 
 node * list_ptr  = NULL ;
 int n;
 //printf("Enter the number of nodes to be inserted : ") ;
 //	scanf("%d",&num) ;
 
 do{
 
 scanf("%d" , &n) ;
 
 if(n == 1)
 list_ptr = CreateLinkedList(list_ptr) ;
 
 else if(n == 2)
 printList(list_ptr) ;

 /*int c ;
 printf("Do you wnat to delete the linked list : (1/0)") ;	
 scanf("%d", &c) ;*/
 
 else if(n == 3)
 DeleteList(list_ptr) ;
 
 /*else
 printf("The list is still allocated") ;

 printList(list_ptr) ;*/
 
 }while(n != 10) ;	 

return 0; 
}

