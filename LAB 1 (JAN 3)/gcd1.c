#include<stdio.h>
int gcd1(int a,int b)
{
	int i,j,max;
	(a>b)?(i=b):(i=a);
	if(a==0 || b==0)
	{
		if(a==0)
		return b;
		else
		return a;
	}
  else
{
		max=1;
	for(j=i;j>=0;j--)
	{
		if(a%j==0 && b%j==0)
		{
		return j;
	}
	}
}

}
int gcd2(int a,int i,int b)
{  if(a==0)
return b;
	if(b==0)
	return a; 
	if(b%a==0 && (a+i)%a==0)
	 return a;
	 else
	 return gcd2(a-1,i+1,b);
	
	
}
int main()
{
	printf("\n Enter");
	int a,b;
	scanf("%d %d",&a,&b);
	(a<0)?(a*=-1):(a*=1);
 (b<0)?(b*=-1):(b*=1);
	printf("\n gcd1=%d",gcd1(a,b));
	printf("\n gcd2=%d",gcd2(a,0,b));
	return 0;
}
