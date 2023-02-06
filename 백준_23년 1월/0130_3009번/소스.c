#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int find_different_point(int first, int second, int third)
{
	if (first == second)
	{
		return third;
	}
	else
	{
		if (first == third)
		{
			return second;
		}
		else
		{
			return first;
		}
	}

}

int main(void)
{
	int x_list[3];
	int y_list[3];

	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &x_list[i], &y_list[i]);
	}

	int new_x = find_different_point(x_list[0], x_list[1], x_list[2]);
	int new_y = find_different_point(y_list[0], y_list[1], y_list[2]);

	printf("%d %d", new_x, new_y);
	return 0;
}