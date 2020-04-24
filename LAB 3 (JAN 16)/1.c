#include<stdio.h>

void stableSort(int a[], int n) 
{ 
    for (int i = 0; i < n - 1; i++)  
    { 
        int min = i; 
        for (int j = i + 1; j < n; j++) 
            if (a[min] > a[j]) 
                min = j; 
  
        int key = a[min]; 
        while (min > i)  
        { 
            a[min] = a[min - 1]; 
            min--; 
        } 
        a[i] = key; 
    } 
} 

void main()
{
	int n;
	printf("\nEnter the size n: ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the array elements (only 0,1,2) : ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	stableSort(a,n);
	
	printf("\nStable Sorted array:");
	for(int i=0;i<n;i++)
		printf("\t%d",a[i]);	
	
}
