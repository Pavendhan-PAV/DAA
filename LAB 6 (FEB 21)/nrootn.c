#include<stdio.h>
#include<stdlib.h>

void main()
{
 int n;
 printf("\nEnter the value of n: ");
 scanf("%d",&n);
 
 int u[n];
    
 for(int i=2;i*i<=n;i++)
 {
  for(int l=0;l<n;l++)
  u[l]=1;
  for(int j=0;j<n;j++)
  {
   if((j+1)%i==0)
   u[j]=(int)'$';
   if(j==n-1)
   {
    if(u[j]==(int)'$')
    printf("\nn is divisible by %d",i);
    else
    printf("\nn is not divisible by %d",i);
   }
  }
 }
} 
