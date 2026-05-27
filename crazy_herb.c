#include <stdio.h>
#include <stdlib.h>

typedef struct Herb
{
    int time;
    int value;
}Herb;

int max(int a,int b)
{
    return a>b?a:b;
}

int max_value(Herb* herb,int c,int n)
{
    int dp[c+1];
    for (int i=0;i<c+1;i++)
    {
        dp[i]=0;
    }
    for (int i=0;i<n;i++)
    {
        for (int j = herb[i].time; j <= c ; j++)
        {
            dp[j] = max(dp[j],dp[j-herb[i].time]+herb[i].value);
        }
    }
    return dp[c];
}

int main(void)
{
    int c,n;
    scanf("%d %d",&c,&n);
    Herb* herb = (Herb*)malloc(sizeof(Herb)*n);//初始化所有草药信息
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&herb[i].time,&herb[i].value);
    }
    int result = max_value(herb,c,n);
    printf("%d\n",result);
    free(herb);
    return 0;

}