#include<stdio.h>
#include<stdlib.h>
 
void toh(int n, char a, char b, char c); 
void main()
{
 int n;
 printf("\nEnter the no of discs:");
 scanf("%d",&n);
 toh(n,'A','B','C');
}

void toh(int n,char a,char b ,char c)
{
 if(n==1)
 {
  printf("\nMoving Disk 1 from %c to %c",a,c);
  return;
 }
 else
 {
  toh(n-1,a,c,b);
  printf("\nMoving Disk %d from %c to %c,",n,a,c);
  toh(n-1,c,b,a);
 }
 
}
