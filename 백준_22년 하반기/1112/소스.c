#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)


#include <stdio.h>
#include <stdlib.h>
int num[500000];
int freq[8001];

int maxFinder(int* arr, int size_arr) {
	int maxV = arr[0];
	for (int t = 0; t < size_arr; t++) {
		if (maxV < arr[t]) maxV = arr[t];
	}
	return maxV;
}
int compare(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	if (n1 < n2) return -1;
	else if (n1 > n2) return 1;
	else return 0;
}

int main() {
	int N, i, j;
	int max;
	int mode;
	int sum = 0, flags = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &num[i]);
		sum += num[i];
		freq[num[i] + 4000]++;
	}
	qsort(num, N, sizeof(int), compare);

	max = maxFinder(freq, 8001);
	for (i = 0; i < 8001; i++) {
		if (max == freq[i]) flags++;
	}
	for (i = 0; i < 8001; i++) {
		if (flags == 1) {
			if (max == freq[i]) {
				mode = i - 4000;
				break;
			}
		}
		else {
			if (max == freq[i])
				if (flags == 0) {
					mode = i - 4000;
					break;
				}
				else flags = 0;
		}
	}

	printf("%.0f\n", (sum / (double)N));
	printf("%d\n", num[N / 2]);
	printf("%d\n", mode);
	printf("%d\n", num[N - 1] - num[0]);
	return 0;
}