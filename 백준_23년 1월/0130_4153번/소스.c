#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int calculate_result(int length_1, int length_2, int length_3)
{
	int max, x, y;

	if (length_1 >= length_2 && length_1 >= length_3)
	{
		max = length_1;
		x = length_2;
		y = length_3;
	}
	else if (length_2 >= length_1 && length_2 >= length_3)
	{
		max = length_2;
		x = length_1;
		y = length_3;
	}
	else
	{
		max = length_3;
		x = length_1;
		y = length_2;
	}

	if ((x * x) + (y * y) == (max * max))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int length_1, length_2, length_3;

	while (1)
	{
		scanf("%d %d %d", &length_1, &length_2, &length_3);

		if (length_1 == 0 && length_2 == 0 && length_3 == 0)
		{
			break;
		}

		else
		{
			if (calculate_result(length_1, length_2, length_3) == 1)
			{
				printf("right\n");
			}
			else
			{
				printf("wrong\n");
			}
		}
	}

	return 0;
}