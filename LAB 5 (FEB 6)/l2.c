#include<stdio.h>
#include<stdlib.h>

int *p[1000],s[1000],a[1000][1000];;
int k,ares[1000],sol[1000],count=0;
int size=0;

struct temparr
{
 int b[1000];
}t[1000];

//----------------------------------------

void store(int at[],int s,int start,int end)
{
 count++;
 if(start=0 && end==k-1)
 { 
  for(int i=0;i<size;i++)
  sol[i]=at[i];
 }
 else
 {
  for(int i=0;i<s;i++)
  t[count].b[i]=at[i];
 }
}

//----------------------------------------

void merge(int start,int mid,int end)
{
 int at[end],s=start;
 int i=start,j=mid+1;
 while(i<=mid && j<=end)
 {
  if(ares[i]<ares[j])
  at[s++]=ares[i++];
  else 
    at[s++]=ares[j++];
 }
 
 if(i>mid)
 while(j<=end)
  at[s++]=ares[j++];
 if(j>end)
 while(i<=mid)
  at[s++]=ares[i++];
 store(at,s,start,end); 
}

//------------------------------------------

void ms(int s,int e)
{
 int m=(s+e)/2;
 if(s<e)
 {
  ms(s,m);
  ms(m+1,e);
  merge(s,m,e);
 }
}

//-----------------------------------------

void join(int start,int end)
{
 int l=0;
 if(end-start==1)
 {
  for(int i=start;i<=end;i++)
  for(int j=0;j<s[i];j++)
  {
   ares[l++]=a[i][j];
  }
  ms(0,(s[start]+s[end])-1);
 }
 else
 {
  int n=(start+(end-start))/2;
  int s=end-start;
  int i=0;
  while(i<s)
  {
   if(i<=(s/2))
   ares[l++]=t[n].b[i];
 }
}

//-----------------------------------------

void dc(int start, int end)
{
 int mid=(start+end)/2;
 if(start<end)
 {
  dc(start,mid);
  dc(mid+1,end);
  join(start,end);
 } 
}


//MAIN---------------------------------------------------------------

void main()
{
 printf("Enter how may sorted arrays you want to enter: ");
 scanf("%d",&k);
 
 for(int i=0;i<k;i++)
 {
  printf("\nEnter size of array %d: \n",i+1);
  scanf("%d",&s[i]);
  size+=s[i];
  for(int j=0;j<s[i];j++)
  {
  printf("Element %d: ",j+1);
  scanf("%d",&a[i][j]);
 }
 }
 
 for(int i=0;i<k;i++)
 p[i]=&a[i][0];
 
 dc(0,k-1);
 
 for(int i=0;i<size;i++)
 printf("\t%d\n",sol[i]);
}
