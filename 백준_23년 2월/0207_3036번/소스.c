#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int Euclidean(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	else
	{
		return Euclidean(b, a % b);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int r_of_ring[100];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &r_of_ring[i]);
	}

	int g_c_d;
	for (int i = 1; i < n; i++)
	{
		g_c_d = Euclidean(r_of_ring[0], r_of_ring[i]);
		printf("%d/%d\n", r_of_ring[0] / g_c_d, r_of_ring[i] / g_c_d);
	}
	
	return 0;
}