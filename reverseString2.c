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
    int index = 0; //表示字符串起始位，每次自增2k
    int len = strlen(a);

    while (1) {
        if (len - index <= k)
        {
            for (int i = index; i < len; i++)
            {
                b[i] = a[len - i - 1 + index];//剩下的字符数不到k，全部翻转
            }
            break;
        }
        else if (k < len - index && len - index <= 2*k)
        {
            for (int i = index; i < index + k; i++)
            {
                b[i] = a[index + k - 1-  (i - index)];
            }
            for (int i = index + k; i < len; i++)
            {
                b[i] = a[i];
            }
            break;
        }
        else {
            for (int i = index; i < index + k; i++)
            {
                b[i] = a[index + k - 1-  (i - index)];
            }
            for (int i = index + k; i < index + 2 * k; i++)
            {
                b[i] = a[i];
            }
            index += 2 * k;
        }
    }

    printf("%s",b);

    return 0;
}