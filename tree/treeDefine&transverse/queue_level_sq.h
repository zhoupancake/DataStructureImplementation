#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int head, rear;
} SqQueue;

void initQueue(SqQueue* s);
void displayQueue(SqQueue *s);
int QueueEmpty(SqQueue *s);
int enQueue(SqQueue *s, int data);
int deQueue(SqQueue *s, int *result);
int getFront(SqQueue *s, int *result);
int getEnd(SqQueue *s, int *result);
void destoryQueue(SqQueue *s);

void initQueue(SqQueue* s){
    s->head = 0;
    s->rear = 0;
}

void displayQueue(SqQueue *s){
    for(int i = s->head; i < s -> rear;i++){
        if(i == s->head)
            printf("%d", s -> data[i]);
        else
            printf(",%d", s -> data[i]);
    }
    printf("\n");
}

int QueueEmpty(SqQueue *s){
    return s->head == s->rear;
}

int enQueue(SqQueue *s, int data){
    if((s->rear + 1) % MaxSize == s->head)
        return 0;
    s->data[s->rear] = data;
    s->rear = (s->rear + 1) % MaxSize;
    return 1;
}

int deQueue(SqQueue *s, int *result){
    if (QueueEmpty(s) == 1)
        return 0;
    *result = s->data[s->head];
    s->head = (s->head + 1) % MaxSize;
    return 1;
}

int getFront(SqQueue *s, int *result){
    *result = s->data[s->head];
    return 1;
}

int getEnd(SqQueue *s, int *result){
    *result = s->data[s->rear-1];
    return 1;
}

void destoryQueue(SqQueue *s){
    free(s);
}