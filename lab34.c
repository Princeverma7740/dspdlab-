#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef int  item;
 
typedef enum {FAILURE,SUCCESS} status_code ;
typedef struct node_tag
         {
         	item data;
            struct node_tag *next;
        
		 }node;
		 
typedef struct queue_tag
{  node *rear;
   node *front;
 }queue;
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

 queue *initialise(queue **qptr )
 {
 	queue *temp=*qptr;
 	
 	temp->front=temp->rear=NULL;
 	return temp;
 }
 status_code insertq(queue **qptr, item d)
 {
 	queue *temp=*qptr;
 	status_code sc=SUCCESS;
 	node *nptr;
 	nptr=makenode(d);
 	if(nptr==NULL)
 	{
 		 sc=FAILURE;
 		 
	}
	else
	{
		if(qptr==NULL)
		{
			temp->front=temp->rear=nptr;
		}
		else
		{
			(temp->rear)->next=nptr;
			temp->rear=nptr;
		}
	}
	
 	return sc;
 }
 status_code deleteq(queue * qptr, int *dptr)
 {
 	status_code sc=SUCCESS;
 	node *nptr;
 	
 	if(qptr==NULL)
 	{
 		 sc=FAILURE;
 		 
	}
	else
	{
		nptr=qptr->front;
		qptr->front=(qptr->front)->next;
		*dptr=nptr->data;
		free(nptr);
		if(qptr->front==NULL)
		{
			qptr->rear=NULL;
		}
	}
   return sc;
}

void main()
{   status_code sc;
    int d;
	queue *qptr;
	
	qptr=initialise(&qptr);
	insertq(&qptr,20);
	insertq(&qptr,22);
	insertq(&qptr,25);
	insertq(&qptr,24);
	insertq(&qptr,23);
	printf("%d %d",qptr->front->data,qptr->rear->data);
	/*while(qptr->front!=NULL)
	{
		printf("%d",qptr->front->data);
		qptr->front=qptr->front->next;
	}*/
}
