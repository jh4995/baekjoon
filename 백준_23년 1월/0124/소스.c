#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int main(void)
{
	int n;
	int student_list[30] = { 0, };

	for (int i = 0; i < 28; i++)
	{
		scanf("%d", &n);
		student_list[n - 1]++;
	}

	for (int i = 0; i < 30; i++)
	{
		if (student_list[i] == 0)
		{
			printf("%d\n", i+1);
		}
	}

	return 0;
}