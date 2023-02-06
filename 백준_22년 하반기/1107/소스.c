#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

int arr[500000] = { 0, };

int compare(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
    {
        return 1;
    }
    else if (*(int*)a < *(int*)b)
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
    int sum = 0;
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int compare = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (compare == arr[i + 1])
        {

        }
    }

    qsort(arr, n, sizeof(int), compare);
    printf("%.0f\n", (double)sum/n);
    printf("%d\n", arr[n/2]);
    //ÃÖºó°ª-> printf("%d\n", );
    printf("%d", arr[n - 1] - arr[0]);
}