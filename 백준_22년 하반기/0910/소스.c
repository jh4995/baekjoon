#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )
int list[1000];

void bubble_sort(int list[], int n)
{
	int i, j, tmp;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (list[j] > list[j + 1])
			{
				SWAP(list[j], list[j + 1], tmp);
			}
		}
	}
}

int main(void)
{
	int i;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}

	bubble_sort(list, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", list[i]);
	}

	return 0;
}