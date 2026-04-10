#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    scanf("%d",&n);
    int m = n+1;
    int *cards = (int*)malloc(m * sizeof(int));

    //1为正面，-1为背面
    for (int i = 0; i < m; i++){
        cards[i] = 1;
    }

    for(int i = 2; i < m; i++){
        for(int j = i; j < m; j +=i){
            cards[j] = -cards[j];
        }
    }

    int total = 0;
    for(int i = 1; i < m; i++){
        if(cards[i] == 1){
            printf("%d ",i);
            total++;
        }
        
    }
    printf("\n%d",total);

    return 0;
}