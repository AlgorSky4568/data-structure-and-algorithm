//
// Created by in4568 on 2026/4/18.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char a[100];
    char b[100] = {'\0'};
    int k;
    scanf("%s %d", a, &k);
    if (strlen(a) < k)
    {
        for (int i = 0; i < strlen(a); i++)
        {
            b[i] = a[strlen(a) - 1 - i];
        }
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            b[i] = a[k-1-i];
        }
        for (int i = k; i < strlen(a); i++)
        {
            b[i] = a[i];
        }
    }
    printf("%s",b);

    return 0;
}