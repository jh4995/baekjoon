/*
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,z) ( (z)=(x), (x)=(y), (y)=(z) )

int list[10];
int n;*/

/*
* ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ선택정렬ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

void selection_sort(int list[], int n)
{
	int i, j, least, tmp;
	for (i = 0; i < n - 1; i++)
	{
		least = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[j] < list[least])
			{
				least = j;
			}
		}
		SWAP(list[i], list[least], tmp);
	}
}
*/

/*
* ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ삽입정렬ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
void insertion_sort(int lis[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
}
*/

/*
* ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ버블정렬ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
void bubble_sort(int list[], int n)
{
	int i, j, tmp;
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (list[j] > list[j + 1])
			{
				SWAP(list[j], list[j + 1], tmp);
			}
		}
	}
}
*/

/*
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ쉘정렬ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap)
	{
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
		{
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}
}

void shell_sort(int list[], int n)

{
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2)
	{
		if ((gap % 2) == 0)
		{
			gap++;
		}
		for (i = 0; i < gap; i++)
		{
			inc_insertion_sort(list, i, n - 1, gap);
		}
	}
}
*/

/*

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ합병정렬ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

int sorted[10];

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
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

void merge_sort(int list[], int left, int right)
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
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ퀵정렬ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

int compare(const void* a, const void* b)
{
	if (*(double*)a > *(double*)b)
	{
		return 1;
	}
	else if (*(double*)a < *(double*)b)
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
	int i;
	double list[5] = { 2.1, 0.9, 1.6, 3.8, 1.2 };

	qsort((void*)list, (size_t)5, sizeof(double), compare);
	for (i = 0; i < 5; i++)
	{
		printf("%f ", list[i]);
	}
	return 0;
}

 /*
int main(void)
{
	n = 10;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		list[i] = rand() % 100;
	}

	//selection_sort(list, n);
	//insertion_sort(list, n);
	//bubble_sort(list, n);
	//shell_sort(list, n);
	//merge_sort(list, 0, n-1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}*/