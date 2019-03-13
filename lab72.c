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
		if(isPrime(l->data)==1)
		{
			prod = prod * l->data;
		}
		l=l->next;	
		count++;
	}
	return prod ;
}
int main()
{
	dnode * dlist_ptr = NULL;
	int n,temp,i;
	printf("Enter number of nodes :");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter data :");
		scanf("%d",&temp);
		dlist_ptr = InsertAtEnd(dlist_ptr,temp);
	}
	
	printf("prduct of prime nodes : %d",primeProd(dlist_ptr));
}
