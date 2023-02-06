#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>

int count;

int recursion_count()
{
    count++;
    return count;
}

int recursion(const char* s, int l, int r)
{
    if (l >= r)
    {
        return 1;
    }
    else if (s[l] != s[r]) 
    {
        return 0;
    }
    else
    {
        recursion_count();
        return recursion(s, l + 1, r - 1);
    }
}

int isPalindrome(const char* s)
{
    return recursion(s, 0, strlen(s) - 1);
}

int main(void)
{
    int t;
    scanf("%d", &t);

    char s[1001];

    for (int i = 0; i < t; i++)
    {
        scanf("%s", s);
        printf("%d ", isPalindrome(s));
        printf("%d\n", recursion_count());
        count = 0;
    }
}