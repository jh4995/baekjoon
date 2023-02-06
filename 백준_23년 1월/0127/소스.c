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

int search_binary(int number_list[], int size, int key)
{
	int middle;
	int low = 0;
	int high = size-1;

	while (low <= high)
	{
		middle = (low + high) / 2;
		if (key == number_list[middle])
		{
			return 1;
		}
		else if (key > number_list[middle])
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}
	return 0;
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	int* a_number = (int*)malloc(sizeof(int) * n);
	int* b_number = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a_number[i]);
	}
	qsort(a_number, n, sizeof(int), compare);

	int overlap = 0;
	for (int j = 0; j < m; j++)
	{
		scanf("%d", &b_number[j]);
		overlap = overlap + search_binary(a_number, n, b_number[j]);
	}

	overlap = overlap * 2;
	printf("%d", n + m - overlap);

	return 0;
}