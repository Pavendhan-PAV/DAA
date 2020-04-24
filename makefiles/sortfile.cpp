#include"sortfile.h"
#include<stdio.h>


void sort::bubblesort(int a[],int size)
{
	int i,j;
    for(i=0;i<size-1;i++)
	 {
	 	for(j=0;j<size-i-1;j++)
	 	{
	 		if(a[j]>a[j+1])
	 		{
	 			int temp=a[j];
	 			a[j]=a[j+1];
	 			a[j+1]=temp;
			 }
		 }
	 }
}
void sort::selectsort(int b[],int size)
{

	int i,j;

	   for( i=0;i<size-1;i++)

	   { 

	   	  for(j=i+1;j<size;j++)

	   	  {  

	   	  	if(b[i]>b[j])

	   	  	{ 

	   	  			int temp=b[j];

	 			b[j]=b[i];

	 			b[i]=temp;

	 			
				 }
	   	  	    
			 }
	   }

}
void sort::insertsort(int c[],int size)
{

	int i,j,min;

	for(i=1;i<size;i++)

	{

		  min=c[i];

		  j=i-1;

		  while(j>=0 && c[j]>min)

		  {

		  	c[j+1]=c[j];

		  	j=j-1;

		  }

		  c[j+1]=min;

	}

}

void sort::merge2(int a[],int start,int mid, int end,int size)
{

 int at[size],k=start;

 int i=start,j=mid+1;

 while(i<=mid && j<=end)

 {

  if(a[i]<a[j])

  at[k++]=a[i++];

  else 

    at[k++]=a[j++];

 }
 
 if(i>mid)

 while(j<=end)

  at[k++]=a[j++];

 if(j>end)

 while(i<=mid)

  at[k++]=a[i++];
 
 for(int i=start;i<k;i++)

 {

a[i]=at[i];
 
 }
 
 
}

void sort::mergesort2(int a[],int start,int end,int size)

{

 if(start<end)

 {

  int mid=(start+end)/2;

  mergesort2(a,start,mid,size);

  mergesort2(a,mid+1,end,size);

  merge2(a,start,mid,end,size);

 }

}

void sort::merge3(int arr[],int start,int mid1,int mid2,int end,int size)
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

void sort::mergesort3(int a[],int start,int end,int size)

{

 if(start<end)

 {

  int mid1=start+(end-start)/3;

  int mid2=start+2*((end-start)/3);

  mergesort3(a,start,mid1,size);

  mergesort3(a,mid1+1,mid2,size);

  mergesort3(a,mid2+1,end,size);

  merge3(a,start,mid1,mid2,end,size);

 }

}
int sort::swap(int *p,int *q)

{

	int temp=*p;

	*p=*q;

	*q=temp;

}
int sort::qsindex(int a[],int start,int end)
{
	int index=start-1;

	int j,pivot;

	pivot=end;

	for(j=start;j<=end-1;j++)

	{

		if(a[j]<a[pivot])

		{

index++;

		if(index!=j)

		swap(&a[index],&a[j]);

		}
		
	}

	swap(&a[index+1],&a[end]);

		return (index+1);
	
}
void sort::quicksort(int a[],int start,int end)

{   

if(start<=end)

{

int index=qsindex(a,start,end);

			quicksort(a,start,index-1);
		
			quicksort(a,index+1,end);
		

}

}
