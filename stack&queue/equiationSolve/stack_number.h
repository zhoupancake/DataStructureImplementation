#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct LNode {
    double data;
    struct LNode* next;
} LNode;

typedef struct {
    int length;
    LNode* head;
} NuStack;

void initStack(NuStack* s);
void displayStack(NuStack *s);
int stackEmpty(NuStack *s);
int push(NuStack *s, double data);
int pop(NuStack *s, double *result);
int getTop(NuStack *s, double *result);
void destoryStack(NuStack *s);

void initStack(NuStack* s){
    s->head = (LNode*)malloc(sizeof(LNode));
    s->head->next = NULL;
    s->length = 0;
}

void displayStack(NuStack *s){
    int flag = 0;
    LNode* temp = s->head->next;
    if(temp == NULL){
        printf("Empty Stack\n");
        return;
    }
    while(temp != NULL){
        if(flag == 0){
            printf("%.2lf", temp->data);
            flag = 1;
        }
        else
            printf(",%.2lf", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int stackEmpty(NuStack *s){
    return s->head->next == NULL;
}

int push(NuStack *s, double data){
    if(s->length + 1 >= MaxSize)
        return 0;
    LNode *insert = (LNode*)malloc(sizeof(LNode));
    insert->data = data;
    insert->next = s->head->next;
    s->head->next = insert;
    s->length++;
    return 1;
}

int pop(NuStack *s, double *result){
    if (stackEmpty(s) == 1)
        return 0;
    *result = s->head->next->data;
    s->head->next = s->head->next->next;
    s->length--;
    return 1;
}

int getTop(NuStack *s, double *result){
    *result = s->head->next->data;
    return 1;
}

void destoryStack(NuStack *s){
    LNode *p_mov;
    while(s->head!=NULL){
        p_mov=s->head;
        s->head=p_mov->next;
        free(p_mov);
    }
}