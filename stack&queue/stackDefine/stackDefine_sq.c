#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

void initStack(SqStack *s);
void displayStack(SqStack *s);
int stackEmpty(SqStack *s);
int push(SqStack *s, int data);
int pop(SqStack *s, int *result);
int getTop(SqStack *s, int *result);
void destoryStack(SqStack *s);


int main(){
    SqStack *s = (SqStack*)malloc(sizeof(SqStack));
    initStack(s);
    printf("The stack is empty -- %d\n", stackEmpty(s));
    for(int i = 0; i < 9;i++)
        push(s, i);
    printf("The stack is empty -- %d\n", stackEmpty(s));
    displayStack(s);
    int result = 0;
    pop(s, &result);
    printf("delete element -- %d\n", result);
    displayStack(s);
    getTop(s, &result);
    printf("The top element in the stack is -- %d\n", result);
    destoryStack(s);
}

void initStack(SqStack *s){
    s -> top = -1;
}

void displayStack(SqStack *s){
    for(int i = 0; i <= s -> top;i++){
        if(i == 0)
            printf("%d", s -> data[i]);
        else
            printf(",%d", s -> data[i]);
    }
    printf("\n");
}

int stackEmpty(SqStack *s){
    return s -> top == -1;
}

int push(SqStack *s, int data){
    if (s -> top == MaxSize -1)
        return 0;
    s -> top ++;
    s -> data[s -> top] = data;
    return 1;
}

int pop(SqStack *s, int *result){
    if (stackEmpty(s) == 1)
        return 0;
    *result = s -> data[s -> top];
    s -> top--;
    return 1;
}

int getTop(SqStack *s, int *result){
    *result = s -> data[s -> top];
    return 1;
}

void destoryStack(SqStack *s){
    free(s);
}