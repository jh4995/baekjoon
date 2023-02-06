#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int n, middle;
	int count = 0;
	scanf("%d", &n);

	int new_result = n;

	while (1)
	{
		middle  = (n % 10)*10 + ((n / 10) + (n % 10))%10 ;
		n = middle;
		count++;

		if (middle == new_result)
		{
			break;
		}
	}

	printf("%d", count);
	return 0;
}