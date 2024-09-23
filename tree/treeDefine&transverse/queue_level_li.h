#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct TNode_Q{
    int data;
    struct TNode_Q *left;
    struct TNode_Q *right;
}TNode, LiTree;

typedef struct {
    TNode data[MaxSize];
    int head, rear;
} SqQueue;

void initQueue(SqQueue* s);
void displayQueue(SqQueue *s);
int QueueEmpty(SqQueue *s);
int enQueue(SqQueue *s, TNode *data);
int deQueue(SqQueue *s, TNode *result);
int getFront(SqQueue *s, TNode *result);
int getEnd(SqQueue *s, TNode *result);
void destoryQueue(SqQueue *s);

void initQueue(SqQueue* s){
    s->head = 0;
    s->rear = 0;
}

void displayQueue(SqQueue *s){
    for(int i = s->head; i < s -> rear;i++){
        if(i == s->head)
            printf("%d", s -> data[i].data);
        else
            printf(",%d", s -> data[i].data);
    }
    printf("\n");
}

int QueueEmpty(SqQueue *s){
    return s->head == s->rear;
}

int enQueue(SqQueue *s, TNode *data){
    if((s->rear + 1) % MaxSize == s->head)
        return 0;
    s->data[s->rear].data = data->data;
    s->data[s->rear].left = data->left;
    s->data[s->rear].right = data->right;
    s->rear = (s->rear + 1) % MaxSize;
    return 1;
}

int deQueue(SqQueue *s, TNode *result){
    if (QueueEmpty(s) == 1)
        return 0;
    result->data = s->data[s->head].data;
    result->left = s->data[s->head].left;
    result->right = s->data[s->head].right;
    s->head = (s->head + 1) % MaxSize;
    return 1;
}

int getFront(SqQueue *s, TNode *result){
    result->data = s->data[s->head].data;
    result->left = s->data[s->head].left;
    result->right = s->data[s->head].right;
    return 1;
}

int getEnd(SqQueue *s, TNode *result){
    result->data = s->data[s->rear-1].data;
    result->left = s->data[s->rear-1].left;
    result->right = s->data[s->rear-1].right;
    return 1;
}

void destoryQueue(SqQueue *s){
    free(s);
}