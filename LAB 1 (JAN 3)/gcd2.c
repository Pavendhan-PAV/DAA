#include<stdio.h>
#include<stdlib.h>
int gcd1(int a,int b)
{   if(a==0)
return b;
	if(b==0)
	return a;
	else
	return gcd1(b%a,a);
}
int gcd2(int a,int b)
{  (a<0)?(a*=-1):(a*=1);
 (b<0)?(b*=-1):(b*=1);
 if(a==0)
 return b;
 if(b==0)
 return a;
 
 
	while(a!=b && a!=0 && b!=0)
	{
		if(a>b)
		a-=b;
		else
		b-=a;
	}
return a;
	
	
	
}
int multigcd(int size,int *a)
{
	if(size==0)
	return 0;
	
	
	int res=multigcd(size-1,a+1);
	res=gcd1(a[0],res);
	return res;
}
int main()
{   	int n,res,i;
	printf("\n Enter no of digits:");
	scanf("%d",&n);
int *a=(int *)malloc(n*sizeof(int));

printf("\n Enter n digits:");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
	res=gcd1(res,a[i]);
}
    printf("\n Gcd1=%d",res);
	printf("\n gcd2=%d",multigcd(n,a));
	return 0;
}
