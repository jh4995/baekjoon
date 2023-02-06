#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#define PI 3.14159265359

int main(void)
{
	int r;
	scanf("%d", &r);

	double result_1 = (double)(PI * r * r);
	double result_2 = (double)(2 * r * r);


	printf("%.6lf\n", result_1);
	printf("%.6lf", result_2);

	return 0;
}