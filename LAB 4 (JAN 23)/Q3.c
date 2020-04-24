#include <stdio.h>
#include <stdlib.h>

int blinear(int ar[], int n)
{
	if (n)
	{
		if (ar[n - 1] < 0)
			return 1 + blinear(ar, n - 1);
		else
			return blinear(ar, n - 1);
	}
	return 0;
}
void main()
{
	srand(0);
	int n = 10;
	int ar[] = {-2, -234, -5, 36, -136, -4, -13, -100, 11};
	printf("%d", blinear(ar, n));
}