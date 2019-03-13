#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef char item;
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
	item ch[20],str[20];
	initialise(&stack);
	int i;
	printf("enter the string");
    scanf("%s",ch);
    for(i=0;i<strlen(ch);i++)
    {
	
	   sc=push(&stack,ch[i]);
    } 

    for(i=0;i<strlen(ch);i++)
    {
	
	 sc=pop(&stack,&str[i]);
	 
    }
    if(strcmp(ch,str)==0)
    {
    	printf("given string %s is pellindrome",ch);
    	
	}
	else
	printf("striing is not pellindrome");
	
}

void initialise(stck *stck_ptr)
{
	stck_ptr->top= NULL;
}	 

