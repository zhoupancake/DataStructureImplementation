#include<stdio.h>
#include<stdlib.h>

#define MaxSize 1000

typedef struct LNode {
    int order;
    int *position;
    int dirt;
    struct LNode* next;
} LNode;

typedef struct {
    int length;
    LNode* head;
} LiStack;

void initStack(LiStack* s);
void displayStack(LiStack *s);
int stackEmpty(LiStack *s);
int push(LiStack *s, int order, int position[2], int dirt);
int pop(LiStack *s, int* order, int *position, int* dirt);
int getTop(LiStack *s, int* order, int *position, int* dirt);
void destoryStack(LiStack *s);

void initStack(LiStack* s){
    s->head = (LNode*)malloc(sizeof(LNode));
    s->head->next = NULL;
    s->length = 0;
}

void displayStack(LiStack *s){
    int count = 1;
    LNode* temp = s->head->next;
    if(temp == NULL){
        printf("Empty Stack\n");
        return;
    }
    while(temp != NULL){
        printf("step %d: position (%d, %d) move ", temp->order, temp->position[0], temp->position[1]);
        switch (temp->dirt){
            case 3:
                printf("up\n");
                break;
            case 1:
                printf("down\n");
                break;
            case 2:
                printf("to left\n");
                break;
            case 0:
                printf("to right\n");
                break;
            default:
                break;
        }
        temp = temp->next;
    }
}

int stackEmpty(LiStack *s){
    return s->head->next == NULL;
}

int push(LiStack *s, int order, int position[2], int dirt){
    if(s->length + 1 >= MaxSize)
        return 0;
    LNode *insert = (LNode*)malloc(sizeof(LNode));
    insert->position = position;
    insert->order = order;
    insert->dirt = dirt;
    insert->next = s->head->next;
    s->head->next = insert;
    s->length++;
    return 1;
}

int pop(LiStack *s, int *order, int *position, int *dirt){
    if (stackEmpty(s) == 1)
        return 0;
    *order = s->head->next->order;
    position = s->head->next->position;
    *dirt = s->head->next->dirt;
    s->head->next = s->head->next->next;
    return 1;
}

int getTop(LiStack *s, int *order, int *position, int *dirt){
    *order = s->head->next->order;
    position = s->head->next->position;
    *dirt = s->head->next->dirt;
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