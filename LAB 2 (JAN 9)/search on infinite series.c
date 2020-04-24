#include<stdio.h>
void search1(int a[])
{ if(a[0]==-1)
{
	printf("\n Element found at index 0");
}
else
{
int i=1;
	while(a[i]!=-1 && a[i-1]>0)
	{
		i++;
	}
	printf("\n Element found at index %d",i);
}

}
void bs(int start,int end,int a[])
{

	while(start<=end)
	{	int mid=(start+end)/2;
		if(a[mid]==-1 && a[mid-1]>0)
		{
		printf("\n Element found at index %d",mid);
		return 0;
	}
		else if(a[mid]>0)
		{
			start=mid+1;
		
		}
		else
		{
		end=mid-1;	
	}
		
	}
}
void search2(int a[])
{
	int i=0,j=100;
	if(a[0]==-1)
	printf("\n Element found at index 0");
	else{
	
	while(a[j]!=-1 && j<=300)
	{  
	
			i=j;
			j=j+100;
		
	}
	
	bs(i,j,a);
	
}
}
void search3(int a[])
{
	int i=0,j=2;
	if(a[0]==-1)
	printf("\n Element found at index 0");
	else{
	
	while(a[j]!=-1 && j<=300)
	{  
	
			i=j;
			j*=2;
		
	}
	
	bs(i,j,a);
	
}
}
int main()
{
	int a[10000];
	int ch=0,i=0;
	/*while(ch==0)
	{
		printf("\n Enter array element:");
		scanf("%d",&a[i]);
		i++;
		printf("\n More elements ,enter 0 else 1");
		scanf("%d",&ch);
	}*/
	for(i=0;i<182;i++)
	{
		a[i]=i+1;
	}
	for(i=182;i<300;i++)
	{
		a[i]=-1;
	}
	search1(a);
	search2(a);
	search3(a);
	return 0;
	
}
