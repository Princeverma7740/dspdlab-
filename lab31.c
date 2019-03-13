#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef int item;
typedef struct node_tag
         {
         	item data;
            struct node_tag *next;
        
		 }node;
typedef struct stack_tag
        {
        	node *top;
		}stck;
			 
typedef enum {FAILURE,SUCCESS} status_code;
void initialise(stck * stck_ptr);
node *makenode(item d)
{
	node *nptr;
	nptr=(node*)malloc(sizeof(node));
	if(nptr!= NULL)
	{
		nptr->data=d;
		nptr->next=NULL;
		
	} return nptr;
}

status_code push(stck *sptr,item d)
{
	node *nptr;
	status_code ret_val=SUCCESS;
	nptr=makenode(d);
	if(nptr==NULL)
	{
		ret_val=FAILURE;
	}
	else
	{
		nptr->next=sptr->top;
		sptr->top=nptr;
	}
	return ret_val;
	
}
status_code pop(stck *sptr,item *dptr)
{
	node *ptr;
	status_code ret_val=SUCCESS;
	if(sptr->top==NULL)
	{
		ret_val=FAILURE;
	}
	else
	{
		ptr=sptr->top;
		sptr->top=(sptr->top)->next;
		*dptr=ptr->data;
		free(ptr);
	}
	return ret_val;
}

void main()	
{  

    status_code sc;
    stck stack;
	item d;
		initialise(&stack);
	sc=push(&stack,10);
	sc=push(&stack,20);
	sc=push(&stack,30);
	sc=push(&stack,140);
	sc=push(&stack,15);
	int i;
    for(i=0;i<5;i++)
    {
	
	 sc=pop(&stack,&d);
	 printf("\n%d",d);    }








	
}

void initialise(stck *stck_ptr)
{
	stck_ptr->top= NULL;
}	 

