#include<stdio.h>
#include<stdlib.h>

int i=0;
struct node
{
 int data;
 struct node *lptr;
 struct node *rptr;
};
struct node *tptr=NULL;

void insert(int x);
void min();
void max();
void io(struct node *ptr);
void m(int a[],int i);
void main()
{
 int k,s[1000],a[1000];
 
 printf("Enter how may sorted arrays you want to enter: ");
 scanf("%d",&k);
 
 for(int i=0;i<k;i++)
 {
  printf("\nEnter size of array %d: \n",i+1);
  scanf("%d",&s[i]);
  for(int j=0;j<s[i];j++)
  {
   printf("Element %d: ",j+1);
   scanf("%d",&a[i]);
   insert(a[i]);
  }
 } 
 io(tptr);
}

void insert(int x)
{
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 temp->data=x;
 temp->lptr=temp->rptr=NULL;
 if(tptr==NULL)
 tptr=temp;
 else
 {
  struct node *ptr=tptr;
  struct node *pptr=NULL;
  while(ptr!=NULL)
  {
   pptr=ptr;
   if(x<ptr->data)
   ptr=ptr->lptr;
   else
   ptr=ptr->rptr;  
  }
  if(x<pptr->data)
  pptr->lptr=temp;
  else
  pptr->rptr=temp;
 } 
}


void io(struct node *ptr)
{
 
 if(ptr!=NULL)
 {
  io(ptr->lptr);
  printf("\t\n%d",ptr->data); 
  io(ptr->rptr);
 }
}

