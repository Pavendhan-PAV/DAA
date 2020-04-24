#include<stdio.h>
#define msize 100
struct fact
{
	int size;
	int factor[msize+1];
	int exponents[msize+1];
};
int i=1;
int j=1;
int x=1;
int a,b;
void ff(int n,struct fact *pl)
{ int i,k=1;
if(n==0)
{
	pl->factor[0]=0;
}
	for(i=2;i<=n;i++)
	{int c=0;
		 while(n%i==0)
		 {
		 	c++;
		 	n/=i;
		 	
		 }
		 if(c>0)
		 {
		 	pl->factor[k]=i;
		 	pl->exponents[k]=c;
		 	k++;
		 }
	}
	
	pl->size=k-1;
	
}
void d(int x,struct fact *sl)
{ int i;
	printf("\n Factors of %d=",x);
	for(i=0;i<=sl->size;i++)
	{
	 
	   while(sl->exponents[i]!=0)
	  	  {
			printf(" %d ",sl->factor[i]);
			(sl->exponents[i])-=1;
		}
	  
	}
}
int md1(int i,int j,struct fact *p,struct fact *q)
{  if(p->factor[0]==0 || q->factor[0]==0)
    {
    	if(p->factor[0]==0)
    	return b;
    	else
    	return a;
	}
	if(i>p->size || j>q->size)
	return x;

		if(p->factor[i]<q->factor[j])
		{ 
		md1(i+1,j,p,q);}
		else if(p->factor[i]>q->factor[j])
		{ 
		md1(i,j+1,p,q);}
		else
		{
		  int min=( (p->exponents[i])>(q->exponents[j]))?(q->exponents[j]):(p->exponents[i]);
		  x*=min*(p->factor[i]);
		  	md1(i+1,j+1,p,q);
			
			
		}
	}
int md2(struct fact *p,struct fact *q)
{  int x=1,i=0,j=0;
    if(p->factor[0]==0 || q->factor[0]==0)
    {
    	if(p->factor[0]==0)
    	return b;
    	else
    	return a;
	}
	while(i<=p->size && j<=q->size)
	{
		if(p->factor[i]<q->factor[j])
		i++;
		else if(p->factor[i]>q->factor[j])
		j++;
		else
		{
			int min=(p->exponents[i]<q->exponents[j])?(p->exponents[i]):(q->exponents[j]);
			while(min!=0)
			{
				x*=p->factor[i];
				min--;
			}
			i++;
			j++;
		}
		
		
	}
	
	return x;
	
}
	
	
	
	

int main()
{
	struct fact l1,l2,*p1,*p2;
	l1.size=l2.size=1;
	p1=&l1;
	p2=&l2;
    p1->factor[0]=1;
	p1->exponents[0]=1;
	p2->factor[0]=1;
	p2->exponents[0]=1;
	//factors
	printf("\n Enter:");
	
	
	scanf("%d %d",&a,&b);
	(a<0)?(a*=-1):(a*=1);
 (b<0)?(b*=-1):(b*=1);
 
	ff(a,p1);
	ff(b,p2);
		d(a,p1);
	d(b,p2);
	
    
   printf("\n Gcd1=%d",md1(1,1,p1,p2));
   printf("\n Gcd2=%d",md2(p1,p2));
	return 0;
	
}

