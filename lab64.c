// C program to implement Bubble Sort on singly linked list 
#include<stdio.h> 
#include<stdlib.h> 
  
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
void insertAtTheBegin(struct Node **start_ref, int data); 
  
struct Node * bubbleSort(struct Node *start); 
  
struct Node * swap(struct Node *,struct Node *lptr,struct Node *a, struct Node *b); 
  
void printList(struct Node *start); 
  
int main() 
{ 
    int arr[] = {12, 56, 2, 11, 1, 90}; 
    int list_size, i,data;
    /* start with empty linked list */
    struct Node *start = NULL; 
    printf("Enter size of list\n");
    scanf("%d",&list_size);
    /* Create linked list from the array arr[]. 
      Created linked list will be 1->11->2->56->12 */
    for (i = 0; i< list_size; i++) 
    {
        printf("Enter element\n");
        scanf("%d",&data);
        insertAtTheBegin(&start,data); 
    }
    /* print list before sorting */
    printf("\n Linked list before sorting "); 
    printList(start); 
  
    /* sort the linked list */
    start=bubbleSort(start); 
  
    /* print list after sorting */
    printf("\n Linked list after sorting "); 
    printList(start); 
  
    getchar(); 
    return 0; 
} 
  
void insertAtTheBegin(struct Node **start_ref, int data) 
{ 
    struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node)); 
    ptr1->data = data; 
    ptr1->next = *start_ref; 
    *start_ref = ptr1; 
} 
  
void printList(struct Node *start) 
{ 
    struct Node *temp = start; 
    printf("\n"); 
    while (temp!=NULL) 
    { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
}
struct Node* bubbleSort(struct Node *start)
{
    struct Node * endptr=NULL,*ptr,*prev,*temp;
    int flag=1;
    while(start!=endptr && flag==1)
    {
        prev=NULL;
        flag=0;
        for(ptr=start;ptr->next!=endptr;ptr=ptr->next)
        {
            
            if((ptr->data)>(ptr->next)->data)
            {
                flag=1;
                temp=ptr->next;
                start=swap(start,prev,ptr,ptr->next);
                ptr=temp;
            }
            prev=ptr;
        }
        endptr=ptr;
    }
    return start;
}

struct Node * swap(struct Node *lptr,struct Node *prev,struct Node *a, struct Node *b)
{
    if(a==lptr)
    {
        a->next=b->next;
        b->next=a;
        lptr=b;
    }
    else
    {
        a->next=b->next;
        prev->next=b;
        b->next=a;
    }
    return lptr;
}

