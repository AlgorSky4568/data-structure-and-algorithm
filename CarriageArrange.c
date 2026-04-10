#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data[20];
    int top;
}stack;

void initStack(stack *s){
    s->top = -1;
}

void push(stack *s, int data){
    s->top++;
    s->data[s->top] = data;
}

int pop(stack *s){
    int data = s->data[s->top];
    s->top--;
    return data;
}
int main(void){
    int carriage[40] = {0};
    stack s1,s2;
    initStack(&s1);
    initStack(&s2);

    int data;
    char ch;
    do{
        scanf("%d",&data);
        push(&s1,data);
    }while((ch = getchar()) != '\n' && ch != EOF);

    do{
        scanf("%d",&data);
        push(&s2,data);
    }while((ch = getchar()) != '\n' && ch != EOF);
    
    int index = 0;
    while(s1.top != -1 || s2.top != -1){
        if(s1.top == -1){
            carriage[index] = pop(&s2);
        }
        else if(s2.top == -1){
            carriage[index] = pop(&s1);
        }
        else if(s1.data[s1.top] > s2.data[s2.top]){
            carriage[index] = pop(&s2);
        }
        else if(s1.data[s1.top] < s2.data[s2.top]){
            carriage[index] = pop(&s1);
        }
        index++;
    }
    for(int i = 0; i < index; i++){
        printf("%d ",carriage[i]);
    }

    return 0;
}