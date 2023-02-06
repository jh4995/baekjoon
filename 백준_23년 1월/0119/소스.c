#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search_binary(char **set_s, int n, char *key)
{
	int middle;
	int low = 0;
	int high = n-1;

	while (low <= high)
	{
		middle = (low + high) / 2;
		if ( strcmp(key, set_s[middle]) == 0)
		{
			return 1;
		}
		else if ( strcmp(key , set_s[middle]) > 0)
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}
	return 0;
}

int compare(const void* a, const void* b)
{
	char* one = *(char**)a;
	char* two = *(char**)b;

	if (strcmp(one, two) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	char** set_s = NULL;
	set_s = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
	{
		set_s[i] = (char*)malloc(sizeof(char) * 501);
		scanf("%s", set_s[i]);
	}
	qsort(set_s, n, sizeof(char*), compare);

	char** check_string = NULL;
	check_string = (char**)malloc(sizeof(char*) * m);
	for (int i = 0; i < m; i++)
	{
		check_string[i] = (char*)malloc(sizeof(char) * 501);
		scanf("%s", check_string[i]);
	}

	int exist = 0;
	for (int i = 0; i < m; i++)
	{
		exist = exist + search_binary(set_s, n, check_string[i]);
	}

	for (int i = 0; i < n; i++)
	{
		free(set_s[i]);
	}
	free(set_s);

	for (int i = 0; i < m; i++)
	{
		free(check_string[i]);
	}
	free(check_string);

	printf("%d", exist);
	return 0;
}


