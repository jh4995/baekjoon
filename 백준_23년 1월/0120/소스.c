#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[21];
	int num;
}pocketmon;

int search_binary(pocketmon* copy_monster_list, int low, int high, char* key)
{
	int middle = (low + high) / 2;

	while (low <= high)
	{
		middle = (low + high) / 2;
		if (strcmp(key, copy_monster_list[middle].name) == 0)
		{
			return (copy_monster_list[middle].num);			
		}
		else if (strcmp(key, copy_monster_list[middle].name) > 0)
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}
	return -1;
}

int compare(const void* a, const void* b)
{
	pocketmon *one = (pocketmon*)a;
	pocketmon *two = (pocketmon*)b;

	if (strcmp(one->name, two->name) > 0)
	{
		return 1;
	}
	else if(strcmp(one->name, two->name) < 0)
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

	pocketmon* monster_list = NULL;
	pocketmon* copy_monster_list = NULL;

	monster_list = (pocketmon*)malloc(sizeof(pocketmon) * n);
	copy_monster_list = (pocketmon*)malloc(sizeof(pocketmon) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", monster_list[i].name);
		monster_list[i].num = i + 1;
		strcpy(copy_monster_list[i].name, monster_list[i].name);
		copy_monster_list[i].num = i + 1;
	}
	
	qsort(copy_monster_list, n, sizeof(pocketmon), compare);

	char question[21];
	int result = 0;
	pocketmon* question_list = NULL;
	for (int j = 0; j < m; j++)
	{
		scanf("%s", question);

		if ( '0' <= question[0] && question[0] <= '9') //숫자 -> 문자
		{
			int idx = atoi(question);
			printf("%s\n", monster_list[idx-1].name);
		}
		else // 문자 -> 숫자
		{
			printf("%d\n", search_binary(copy_monster_list, 0, n - 1, question));
		}
	}
	
	free(monster_list);
	free(copy_monster_list);

	return 0;
}