#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    char s_stack[100];
}stack;

void initStack(stack *s)
{
    s->top = -1;
}

void push(stack *s, char x)
{
    s->s_stack[++s->top] = x;
}

void pop(stack *s)
{
    s->top--;
}

int main(void)
{
    stack s;
    initStack(&s);
    char x;
    int flag = 1;
    while(1)
    {
        scanf("%c", &x);
        if (x == '[' || x == '(' || x == '{')
        {
            push(&s, x);
        }
        else if (x == ']')
        {
            if (s.s_stack[s.top] == '[')
            {
                pop(&s);
            }
            else
            {
                flag = 0;
                break;
            }
        }
        else if (x == ')')
        {
            if (s.s_stack[s.top] == '(')
            {
                pop(&s);
            }
            else
            {
                flag = 0;
                break;
            }
        }
        else if (x == '}')
        {
            if (s.s_stack[s.top] == '{')
            {
                pop(&s);
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (s.top == -1)
        {
            break;
        }
    }
    if (flag)
    {
       printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}