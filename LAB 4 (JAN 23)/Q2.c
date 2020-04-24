#include <stdio.h>

int count(int bin_num[], int len)
{
	if (len == 1)
		return bin_num[0];

	return count(bin_num, len / 2) + count(bin_num + len / 2, len - len / 2);
}

void main()
{
	int bin_num[] = { 1, 1, 0, 1, 0, 1, 1, 1, 0 ,1, 0, 1 };
	int n = sizeof bin_num / sizeof bin_num[0];

	printf("Total number of 1's present are %d", count(bin_num, n));
}
