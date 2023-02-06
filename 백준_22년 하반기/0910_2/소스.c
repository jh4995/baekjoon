#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct dot{
	int x;
	int y;
}dot;
dot list[100000];
dot sorted[100000];

void merge(dot* list, int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;

	while (i <= mid && j <= right)
	{
		if (list[i].y < list[j].y)
		{
			sorted[k++] = list[i++];
		}
		else if (list[i].y > list[j].y)
		{
			sorted[k++] = list[j++];
		}
		else
		{
			if (list[i].x < list[j].x)
			{
				sorted[k++] = list[i++];
			}
			else if (list[i].x > list[j].x)
			{
				sorted[k++] = list[j++];

			}
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

void merge_sort(dot* list, int left, int right)
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

//
int main(void)
{
	int n;
	scanf("%d", &n);

	dot* list = (dot*)malloc(sizeof(dot) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &list[i].x);
		scanf("%d", &list[i].y);
	}

	merge_sort(list, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", list[i].x, list[i].y);
	}

	return 0;
}