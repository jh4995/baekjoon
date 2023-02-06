#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int alphabet[26];
	char word[100];
	scanf("%s", word);

	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = -1;
	}
	
	for (int i = 'a'; i<='z'; i++)
	{
		for (int j = 0; word[j] != NULL; j++)
		{
			if (word[j] == i)
			{
				alphabet[word[j] - 'a'] = j;
				break;
			}
		}
	}
	for (int i = 0; i<26; i++)
	{
		printf("%d ", alphabet[i]);
	}
	return 0;
}
/*
int main(void)
{
	int n, d_n;
	int new_n = 1;
	int array[10000];

	while (1)
	{
		n = new_n;
		d_n = n + (n / 10) + (n % 10);
		new_n = d_n;

		printf("%d\n", new_n);
		if (new_n > 100)
		{
			break;
		}
	}


	return 0;
}*/
