// A simple C program for traversal of a linked list 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#define MIN_HEAP 4

typedef struct Alloc_tag 
{ 
int start;
int end; 
int size;
char datatype[10];
char name[20];
struct Alloc_tag *next; 
} alloc; 

typedef struct Free_tag 
{ 
int start;
int end; 
int size;
struct Free_tag *next; 
}Free; 

typedef union DT
{
	int i;
	char c;
	float f;
	double d;	
}dt;

int ind = 0;

alloc * InsertAtEndAlloc(alloc * list_ptr)
{
	alloc * nptr = (alloc *)malloc(sizeof(alloc)) , * ptr ;
	
	ptr = list_ptr ;
	
//	printf("Enter data : ") ;
//	scanf("%d" , &nptr->data) ;
	nptr->start = -1;
	nptr->end = -1;
	nptr->size = 0;
	strcpy(nptr->datatype,"");
	strcpy(nptr->name,"");
	
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

Free * InsertAtEndFree(Free * list_ptr)
{
	Free * nptr = (Free *)malloc(sizeof(Free)) , * ptr ;
	
	ptr = list_ptr ;
	
//	printf("Enter data : ") ;
//	scanf("%d" , &nptr->data) ;
	
	nptr->start = -1;
	nptr->end = -1;
	nptr->size = 0;
		
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

void Malloc(char datatype[],alloc * ptr,Free * freelist,dt heap[],int sizeofheap,int size,char name[])
{
	printf("into malloc\n");	
	if(ind + size-1 < sizeofheap)
	{
		strcpy(ptr->datatype,datatype);
		strcpy(ptr->name,name);
		ptr->start = ind;
		ptr->end = ind + size-1;
		ptr->size = size ;
	}
	else
	{
		printf("Memory Allocation not possible !!!");
		return;
	}
	
	freelist->start = ind + size;
	freelist->end = ind + (size/MIN_HEAP + 1)*MIN_HEAP - 1;
	freelist->size = (size/MIN_HEAP + 1)*MIN_HEAP - size ;
	
	ind = ind + (size/MIN_HEAP + 1)*MIN_HEAP;
}

void dataEntry(alloc * alloclist,dt heap[],int sizeofheap,int size)
{
	printf("into dataentry\n");
	int p;
	int i;
	char c;
	float f;
	double d;
	
	if(strcmp(alloclist->datatype,"int")==0)
	{
		printf("Enter %d integers : ",size);
		
		for(p=alloclist->start;p<=alloclist->end;p++)
		{
			scanf("%d",&i);
			heap[p].i = i;
		}
	}
	else if(strcmp(alloclist->datatype,"char")==0)
	{
		printf("Enter %d characters : ",size);
		
		for(p=alloclist->start;p<=alloclist->end;p++)
		{
			scanf("%c",&c);
			heap[p].c = c;
		}
	}
	else if(strcmp(alloclist->datatype,"float")==0)
	{
		printf("Enter %d floating point numbers : ",size);
		
		for(p=alloclist->start;p<=alloclist->end;p++)
		{
			scanf("%f",&f);
			heap[p].f = f;
		}
	}
	else if(strcmp(alloclist->datatype,"double")==0)
	{
		printf("Enter %d double numbers : ",size);
		
		for(p=alloclist->start;p<=alloclist->end;p++)
		{
			scanf("%lf",&heap[p].d);
			heap[p].d = d;
		}
	}
	
}
int main() 
{ 
	int sizeofheap;
	printf("\nEnter size of the simulated heap : ");
	scanf("%d",&sizeofheap);
	
	//our user defined heap
	dt heap[sizeofheap];
	
	//Free List
	Free * freelist = NULL,*ptr2=NULL;
	freelist = InsertAtEndFree(freelist);
//	freelist->start = -1;
//	freelist->end = -1;
	
	//Allocated list
	alloc * alloclist = NULL,*ptr1=NULL;
	alloclist = InsertAtEndAlloc(alloclist);
//	alloclist->start = -1;
//	alloclist->end = -1;
	
	char datatype[10],name[20];
	int query,size;
	
	do
	{
		printf("Enter query : \n1. Allocate Memory\n2. Free Memory\n");
		scanf("%d",&query);
		
		if(query==1)
		{
			
			printf("Enter name of the variable :");
			scanf("%s",name);
			
			printf("Enter data type of the variable : ");
			scanf("%s",datatype);
			
			printf("Enter number of blocks to be allocated : (Enter 1 if array of datatype is not required) ");
			scanf("%d",&size);
			
			ptr1 = alloclist;
			while(ptr1->next!=NULL)
			{
				ptr1=ptr1->next;
			}
			ptr2 = freelist;
			while(ptr2->next!=NULL)
			{
				ptr2=ptr2->next;
			}
						//alloc  //free
			Malloc(datatype,ptr1,ptr2,heap,sizeofheap,size,name);
		
			dataEntry(ptr1,heap,sizeofheap,size);
			
			ptr1 = InsertAtEndAlloc(ptr1);
			freelist = InsertAtEndFree(freelist);
			
		}
	}while(query!=-1);
	
return 0; 
}

