#include<stdio.h>

int arr[11]={1,4,13,7,2,0,-1,18,0,8,5};


void merge(int start,int mid1,int mid2, int end)
{
int i=start,j=mid1+1,k=mid2+1,l=start;
int a[11];
while(i<=mid1 && j<=mid2 && k<=end)
{ 
 if(arr[i]<arr[j] && arr[i]<arr[k])
 a[l++]=arr[i++];
 else if(arr[j]<arr[i] && arr[j]<arr[k])
 a[l++]=arr[j++];
 else
 a[l++]=arr[k++];
 }
 
 if(i>mid1) //1
 {
  while(j<=mid2 && k<=end)
  {
   if(arr[j]<arr[k])
   a[l++]=arr[j++];
   else 
    a[l++]=arr[k++];
  }
 
  if(j>mid2)
  while(k<=end)
   a[l++]=arr[k++];
  if(k>end)
  while(j<=mid2)
   a[l++]=arr[j++];
 }
 
 if(j>mid2) //2
 {
   while(i<=mid1 && k<=end)
  {
   if(arr[i]<arr[k])
   a[l++]=arr[i++];
   else 
    a[l++]=arr[k++];
  }
 
  if(i>mid1)
  while(k<=end)
   a[l++]=arr[k++];
  if(k>end)
  while(i<=mid1)
   a[l++]=arr[i++];
}

 if(k>end) //3
 {
  while(j<=mid2 && i<=mid1)
  {
   if(arr[j]<arr[i])
   a[l++]=arr[j++];
   else 
    a[l++]=arr[i++];
  }
 
  if(j>mid2)
  while(i<=mid1)
   a[l++]=arr[i++];
  if(i>mid1)
  while(j<=mid2)
   a[l++]=arr[j++];
 }
 int p;
 for( p=start;p<l;p++)
 arr[p]=a[p];
}

void ms(int start, int end)
{
 if(start<end)
 {
  int mid1=start+(end-start)/3;
  int mid2=start+2*((end-start)/3);
  ms(start,mid1);
  ms(mid1+1,mid2);
  ms(mid2+1,end);
  merge(start,mid1,mid2,end);
 }
}




void main()
{int i;
 ms(0,10);
 for(i=0;i<11;i++)
 printf("%d\n",arr[i]);
}
