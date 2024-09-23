#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef struct {
    char data[MaxSize];
    int top;
} SqStack;

void initStack(SqStack *s);
void displayStack(SqStack *s);
int stackEmpty(SqStack *s);
int push(SqStack *s, char data);
int pop(SqStack *s, char *result);
int getTop(SqStack *s, char *result);
void destoryStack(SqStack *s);

void initStack(SqStack *s){
    s -> top = -1;
}

void displayStack(SqStack *s){
    for(int i = 0; i <= s -> top;i++){
        if(i == 0)
            printf("%c", s -> data[i]);
        else
            printf(",%c", s -> data[i]);
    }
    printf("\n");
}

int stackEmpty(SqStack *s){
    return s -> top == -1;
}

int push(SqStack *s, char data){
    if (s -> top == MaxSize -1)
        return 0;
    s -> top ++;
    s -> data[s -> top] = data;
    return 1;
}

int pop(SqStack *s, char *result){
    if (stackEmpty(s) == 1)
        return 0;
    *result = s -> data[s -> top];
    s -> top--;
    return 1;
}

int getTop(SqStack *s, char *result){
    *result = s -> data[s -> top];
    return 1;
}

void destoryStack(SqStack *s){
    free(s);
}