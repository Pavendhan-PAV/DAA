#include<stdio.h>
#include<stdlib.h>
struct node
{
	int min;
	int max;
};

struct node *find(int a[],int n)
{  int i;
 struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(n%2!=0)
    {
    	temp->min=temp->max=a[0];
    	i=1;
	}
	else
	{
		if(a[0]>a[1])
		{
			temp->min=a[1];
			temp->max=a[0];
			}
		else
		{
				temp->min=a[0];
			temp->max=a[1];
			
		}
		i=2;
	}
	
	while(i<n-1)
	{
		if(a[i]>a[i+1])
		{
			if(temp->max<a[i])
			temp->max=a[i];
			if(temp->min>a[i+1])
			temp->min=a[i+1];
		}
		else
		{
				if(temp->max<a[i+1])
			temp->max=a[i+1];
			if(temp->min>a[i])
			temp->min=a[i];
			
			
		}
		
	i+=2;
	}
	return temp;
}
int main()
{
	int a[9]={0,1,1,1,-1,-1,0,1,5};
	struct node *temp=find(a,9);
	printf("\nmin=%d max=%d",temp->min,temp->max);
	return 0;
}
