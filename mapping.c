#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    scanf("%d", &num);
    int mapping[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &mapping[i]);
    }
    int* nums = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &nums[i]);
    }
    int* nums1 = (int*)malloc(num * sizeof(int)); //用来接收转化后的字符串
    for (int i = 0; i < num; i++)
    {
        nums1[i] = 0;
    }


    for (int i = 0; i < num; i++)
    {
        char str[20] = {0};
        sprintf(str, "%d",nums[i]);
        int j = 0;
        while (str[j] != '\0')
        {
            str[j] = mapping[str[j] - '0'] + '0';
            j++;
        }
        nums1[i] = atoi(str);
    }

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i ; j++)
        {
            if (nums1[j] > nums1[j + 1])
            {
                int temp1 = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp1;

                int temp2 = nums1[j + 1];
                nums1[j + 1] = nums1[j];
                nums1[j] = temp2;
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;


}
