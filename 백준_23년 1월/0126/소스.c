#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search_binary(char** set, int size, char* key)
{
	int middle;
	int low = 0;
	int high = size-1;

	while (low <= high)
	{
		middle = (low + high) / 2;
		if (strcmp(key, set[middle]) == 0)
		{
			return 1;
		}
		else if (strcmp(key, set[middle]) > 0)
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
	else if (strcmp(one, two) < 0)
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
	int n, m;
	scanf("%d %d", &n, &m);

	char** never_listened = NULL;
	never_listened = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
	{
		never_listened[i] = (char*)malloc(sizeof(char) * 21);
		scanf("%s", never_listened[i]);
	}
	qsort(never_listened, n, sizeof(char*), compare);

	char** never_seen = NULL;
	never_seen = (char**)malloc(sizeof(char*) * m);
	for (int j = 0; j < m; j++)
	{
		never_seen[j] = (char*)malloc(sizeof(char) * 21);
		scanf("%s", never_seen[j]);
	}
	qsort(never_seen, m, sizeof(char*), compare);

	int exist = 0;
	for (int j = 0; j < m; j++)
	{
		exist = exist + search_binary(never_listened, n, never_seen[j]);
	}
	printf("%d\n", exist);

	for (int j = 0; j < m; j++)
	{
		if (search_binary(never_listened, n, never_seen[j]) >= 1)
		{
			printf("%s\n", never_seen[j]);
		}
	}


	for (int i = 0; i < n; i++)
	{
		free(never_listened[i]);
	}
	free(never_listened);

	for (int j = 0; j < m; j++)
	{
		free(never_seen[j]);
	}
	free(never_seen);


	return 0;
}