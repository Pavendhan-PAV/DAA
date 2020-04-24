//split even sized array into two parts with minimum diff in sum using combinations

#include <stdio.h>
#include<stdlib.h>
int diff=+2147483647;
struct set{
	
	int arr[100];
	int index[100];
	int data[50];
	int sum;
	int result[50];
};

void split(struct set* a,int start,int end,int low,int high)
{
	if(low==high)
	{
		int y=0;
		for(int i=0;i<high;i++)
		{
			y=y+a->arr[a->data[i]];
		}
		int z=a->sum-y;
		if(z<diff)
		{
				for(int i=0;i<high;i++)
		{
			a->result[i]=a->data[i];
		}
	    }
		
	}
	for(int i=start;i<=end&&end-i+1>=high-low;i++)
	{
		a->data[low]=a->index[i];
		split(a,i+1,end,low+1,high);
	}
}

int main()
{
	int n;
 struct set* a=(struct set*)malloc(sizeof(struct set));
	printf("enter the size of array :\n");
	scanf("%d",&n);a->sum=0;
	printf("enter elements :\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a->arr[i]);
		a->index[i]=i;
		a->sum=a->sum+a->arr[i];
	}
	
	split(a,0,n-1,0,n/2);
	printf("\n set 1 : ");
	for(int i=0;i<n/2;i++)
	{
		printf(" %d ",a->arr[a->result[i]]);
		a->index[a->result[i]]=-1;
	}
	printf("\n set 2 : ");
		for(int i=0;i<n;i++)
	{
		if(a->index[i]!=-1)
		{
		
		printf(" %d ",a->arr[i]);
	}

	}
	
}
