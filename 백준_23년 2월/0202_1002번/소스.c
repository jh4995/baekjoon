#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <math.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	int x_1, y_1, r_1, x_2, y_2, r_2, result;

	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d %d %d %d", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);

		double point_distance = sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2));
		double r_difference = (r_1 > r_2) ? (r_1 - r_2) : (r_2 - r_1);

		if (point_distance == 0 && r_1 == r_2)
		{
			result = -1;
		}
		else if (r_difference < point_distance && point_distance < (r_1 + r_2))
		{
			result = 2;
		}
		else if (point_distance == (r_1 + r_2) || point_distance == r_difference)
		{
			result = 1;
		}
		else
		{
			result = 0;
		}
		printf("%d\n", result);
	}
	
	return 0;
}