#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count[] = { 0, };
	int n;
	scanf("%d", &n);

	int* list;
	list = (int*)calloc(n, sizeof(int));
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if ((int)list[i] > (int)list[j])
			{
				count[i]++;
			}
			else
			{
				count[j]++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", count[i]);
	}
	return 0;
}