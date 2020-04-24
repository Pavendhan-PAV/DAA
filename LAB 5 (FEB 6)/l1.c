#include<stdio.h>

int ares[1000];

void merge(int start,int mid, int end)
{
 printf("start=%d,mid=%d,end=%d\n",start,mid,end);
 int at[end],k=start;
 int i=start,j=mid+1;
 while(i<=mid && j<=end)
 {
  if(ares[i]<ares[j])
  at[k++]=ares[i++];
  else 
    at[k++]=ares[j++];
 }
 
 if(i>mid)
 while(j<=end)
  at[k++]=ares[j++];
 if(j>end)
 while(i<=mid)
  at[k++]=ares[i++];
 
 for(int i=start;i<k;i++)
 {ares[i]=at[i];
 
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
 int k,s[1000],a[1000][1000];
 printf("Enter how may sorted arrays you want to enter: ");
 scanf("%d",&k);
 
 for(int i=0;i<k;i++)
 {
  printf("\nEnter size of array %d: \n",i+1);
  scanf("%d",&s[i]);
  for(int j=0;j<s[i];j++)
  {
  printf("Element %d: ",j+1);
  scanf("%d",&a[i][j]);
 }
 }
 int l=0,end=0;
 for(int i=0;i<k;i++)
 {
  end=s[i]+end;
  for(int j=0;j<s[i];j++)
  {
   ares[l++]=a[i][j];
   printf("\t\t%d\n",end);
  }
  if(i>=1)
   ms(0,end-1);
 }
  /*printf("\t\t\t\n%d\n",end);
  for(int j=0;j<k;j++)
  {
  printf("\t%d\n",s[j]);
  }*/
 for(int i=0;i<end;i++)
 printf("%d\n",ares[i]);
}
