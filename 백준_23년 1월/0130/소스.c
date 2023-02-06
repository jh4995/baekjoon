#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#define MIN(x, y) (x) < (y) ? (x) : (y)

int main(void)
{
	int x, y, w, h;
	int min_row, min_col = 0;
	int shortest = 0;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	min_row = MIN(x, w - x);
	min_col = MIN(y, h - y);
	shortest = MIN(min_row, min_col);

	printf("%d", shortest);
	return 0;
}