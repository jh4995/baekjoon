#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j != 1)
			{
				printf("*");
			}
			else
			{
				continue;
			}
		}
		printf("\n");
	}

	return 0;
}