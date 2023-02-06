#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int judge_in_out(int x, int y, int c_x, int c_y, int r)
{
	if ((x - c_x) * (x - c_x) + (y - c_y) * (y - c_y) > r * r)
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
	int t;
	scanf("%d", &t);

	int x1, y1, x2, y2;
	int n;
	int c_x, c_y, r;

	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);

		int count = 0;
		for (int j = 0; j < n; j++)
		{
			scanf("%d %d %d", &c_x, &c_y, &r);

			if (judge_in_out(x1, y1, c_x, c_y, r) != judge_in_out(x2, y2, c_x, c_y, r))
			{
				count++;
			}

		}
		printf("%d\n", count);
	}

	return 0;
}