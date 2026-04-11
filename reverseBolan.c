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
    if (S->top != -1) {
        *data = S->data[S->top];
        S->top = S->top - 1;
    }

}

int main(void) {
    stack s;
    int num;
    scanf("%d", &num);
    initStack(&s);

    int result = 0;
    int num1,num2;
    while (num != 0) {
        char ch;
        scanf("%c", &ch);
        if (ch == '+') {
            pop(&s, &num1);
            pop(&s, &num2);
            result = num1 + num2;
        }
        else if (ch == '-') {
            pop(&s, &num1);
            pop(&s, &num2);
            result = num1 - num2;
        }
        else if (ch == '*') {
            pop(&s, &num1);
            pop(&s, &num2);
            result = num1 * num2;
        }
        else if (ch == '/') {
            pop(&s, &num1);
            pop(&s, &num2);
            result = num1 / num2;
        }
        else {
            push(&s, ch - '0');
        }
        num--;
    }
    printf("%d", result);

    return 0;
}