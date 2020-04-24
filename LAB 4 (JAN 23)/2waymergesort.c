#include<stdio.h>

int arr[5]={4,8,3,7,1};

void merge(int start,int mid, int end)
{printf("start=%d,mid=%d,end=%d\n",start,mid,end);
 int at[5],k=start;
 int i=start,j=mid+1;
 while(i<=mid && j<=end)
 {
  if(arr[i]<arr[j])
  at[k++]=arr[i++];
  else 
    at[k++]=arr[j++];
 }
 
 if(i>mid)
 while(j<=end)
  at[k++]=arr[j++];
 if(j>end)
 while(i<=mid)
  at[k++]=arr[i++];
 
 for(int i=start;i<k;i++)
 {arr[i]=at[i];
 
 }
 
 
}

void ms(int start, int end)
{
 if(start<end)
 {
  int mid=(start+end)/2;
  ms(start,mid);
  ms(mid+1,end);
  merge(start,mid,end);
 }
}
void main()
{
 ms(0,4);
 for(int i=0;i<5;i++)
 printf("%d\n",arr[i]);
}
