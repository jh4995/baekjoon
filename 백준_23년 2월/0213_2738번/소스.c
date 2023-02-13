#define _CRT_SSECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int main(void)
{
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	int a[101][101];
	int b[101][101];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", a[i][j] + b[i][j]);
		}
		printf("\n");
	}

	return 0;
}