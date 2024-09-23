#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode;

typedef struct {
    int length;
    LNode* head;
    LNode* tail;
} LiQueue;

void initQueue(LiQueue* s);
void displayQueue(LiQueue *s);
int QueueEmpty(LiQueue *s);
int push(LiQueue *s, int data);
int pop(LiQueue *s, int *result);
int getFront(LiQueue *s, int *result);
int getEnd(LiQueue *s, int *result);
void destoryQueue(LiQueue *s);


int main(){
    LiQueue *s = (LiQueue*)malloc(sizeof(LiQueue));
    initQueue(s);
    printf("The Queue is empty -- %d\n", QueueEmpty(s));
    for(int i = 0; i < 9;i++)
        push(s, i);
    printf("The Queue is empty -- %d\n", QueueEmpty(s));
    displayQueue(s);
    int result = 0;
    pop(s, &result);
    printf("delete element -- %d\n", result);
    displayQueue(s);
    int front = 0, end = 0;
    getFront(s, &front);
    getEnd(s, &end);
    printf("The head element in the Queue is -- %d\n", front);
    printf("The tail element in the Queue is -- %d\n", end);
    destoryQueue(s);
}

void initQueue(LiQueue* s){
    s->head = (LNode*)malloc(sizeof(LNode));
    s->head->next = NULL;
    s->tail = s->head;
    s->length = 0;
}

void displayQueue(LiQueue *s){
    int flag = 0;
    LNode* temp = s->head->next;
    if(temp == NULL){
        printf("Empty Queue\n");
        return;
    }
    while(temp != NULL){
        if(flag == 0){
            printf("%d", temp->data);
            flag = 1;
        }
        else
            printf(",%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int QueueEmpty(LiQueue *s){
    return s->head->next == NULL;
}

int push(LiQueue *s, int data){
    if(s->length + 1 >= MaxSize)
        return 0;
    LNode *insert = (LNode*)malloc(sizeof(LNode));
    insert -> next = NULL;
    insert -> data = data;
    s -> tail -> next = insert;
    s -> tail = insert;
    s -> length++;
    return 1;
}

int pop(LiQueue *s, int *result){
    if (QueueEmpty(s) == 1)
        return 0;
    *result = s->head->next->data;
    s->head->next = s->head->next->next;
    s->length--;
    return 1;
}

int getFront(LiQueue *s, int *result){
    *result = s->head->next->data;
    return 1;
}

int getEnd(LiQueue *s, int *result){
    *result = s->tail->data;
    return 1;
}

void destoryQueue(LiQueue *s){
    LNode *p_mov;
    while(s->head!=NULL){
        p_mov=s->head;
        s->head=p_mov->next;
        free(p_mov);
    }
}