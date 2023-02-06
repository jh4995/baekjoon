#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
//#include <stdlib.h>

/*
int main(void)
{
	int first, second;

	while (1)
	{
		scanf("%d %d", &first, &second);

		if (first == 0 && second == 0)
		{
			break;
		}

		if (second % first == 0)
		{
			printf("factor\n");
		}
		else if (first % second == 0)
		{
			printf("multiple\n");
		}
		else
		{
			printf("neither\n");
		}
	}

	return 0;
}*/

/*
int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
	{
		return 1;
	}
	else if (*(int*)a < *(int*)b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int real_num;
	scanf("%d", &real_num);

	int* real_list = (int*)malloc(sizeof(int) * real_num);
	for (int i = 0; i < real_num; i++)
	{
		scanf("%d", &real_list[i]);
	}
	qsort(real_list, real_num, sizeof(int), compare);
	

	printf("%d", real_list[0] * real_list[real_num - 1]);
	
	return 0;
}*/

/*
int main(void)
{
	int first, second;
	scanf("%d %d", &first, &second);

	int g_c_d = 0;
	for (int i = 1; i <= first && i <= second; i++)
	{
		if (first % i == 0 && second % i == 0) {
			g_c_d = i;
		}
	}

	printf("%d\n", g_c_d);
	printf("%d", first * second / g_c_d);

	return 0;
}*/

int main(void)
{
	int t;
	scanf("%d", &t);

	int first, second;
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &first, &second);

		int g_c_d = 0;
		for (int i = 1; i <= first && i <= second; i++)
		{
			if (first % i == 0 && second % i == 0) {
				g_c_d = i;
			}
		}

		printf("%d\n", first * second / g_c_d);
	}

	return 0;
}