#include <stdio.h>
#include <stdlib.h>

typedef struct dnodes{
	int data ;
	struct dnodes *next;
	struct dnodes *prev;
}dnode;

dnode * InsertAtEnd(dnode * list_ptr,int temp)
{
	dnode * d = (dnode *)malloc(sizeof(dnode));
	if(list_ptr==NULL)
	{	
		list_ptr = d ;
		d->data = temp;
		d->next = NULL;
		d -> prev = NULL;
	}
	else
	{
		dnode * p = list_ptr;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next = d;
		d->data=temp;
		d->prev = p;
		d->next = NULL;
	}
	return list_ptr ;
}

int isPrime(int count)
{
	if(count==1)
	return 0;
	if(count==2||count==3)
	return 1;
	else
	{
		int i,flag=0 ; 
		for(i=2;i<=count/2&&flag==0;i++)
		{
			if(count%i==0)
			return 0;
		}
		
		return 1;
	}
}

int primeProd(dnode * list_ptr)
{
	int count=1;
	int prod = 1;
	dnode * l = list_ptr;
	
	if(list_ptr==NULL)
	return 0;
	
	while(l!=NULL)
	{
		if(isPrime(count)==1)
		{
			prod = prod * l->data;
		}
		l=l->next;	
		count++;
	}
	return prod ;
}

int Common(dnode * dlist_ptr,dnode * dlist_ptr2)
{
	int i,j,common=0;
	dnode * p1 = dlist_ptr;
	dnode * p2 = dlist_ptr2;
	while(p1!=NULL)
	{
		p2 = dlist_ptr2;
		while(p2!=NULL)
		{
			if(p1->data==p2->data)
			{
				common++;
				break;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	
	return common;
}
int main()
{
	dnode * dlist_ptr = NULL;
	int n,temp,i,n2;
	printf("Enter number of nodes :");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter data :");
		scanf("%d",&temp);
		dlist_ptr = InsertAtEnd(dlist_ptr,temp);
	}
	
	dnode * dlist_ptr2 = NULL;
	printf("Enter number of nodes :");
	scanf("%d",&n2);
	
	for(i=0;i<n2;i++)
	{
		printf("Enter data :");
		scanf("%d",&temp);
		dlist_ptr2 = InsertAtEnd(dlist_ptr2,temp);
	}
	printf("The common elements are : %d",Common(dlist_ptr,dlist_ptr2));
}
