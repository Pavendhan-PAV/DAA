#include<stdio.h>
#include"sortfile.h"


void print_Array(int *A,int size)
{

 for(int i=0;i<size;i++)
 printf("%d ",A[i]);

}





int main()
{

sort s;

int A[]={5,3,2,1,4};

int size=sizeof(A)/sizeof(A[0]);

print_Array(A,size);

s.quicksort(A,0,size-1);

print_Array(A,size);

return 0;

}


