#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int joongbok_check(int list[], int n)
{
    int check[8001] = { 0 };
    int i, idx, max = 0, cnt = 0;

    for (i = 0; i < n; i++)
    {
        idx = list[i] + 4000;
        check[idx] += 1;

        if (check[idx] > max)
        {
            max = check[idx];
        }
    }

    for (i = 0, idx = 0; i < 8001; i++)
    {
        if (check[i] == 0)
        {
            continue;
        }

        if (check[i] == max)
        {
            if (cnt == 0)
            {
                idx = i;
                cnt += 1;
            }
            else if (cnt == 1)
            {
                idx = i;
                break;
            }
        }
    }
    return idx - 4000;
}

int main(void)
{
    int n;
    double sum = 0;
    scanf("%d", &n);

    int* list;
    list = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
        sum += list[i];
    }

    qsort(list, n, sizeof(int), compare);

    printf("%d\n", (int)round(sum / n));
    printf("%d\n", list[n / 2]);
    printf("%d\n", joongbok_check(list, n));
    printf("%d", list[n - 1] - list[0]);
}