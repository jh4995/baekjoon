#define _CRT_SSECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#define MIN(x, y) (x) < (y) ? (x) : (y)

#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int tmp;
	int two_count = 0;
	int five_count = 0;
	for (int i = 1; i <= n; i++)
	{
		tmp = i;
		while (tmp % 2 == 0)
		{
			two_count++;
			tmp = tmp / 2;
		}

		while (tmp % 5 == 0)
		{
			five_count++;
			tmp = tmp / 5;
		}
	}

	int zero_count = MIN(two_count, five_count);

	printf("%d", zero_count);
	return 0;
}