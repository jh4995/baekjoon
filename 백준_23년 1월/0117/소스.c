#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

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

int search_binary(int card_list[], int n, int key)
{
	int middle;
	int low = 0;
	int high = n;

	while (low <= high)
	{
		middle = (low + high) / 2;
		if (key == card_list[middle])
		{
			return 1;
		}
		else if (key > card_list[middle])
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}
	return -1;
}

int main(void)
{
	int i;
	int exist = 0;

	int n;
	scanf("%d", &n);
	int* card_list = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &card_list[i]);
	}
	
	int m;
	scanf("%d", &m);
	int* number_list = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &number_list[i]);
	}
	
	qsort(card_list, n, sizeof(int), compare);

	for (int i = 0; i < m; i++)
	{
		exist = search_binary(card_list, n, number_list[i]);

		if (exist == 1)
		{
			printf("%d ", 1);
		}
		else
		{
			printf("%d ", 0);
		}
	}

	free(card_list);
	free(number_list);

	return 0;
}