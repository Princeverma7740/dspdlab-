 #include<stdio.h>
 #include<stdlib.h>
 typedef struct dl_node_tag{
 		 
 		 int data;
 		 struct dl_node_tag *prev;
 		struct dl_node_tag *next;
 } dl_node;
  dl_node *createlist(int n);
  dl_node *divide(dl_node *lptr, int k);
  void display(dl_node *lptr);
 int main()
 {
 	int n,k;
 	dl_node *lptr;
 	lptr = NULL;
 	printf("enter no. of node : ");
 	scanf("%d",&n);
 		
    printf("enter no. k : ");
 	scanf("%d",&k);
 	
 	lptr = createlist(n);
 	printf("Initial list : \n");
 	display(lptr);
 	printf("\n");
 	if(k == 0)
 	{
 		printf("not defined : ");
	 }
 	else
	 {
	 lptr = divide(lptr,k);
	 printf("Final truncated list : \n");
	display(lptr);
	}
	return 0;
 }
 
 dl_node *createlist(int n)
 {
 	dl_node *nptr, *lptr, *temp;
 	int i, data;
 	lptr = NULL;
 	for(i=0;i<n;i++)
 	{
 		nptr = (dl_node*)malloc(sizeof(dl_node));
 		printf("enter data");
 		scanf("%d",&data);
 		nptr->data = data;
 		nptr->prev = NULL;
 		nptr->next = NULL;
 		
 		if(lptr == NULL)
 		{
 			lptr = nptr;
		 }
		else
		{
			 temp = lptr;
			 while(temp->next!=NULL)
			 {
			 	temp = temp->next;
			 }
			temp->next = nptr;
			nptr->prev = temp;
		}
	 }
	 return lptr;
 }
 
 
 void display(dl_node *lptr)
 {
 	dl_node *temp;
 	temp = lptr;
 	while(temp!=NULL)
 	{
	 
 	printf("%d\t",temp->data);
 	temp = temp->next;
   }
 }
dl_node *divide(dl_node *lptr, int k)
{
	dl_node *nptr, *temp,*temp1;
	nptr = lptr;
	temp = NULL;
	while(nptr!=NULL)
	{		
	
		if(nptr==lptr)
		{
			if((nptr->data)%k==0)
			{
				lptr=lptr->next;
				lptr->prev=NULL;
				temp=nptr;
				nptr=lptr;
				free(temp);
			}
			else
			{
				nptr=nptr->next;
				
			}
		}
		else
		{
			if((nptr->data)%k==0)
			{
				temp=nptr;
				temp1=nptr->next;
				(nptr->prev)->next=nptr->next;
				
				if(nptr->next!=NULL)
				{
				
					(nptr->next)->prev=nptr->prev;
					
				}
				
				free(temp);
				nptr=temp1;				
			}
			else
			{
				nptr=nptr->next;
			}
		}
		
	} 
	return lptr;

}

