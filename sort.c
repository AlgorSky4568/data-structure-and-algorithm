//
// Created by in4568 on 2026/6/28.
//

#include <stdio.h>

void swap(int* list,int a,int b)
{
    int temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}

void bubble_sort(int* list, int size)
{
    int swap_flag = 0;
    for (int i = 0 ; i <size;i++)
    {
        swap_flag = 0;
        for (int j = 0; j  < size-i-1;j++)
        {
            if (list[j] > list[j+1])
            {
                swap_flag = 1;
                swap(list,j,j+1);
            }
        }
        if (!swap_flag) break;
    }
}

void fast_sort(int* list, int begin,int end)
{
    if (begin >= end)
    {
        return;
    }
    int flag = list[(begin + end)/2];
    int low = begin;
    int high = end;
    while (low < high)
    {
        while(low < high && list[high] > flag) high --;
        while (low < high && list[low] < flag) low ++;
        swap(list,low,high);
    }
    fast_sort(list,begin,high);
    fast_sort(list,high+1,end);
}

int main(void)
{
    int list[10] = {78, 12, 53, 91, 34, 67, 45, 88, 23, 99};//正确排序应为{12,23,34,45,53,67,78,88,91,99}
    fast_sort(list,0,9);
    for (int i = 0 ; i <10;i++)
    {
        printf("%d ",list[i]);
    }
    return 0;
}