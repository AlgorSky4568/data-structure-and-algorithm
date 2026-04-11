#include <stdlib.h>
#include <stdio.h>


typedef struct {
    int data[20];
    int top;
}stack;


void initStack(stack *s) {
    s->top = -1;
}

void push(stack *s, int data)
{
    s->top++;
    s->data[s->top] = data;

}

void pop(stack *S, int *data)
{
    *data = S->data[S->top];
    S->top = S->top - 1;
}

int main(void) {
    stack s; //栈
    int num; //循环次数
    scanf("%d", &num);
    getchar();
    initStack(&s); //初始化栈

    int result1 = 0;
    int result2 = 0;
    int num1,num2;//进行运算的两个数
    num1 = 0;
    num2 = 0;
    while (num != 0) {
        char ch[20];
        scanf("%s", ch);
        getchar();
        if (ch[0] == '+') {
            pop(&s, &num1);
            pop(&s, &num2);
            result1 = num1 + num2;
            push(&s,result1);
        }
        else if (ch[0] == '-') {
            pop(&s, &num2);
            pop(&s, &num1);
            result1 = num1 - num2;
            push(&s,result1);
        }
        else if (ch[0] == '*') {
            pop(&s, &num1);
            pop(&s, &num2);
            result1 = num1 * num2;
            push(&s,result1);
        }
        else if (ch[0] == '/') {
            pop(&s, &num2);
            pop(&s, &num1);
            result1 = num1 / num2;
            push(&s,result1);
        }
        else {
            push(&s, atoi(ch));
        }
        num--;
    }
    result2 = s.data[s.top];
    printf("%d", result2);

    return 0;
}
