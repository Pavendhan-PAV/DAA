#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b)
{
	if(!(a && b))
		return a+b;
	return gcd(b%a, a);
}
int gcdn(int ar[], int n)
{
	if(n)
		return gcd(ar[n - 1], gcdn(ar, n - 1));
	return ar[n];
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
long int lcmn(int ar[], int n)
{
	if(n)
		return lcm(ar[n - 1], lcmn(ar, n - 1));
	return ar[n];
}
void randomfill(int ar[], int len, int max)
{
	for(int i = 0; i <len; ++i)
		ar[i] = rand() % max;
}
void main()
{
	srand(0);
	int n = 10, ar[10];
	randomfill(ar, n, 100);
	printf("%d\n", gcdn(ar, n));
	printf("%ld\n", lcmn(ar, n));
}