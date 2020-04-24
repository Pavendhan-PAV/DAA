#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
	
};
struct node *table[10];
void fun(int a[],int n,int p)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]+a[j]==p)
			{
				printf("\n There exists q at index %d and r at index %d for given p",i,j);
				return 0;
			}
		}
	}
	printf("\n There does not exist such element");
	
	
}
void fun1(int a[],int n,int p)
{
	int i=0,j=n-1;
	while(i<j)
	{
		if((a[i]+a[j])==p)
		{
			printf("\n There exists q at index %d and r at index %d for given p",i,j);
			return 1;
		}
		else if((a[i]+a[j])>p)
		j--;
		else
		i++;
		
	}
		printf("\n There does not exist q and r for given p");
	
}
void insert(int data)
{
	int index2=data%10;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	struct node *ptr=table[index2];
	if(ptr==NULL)
	{
		 table[index2]=temp;
	}
	else
	{
		 while(ptr->next!=NULL)
		 {
		 	ptr=ptr->next;
		 }
		 ptr->next=temp;
	}
	
	
	
	
}
int fun2(int p)
{
	int index=p%10;
	struct node *temp=table[index];
	while(temp!=NULL)
   {
   	if(temp->data==p)
   {
	   
	   	return 1;}
   	temp=temp->next;
   	
   }
   return 0;
}
void show(int n)
{int i;
	for(i=0;i<n;i++)
	{
			struct node *temp=table[i];
	while(temp!=NULL)
   {
	
		temp=temp->next;
	}
	
	
}
}
void hash(int arr[],int n,int p)
{ int i,res;
		for(i=0;i<n;i++)
	{
		insert(arr[i]);
		
	}
	show(n);
		for(i=n-1;i>=0;i--)
	{
	  res=fun2(p-arr[i]);
	  if(res==1)
	  {
	  	printf("\n Element found ");
	  	return 0;
	  }
	}

	
	printf("\n Element not found:");
	
	
}
	void SelectionSort(int a[], int size)
{
   int max, imax, temp,i,j;
   
  for( i=0; i<size-1; ++i)
  {
     max=a[0];
     imax=0;
    for( j=1; j<size-i; j++)
      if(a[j] > max)
      {
          max=a[j];
          imax=j;
      }

       temp=a[imax];
       a[imax]=a[size-i-1];
       a[size-i-1]=temp;    
     //swap a[imax] with a[size-i-1];
 
  }
}
int main()
{
	printf("\n Enter no of array elements:");
	int n,i;
	scanf("%d",&n);
		int *arr=(int *)malloc(n*sizeof(int));
	printf("\n Enter array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		
		
	}
SelectionSort(arr, n);
		printf("\n Enter p:");
		int p;
		scanf("%d",&p);
		fun1(arr,n,p);
		fun(arr,n,p);
	hash(arr,n,p);
		return 0;
	
	
}
