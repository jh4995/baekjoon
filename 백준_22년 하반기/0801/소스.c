#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int main(void)
{
	int all[6] = { 1,1,2,2,2,8 };
	int found[6] = { 0, };

	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &found[i]);
	}

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", all[i] - found[i]);
	}
	return 0;
}

