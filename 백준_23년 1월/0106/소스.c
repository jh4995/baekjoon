#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct coordinate{
	int index;
	int number;
}coordinate;

int compare(const void* a, const void* b)
{
	coordinate x = *(coordinate*)a;
	coordinate y = *(coordinate*)b;

	if (x.number > y.number)
	{
		return 1;
	}
	else if (x.number < y.number)
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
	int count = -1;
	int min = INT_MIN;
	scanf("%d", &n);

	coordinate* pre_compress = (coordinate*)malloc(sizeof(coordinate) * n);
	int* post_compress = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pre_compress[i].number);
		pre_compress[i].index = i;

	}

	qsort(pre_compress, n, sizeof(coordinate), compare);

	for (int i = 0; i < n; i++)
	{
		if (pre_compress[i].number != min)
		{
			min = pre_compress[i].number;
			count++;
		}
		post_compress[pre_compress[i].index] = count;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", post_compress[i]);
	}

	return 0;
}*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>

int count;

int recursion_count()
{
	count++;
	return count;
}

int recursion(const char* s, int l, int r)
{
	if (l >= r)
	{
		return 1;
	}
	else if (s[l] != s[r])
	{
		return 0;
	}
	else
	{
		recursion_count();
		return recursion(s, l + 1, r - 1);
	}
}

int isPalindrome(const char* s)
{
	return recursion(s, 0, strlen(s) - 1);
}

int main()
{
	int t;
	scanf("%d", &t);

	char s[1001];

	for (int i = 0; i < t; i++)
	{
		scanf("%s", s);
		printf("%d ", isPalindrome(s));
		printf("%d\n", recursion_count());
		count = 0;
	}
}