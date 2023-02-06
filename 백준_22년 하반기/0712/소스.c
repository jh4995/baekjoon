#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
/*
int main(void)
{
	int n;
	int count;
	char test_case[80];
	int O_count[100] = {0, };
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", &test_case);
		count = 1;
		for (int j = 0; j < strlen(test_case); j++)
		{
			if (test_case[j] == 'O')
			{
				O_count[i] = O_count[i] + 1;
				count++;
			}
			else if (test_case[j] == 'X')
			{
				count = 1;
			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", O_count[i]);
	}
	

	return 0;
}*/

int main(void)
{
	int n;
	int count;
	char test_case[80];
	int o_count[100] = { 0, };

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &test_case[i]);
		count = 1;

		for (int j = 0; j < strlen(test_case); j++)
		{
			if (test_case[j] == 'O')
			{
				o_count[i] += count;
				count++;
			}
			else
			{
				count = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", o_count[i]);
	}
	return 0;
}
/*
int main(void)
{
	int input;
	int count;
	int sum[100] = { 0, };
	char arr[80];

	scanf("%d", &input);
	for (int i = 0; i < input; i++)
	{
		scanf("%s", &arr);
		count = 1;

		for (int j = 0; j < strlen(arr); j++)
		{
			if (arr[j] == 'O')
			{
				sum[i] += count;
				count++;
			}
			else
			{
				count = 1;
			}
		}
	}

	for (int i = 0; i < input; i++)
	{
		printf("%d\n", sum[i]);
	}
	return 0;
}*/
