#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int main(void)
{
	int k;
	scanf("%d", &k);

	int direction[8];
	int length[8];

	int max_row = 0;
	int max_col = 0;
	int sub_area = 1;

	for (int i = 0; i < 6; i++)
	{
		scanf("%d %d", &direction[i], &length[i]);

		if (direction[i] == 1 || direction[i] == 2)
		{
			if (length[i] > max_row)
			{
				max_row = length[i];
			}
		}

		if (direction[i] == 3 || direction[i] == 4)
		{
			if (length[i] > max_col)
			{
				max_col = length[i];
			}
		}
	}

	direction[6] = direction[0];
	direction[7] = direction[1];
	length[6] = length[0];
	length[7] = length[1];
	for (int i = 0; i < 6; i++)
	{
		if (direction[i] == direction[i + 2])
		{
			sub_area = sub_area * length[i + 1];
		}
	}

	printf("%d", (k * max_row * max_col) - (k * sub_area));
	return 0;
}