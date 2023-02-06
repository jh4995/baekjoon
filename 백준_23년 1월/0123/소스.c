#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int main(void)
{
	int n;
	int list[100];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}

	int v;
	scanf("%d", &v);

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (v == list[i])
		{
			count++;
		}
	}

	printf("%d", count);

	return 0;
}