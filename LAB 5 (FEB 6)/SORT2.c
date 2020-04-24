#include <stdio.h>
#include <stdlib.h>
#define LEN 1000000


void randomfill(int a[])
{
 srand(0);
 for (int i = 0; i < LEN; ++i)
 a[i] = rand() % 1000000;
}


void print(int a[])
{
 for (int i = 0; i < LEN; ++i)
 printf("%d ", a[i]);
 printf("\n\n\n");
}


void insertionsort(int beg, int a[], int end)
{
 for (int i = beg; i < end; ++i)
 {
  for (int j = beg; j < i; ++j)
  {
   if (a[j] > a[i])
   {
    a[i] = a[i] ^ a[j];
    a[j] = a[i] ^ a[j];
    a[i] = a[i] ^ a[j];
   }
  }
 }
}


void merge(int beg, int a[], int end, int m)
{
 int i = 0;
 int tmp[1000000];
 int mid = m, b = beg;
  
 while ((beg < mid) && (m < end))
 {
  if (a[beg] < a[m])
  tmp[i++] = a[beg++];
  else
  tmp[i++] = a[m++];
 }
 while (beg < mid)
 {
  tmp[i] = a[beg];
  beg++;
  i++;
 }
 while (m < end)
 {
  tmp[i] = a[m];
  m++;
  ++i;
 }
 for (int j = 0; j < end - b; ++j)
 a[j + b] = tmp[j];
}


void ms(int beg, int a[], int end)
{
 if (end - beg <= 10000)
 insertionsort(beg, a, end);
 else
 {
  int m = (beg + end) / 2;
  ms(beg, a, m);
  ms(m, a, end);
  merge(beg, a, end, m);
 }
}


void main()
{
 srand(1);
 int a[LEN];
 randomfill(a);
 ms(0,a,LEN);
 print(a);
} 
