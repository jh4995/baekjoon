#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int num = 666;
	int count = 0;


	while (1)
	{
		int count_of_6 = 0;
		int changing_num = num;

		while (changing_num > 0)
		{
			int digit = changing_num % 10;

			if (digit == 6)
			{
				count_of_6++;
			}
			else
			{
				count_of_6 = 0;
			}

			if (count_of_6 == 3)
			{
				count++;
				break;
			}
			changing_num /= 10;
		}

		if (count == n)
		{
			break;
		}

		num++;
	}

	printf("%d", num);

	return 0;
}