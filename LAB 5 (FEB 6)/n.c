#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *arr[100];
int  find_min(int k)
{
	int i,min,index;
	min=(arr[0])->data;
	
	index=0;
	for(i=1;i<=k;i++)
	{
		if(arr[i]->data < min)
		{
			min=arr[i]->data;
		
			index=i;
			
		}
		
	}
		
	return index;
}
void sort(int *k)
{    
     int index=find_min(*k);
     printf("%d ",arr[index]->data);
     if(arr[index]->next==NULL)
     {
     	struct node *temp=arr[*k];  //exhaust
     	arr[*k]=arr[index];
     	arr[index]=temp;
     
     	(*k)--;
     	
	 }
	 else
     arr[index]=arr[index]->next;
}

void insert(struct node *a[],int index,int value)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
		struct node *temp2=arr[index];
		if(arr[index]==NULL)
		{
			arr[index]=temp;
		}
		else
		{
		
		while(temp2->next!=NULL)
		{
			temp2=temp2->next;
					}
		temp2->next=temp;
	}
}
void show(int k )
{
	int i;
	for(i=0;i<k;i++)
	{
			struct node *temp=arr[i];
			while(temp!=NULL)
			{
				printf("arr%d =%d of k=%d",i,temp->data,k);
				temp=temp->next;
		}
		printf("\n");
	}
	
}
int main()
{   
	int k,i,j,size=0;
	printf("\n Enter the value of k:");
	scanf("%d",&k);
	struct node *a1=(struct node*)malloc(k*sizeof(struct node));
	//int *a2=(int*)malloc(k*sizeof(int));
	for(i=0;i<k;i++)
	{   int q;
		printf("\n Enter the size of array%d:",i);
		scanf("%d",&q);
		size+=q;
		
		for(j=0;j<q;j++)
		{
			int value;
			printf("\n Enter the %d th element",j);
			scanf("%d",&value);
			insert(&a1,i,value);
		}
		
	}
	k-=1;
	
  for(i=0;i<size;i++)
  sort(&k);

	
}
