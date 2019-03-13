#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}dll;

void insertAtStart(dll **head,int data)
{
    dll *temp=*head,*newNode=(dll*)malloc(sizeof(dll));
    
    newNode->data=data;
    
    if(temp!=NULL)
    {
        temp->prev=newNode;
    }
    
    newNode->prev=NULL;
    
    newNode->next=temp;
    
    *head=newNode;
}

void printdll(dll *head)//it proofs that dll is formed properly
{
    dll *temp=head;
    
    while(head!=NULL)
    {
        temp=head;
        printf("%d ",head->data);
        head=head->next;
    }
    
    printf("\n");
    
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}

void printpairs(dll *head,int num)
{
     dll *temp=head,*last,*start,*end;
     
     while(temp->next!=NULL)
     {
         temp=temp->next;
     }
     
     last=head;
     start=temp;
     //printf("%d %d \n",start->data,end->data);
     while((start!=NULL)&&(start->data<=num))
     {
         end=last;
         //printf("%d %d \n",start->data,end->data);
         while((start!=end)&&((start->data)*(end->data))>num)
         {
             end=end->next;
         }
         
         if(start->data*end->data==num)
         {
             printf("(%d %d) ",start->data,end->data);
         }
         
         start=start->prev;
     }
}

int main()
{
    int x;
    printf("Enter the Number\n");
    scanf("%d",&x);
    dll *list=NULL;
    insertAtStart(&list,1);
    insertAtStart(&list,2);
    insertAtStart(&list,3);
    insertAtStart(&list,4);
    insertAtStart(&list,5);
    insertAtStart(&list,6);
    insertAtStart(&list,8);
    //printdll(list);//similarly traverse function can be implemented
    printpairs(list,x);
}
