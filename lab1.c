#include<stdio.h>
#include<stdlib.h>
 typedef int item;
typedef struct Node_tag
{
	item data;
	struct Node_tag *next;
}node;
void print(node *nptr)
{   if(nptr==NULL)
	{
		printf("list is empty");
	}
	while(nptr!=NULL)
	{
			printf("the data is %d \n",nptr->data);
			nptr=nptr->next;
			
		
	}
}

node* deletell(node *lptr )
{   node *nptr;
	while(lptr!=NULL)
	{
		nptr=lptr;
		lptr=lptr->next;
		free(nptr);
	}
	return nptr;
}
node *makenode(node * lptr, int d)
{       node *nptr;
       	
		nptr=(node*)malloc(sizeof(node));
		nptr->data=d;
		nptr->next=lptr;
		lptr=nptr;
	    return lptr;
	
}
node *create(node *lptr ,int size){
	int d,i;
	 for(i=0;i<size;i++)
	   {
		 printf("enter data\n");
	    scanf("%d",&d);
       lptr=makenode(lptr,d);
   }
	return lptr;
}
void main()
{
	int i=0,size,j;
	 node *lptr,*nptr;
	int data;
	lptr=NULL;
	nptr=lptr;
	printf("enter the number of the nodes");
	scanf("%d",&j);
    lptr=create(lptr,j);
	print(lptr);
    deletell(lptr);
    	printf("khatm");	
}



