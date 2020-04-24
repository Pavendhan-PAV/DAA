#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void binary(int a[],int n)
{ int i=0;
 while(n!=0)
 {
 	 a[i]=n%2;
 	 n/=2;
 	 i++;
 }

}

void sum(int a[],int n)
{int temp[n][n];
	int i,j,k,z;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			
			temp[i][j]=a[i]*a[j];
		}
		
	}
	int *sum=(int*)malloc(n*n*sizeof(int));
		for(k=0;k<n*n;k++)
	sum[k]=0;
	for(i=0;i<n;i++)
	{
		sum[i]=temp[0][i];
	}
	for(i=1;i<n;i++)
	{ int carry=0;
		for(j=0;j<n;j++)
		{  
		
		   z=sum[i+j];
		   
		    if(temp[i][j]+z+carry==2)
		    {
		    	sum[i+j]=0;
		    	carry=1;
		    	
			}
			else if(temp[i][j]+z+carry==3)
			{
				sum[i+j]=1;
				carry=1;
				
			}
			else
			{
				sum[i+j]=(temp[i][j]+carry+z);
				carry=0;
			
			}
			
		}if(carry==1)
		{
			sum[j+i]=1;
		}
		
		
	}
	
	int product=0;
for(i=0;i<n*n;i++)
	product+=sum[i]*pow(2,i);
	printf("\n prod=%d",product);
}
int main()
{
	int a=15;
	int x=log2(a)+1;
	

	int *a1=(int *)malloc(x*sizeof(int));
    binary(a1,a);
    sum(a1,x);
    return 0;
    
}
