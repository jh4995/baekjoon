#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

/*
int main(void)
{
	int n;
	scanf("%d", &n);

	int x[50] = { 0, };
	int y[50] = { 0, };
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	for (int i = 0; i < n; i++)
	{
		int rank_down = 1;
		for (int j = 0; j < n; j++)
		{
			if (x[i] < x[j] && y[i] < y[j])
			{
				rank_down++;
			}
		}
		printf("%d ", rank_down);
	}

	return 0;
}*/

char white_start [8][8] = 
{	
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"}
};

char black_start[8][8] =
{	
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"}
};

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	char board[50][50];

	int i, j;
	int start_of_i, start_of_j;
	int change_to_W = 0;
	int	change_to_B = 0;
	int change_count = 0;
	int min_change[50][50] = { 0 };
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &board[i][j]);
		}
	}

	for (start_of_i = 0; start_of_i < n - 7; start_of_i++)
	{
		for (start_of_j = 0; start_of_j < m - 7; start_of_j++)
		{
			change_to_B = 0;
			change_to_W = 0;
			change_count = 0;

			for (i = start_of_i; i < start_of_i + 8; i++)
			{
				for (j = start_of_j; j < start_of_j + 8; j++)
				{
					
					if (board[i][j] != black_start[i-start_of_i][j-start_of_j])
					{
						change_to_W++;
					}
					if (board[i][j] != white_start[i-start_of_i][j-start_of_j])
					{
						change_to_B++;
					}
				}
			}

			if (change_to_W >= change_to_B)
			{
				change_count = change_to_B;
			}

			else
			{
				change_count = change_to_W;
			}

			min_change[start_of_i][start_of_j] = change_count;
		}
	}

	result = min_change[0][0];
	for (start_of_i = 0; start_of_i < n - 7; start_of_i++)
	{
		for (start_of_j = 0; start_of_j < m - 7; start_of_j++)
		{
			if (result > min_change[start_of_i][start_of_j])
			{
				result = min_change[start_of_i][start_of_j];
			}
		}
	}
	
	printf("%d", result);

	return 0;
}