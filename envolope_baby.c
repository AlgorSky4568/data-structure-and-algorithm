#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
// 信封结构体
typedef struct {
    int width;
    int height;
} Envelope;


void sort(Envelope* envelopes, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (envelopes[i].width > envelopes[j].width) //按照宽度升序排列
            {
                Envelope temp1 = envelopes[i];
                envelopes[i] = envelopes[j];
                envelopes[j] = temp1;
            }
            else if (envelopes[i].width == envelopes[j].width)
            {
                if (envelopes[i].height < envelopes[j].height) //按照高度降序排列
                {
                    Envelope temp2 = envelopes[i];
                    envelopes[i] = envelopes[j];
                    envelopes[j] = temp2;
                }
            }
        }
    }
}


int maxEnvelopes(Envelope* envelopes, int n) {
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i-1; j >= 0; j--)
        {
            if (envelopes[i].height > envelopes[j].height)
            {
                dp[i] = max(dp[i], dp[j] +1);
            }
        }
    }
    int result = dp[0];
    for (int i = 1; i < n; i++)
    {
        result = max(result, dp[i]);
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    
    Envelope* envelopes = (Envelope*)malloc(n * sizeof(Envelope));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &envelopes[i].width, &envelopes[i].height);
    }
    sort(envelopes,n);

    int result = maxEnvelopes(envelopes, n);
    printf("%d\n", result);
    
    free(envelopes);
    return 0;
}