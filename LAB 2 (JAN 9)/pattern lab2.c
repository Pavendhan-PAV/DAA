#include<stdio.h>

void pattern(int n)
{ int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		printf("%d ",j+1);
		printf("\n");
	}
	
	
		printf("\n");
		
	
	
	
}
void pattern2(int n)
{int i,j;
	for(i=0;i<n;i++)
	{  j=i;
	while(j!=0)
{
	printf("  ");
	j--;
}
	
		for(j=i;j<n;j++)
		printf("%d ",j+1);
		
		printf("\n");
	}
	
	
}
void pattern3(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
	 for(j=0;j<i;j++)
	 printf("%d ",j+1);
	 printf("\n");
		
		
	}
	
		printf("\n");
		
		
}
void pattern4(int n)
{int i,j;
	for(i=n-1;i>=0;i--)
	{  j=i;
	while(j!=0)
{
	printf("  ");
	j--;
}
	
		for(j=i;j<=n-1;j++)
		printf("%d ",j+1);
		
		printf("\n");
	}
	printf("\n");
}
int main()
{
	printf("\n Enter n");
	int n,i,j;
	scanf("%d",&n);
		

	
	pattern(n);
	pattern2(n);
	pattern3(n);
	pattern4(n);
	return 0;
	
}
