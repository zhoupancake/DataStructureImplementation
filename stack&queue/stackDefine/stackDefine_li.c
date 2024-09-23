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
} LiStack;

void initStack(LiStack* s);
void displayStack(LiStack *s);
int stackEmpty(LiStack *s);
int push(LiStack *s, int data);
int pop(LiStack *s, int *result);
int getTop(LiStack *s, int *result);
void destoryStack(LiStack *s);


int main(){
    LiStack *s = (LiStack*)malloc(sizeof(LiStack));
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

void initStack(LiStack* s){
    s->head = (LNode*)malloc(sizeof(LNode));
    s->head->next = NULL;
    s->length = 0;
}

void displayStack(LiStack *s){
    int flag = 0;
    LNode* temp = s->head->next;
    if(temp == NULL){
        printf("Empty Stack\n");
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

int stackEmpty(LiStack *s){
    return s->head->next == NULL;
}

int push(LiStack *s, int data){
    if(s->length + 1 >= MaxSize)
        return 0;
    LNode *insert = (LNode*)malloc(sizeof(LNode));
    insert->data = data;
    insert->next = s->head->next;
    s->head->next = insert;
    s->length++;
    return 1;
}

int pop(LiStack *s, int *result){
    if (stackEmpty(s) == 1)
        return 0;
    *result = s->head->next->data;
    s->head->next = s->head->next->next;
    return 1;
}

int getTop(LiStack *s, int *result){
    *result = s->head->next->data;
    return 1;
}

void destoryStack(LiStack *s){
    LNode *p_mov;
    while(s->head!=NULL){
        p_mov=s->head;
        s->head=p_mov->next;
        free(p_mov);
    }
}