#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int first = *(int*)a;
	int second = *(int*)b;

	if (first > second)
	{
		return 1;
	}
	else if (first < second)
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

	int n;
	scanf("%d", &n);

	int* list = (int*)malloc(sizeof(int) * n);
	int* sorted = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}

	qsort(sorted, n, sizeof(int), compare);

	free(list);
	free(sorted);
	return 0;
}