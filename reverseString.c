#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char s[50];
    int top;
}stack;


void initstack(stack *st){
    st->top = -1; 
}

void push(stack *st,char ch){
    st->top++;
    st->s[st->top] = ch;
}

void pop(stack *st,char ch){
    st->top--;
}

int main(void){
    char s[50] = {'\0'};
    scanf("%s",s);
    //处理不符合题目的字符
    for (int i = 0; i < sizeof(s);i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            s[i] = s[i] + ('a' - 'A');
        }
        else if('0' <= s[i]  && s[i] <= '9'){
            s[i] = '\0';
        }
        else{
            continue;
        }
    }

    char s1[50];
    //复制翻转过来的字符
    for(int i = 0;i < 50; i++){
        s1[i] = s[49 - i];
    }
    int i = 0;int j = 0;//i是控制s的，j是控制s1的
    int flag = 1;
    while(i != 50 && j != 50){
        if(s[i] == '\0'){
            i++;
            continue;
        }
        else if(s1[j] == '\0'){
            j++;
            continue;
        }
        else if(s[i] != s1[j]){
            flag = 0;
            break;
        }
        else{
            i++;
            j++;
        }
    }
    if(flag){
        printf("true");
    }
    else{
        printf("false");
    }

return 0;
}