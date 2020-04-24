#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *nptr;
};
int push(struct node **a,int x);
void printll(struct node *l);
int print(int a[][2],int size);
int swap(int *a,int *b);


int main()
{
	int n;
	printf("\nEnter no of integers:\n");
	scanf("%d",&n);
	int a[n][2];
	for(int i=0;i<n;i++)
	{
		a[i][1]=i;
		scanf("%d",&a[i][0]);
	}
	print(a,n);
}


int print(int a[][2],int size)
{
	int count=0;
	int i=0,j=size-1,length=size,lench=size-1;
	struct node* array[size];
	for(int tre=0;tre<size;tre++)
	{
		array[tre]=NULL;
	}
	
	while(i<j)
		{
			count++;
		
			if(a[j][0]<a[i][0])
			{
				if(i!=j)
		{
				push(&array[a[j][1]],a[i][0]);}
		
			swap(&a[j][0],&a[i][0]);
			swap(&a[j][1],&a[i][1]);
		    
	    	}
	    	else
	    	{
	    	if(i!=j)
	    	push(&array[a[i][1]],a[j][0]);	
			}
			i++;j--;
			if(j==lench/2)
			{
				i=0;
				j=lench/2;
				lench=lench/2;
			}
		
		}
		for(int t=0;t<size;t++)
		printf(" %d ",a[t][0]);

	struct node* temp=array[a[0][1]];
	int min2=array[a[0][1]]->data;
 temp=temp->nptr;
	while(temp!=NULL)
	{
		count++;
		if(min2==a[0][0])
		{
			min2=temp->data;
			
		}
	
		if((temp->data!=a[0][0])&&(temp->data<min2))
		{
		min2=temp->data;
		}
		temp=temp->nptr;
		
	}
	printf("\nMin 1: %d\nMin 2: %d  \n",a[0][0],min2);

	
}
void printll(struct node *l)
{  
    printf(" list is\n");
    while(l!=NULL)
    {
        printf("%d->",l->data);
        l=l->nptr;
    }
    printf(" \n");
}
int push(struct node **a,int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->nptr=NULL;
	temp->nptr=*a;
	*a=temp;
}
int swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
