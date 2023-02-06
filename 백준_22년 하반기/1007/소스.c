#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int age;
	char name[100];
}array;

array name_set[100000];
array sorted[100000];
	
void merge(array* list, int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;

	while (i <= mid && j <= right)
	{
		if (list[i].age <= list[j].age)
		{
			sorted[k++] = list[i++];
		}
		else
		{
			sorted[k++] = list[j++];
		}
	}

	if (i > mid)
	{
		for (l = j; l <= right; l++)
		{
			sorted[k++] = list[l];
		}
	}
	else
	{
		for (l = i; l <= mid; l++)
		{
			sorted[k++] = list[l];
		}
	}
	for (l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}
}

void merge_sort(array* list, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %s", &name_set[i].age, name_set[i].name);
	}

	merge_sort(name_set, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n", name_set[i].age, name_set[i].name);		
	}

	return 0;
}