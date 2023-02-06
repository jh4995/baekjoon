#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
/*
void hanoi(int n, int start, int path, int end)
{
	if (n == 1)
	{
		printf("%d %d\n", start, end);
	}
	else
	{
		hanoi(n - 1, start, end, path);
		printf("%d %d\n", start, end);
		hanoi(n - 1, path, start, end);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int k = 1;
	for (int i = 0; i < n; i++)
	{
		k = k * 2;
	}

	printf("%d\n", k - 1);
	hanoi(n, 1, 2, 3);		

	return 0;
}*/

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int call_number[100] = { 0, };
	int sum, max = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &call_number[i]);
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = call_number[i] + call_number[j] + call_number[k];

				if (sum <= m && max < sum)
				{
					max = sum;
				}
			}
		}
	}

	printf("%d", max);
	return 0;
}