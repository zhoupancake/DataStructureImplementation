#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"queue_level_sq.h"
#define MaxSize_T 100

typedef struct TNode{
    int data;
    int isEmpty;
}TNode;

typedef struct SqTree{
    TNode tree[MaxSize_T];
    int length;
}SqTree;

void initTree(SqTree *t);
void displayTree(SqTree *t);
void preOrder(SqTree *t, int index);
void inOrder(SqTree *t, int index);
void postOrder(SqTree *t, int index);
void levelOrder(SqTree *t, SqQueue *q);
int main(){
    SqTree *t = (SqTree*)malloc(sizeof(SqTree));
    SqQueue *q = (SqQueue*)malloc(sizeof(SqQueue));
    initQueue(q);
    initTree(t);
    displayTree(t);
    printf("The sequence of the pre-order traverse of the tree is:\n");
    preOrder(t, 1);
    printf("\n");
    printf("The sequence of the in-order traverse of the tree is:\n");
    inOrder(t, 1);
    printf("\n");
    printf("The sequence of the post-order traverse of the tree is:\n");
    postOrder(t, 1);
    printf("\n");
     printf("The sequence of the level-order traverse of the tree is:\n");
    enQueue(q, 1);
    levelOrder(t, q);
    destoryQueue(q);
    free(t);
    return 0;
}

void initTree(SqTree *t){
    t->tree[0].data = 0;
    t->tree[0].isEmpty = 1;
    t->tree[1].data = (rand() % (100));
    t->tree[1].isEmpty = 0;
    t->length++;
    srand((unsigned)time(NULL));
    for(int i = 2;i < 15;i++){
        if(t->tree[i/2].isEmpty == 1 || (rand() % (100)) > 90){
            t->tree[i].data = 0;
            t->tree[i].isEmpty = 1;
        }
        else{
            t->tree[i].data = (rand() % (100));
            t->tree[i].isEmpty = 0;
        }
        t->length++;
    }
}

void displayTree(SqTree *t){
    for(int i = 1;i < t->length;i++){
        if(t->tree[i].isEmpty == 1)
            printf("n,");
        else
            printf("%d,", t->tree[i].data);
    }
    printf("\n");
}

void preOrder(SqTree *t, int index){
    if(t->tree[index].isEmpty == 0)
        printf("%d ", t->tree[index].data);
    else
        return;
    if(index*2 < t->length && t->tree[index*2].isEmpty == 0)
        preOrder(t, index*2);  
    if(index*2+1 < t->length && t->tree[index*2+1].isEmpty == 0)
        preOrder(t, index*2+1);  
    return;
}
void inOrder(SqTree *t, int index){
    if(index*2+1 < t->length && t->tree[index*2].isEmpty == 0)
        inOrder(t, index*2);  
    if(t->tree[index].isEmpty == 0)
        printf("%d ", t->tree[index].data);
    else
        return;
    if(index*2+1 < t->length && t->tree[index*2+1].isEmpty == 0)
        inOrder(t, index*2+1);
    return;
}
void postOrder(SqTree *t, int index){
    if(index*2 < t->length && t->tree[index*2].isEmpty == 0)
        postOrder(t, index*2);  
    if(index*2+1 < t->length && t->tree[index*2+1].isEmpty == 0)
        postOrder(t, index*2+1);
    if(t->tree[index].isEmpty == 0)
        printf("%d ", t->tree[index].data);
    else
        return;
    return;
}

void levelOrder(SqTree *t, SqQueue *q){
    if(!QueueEmpty(q)){
        int index;
        deQueue(q, &index);
        printf("%d ", t->tree[index].data);
        if(index*2 < t->length && t->tree[index*2].isEmpty == 0)
            enQueue(q, index*2);
        if(index*2+1 < t->length && t->tree[index*2+1].isEmpty == 0)
            enQueue(q, index*2+1);
        levelOrder(t, q);
    }
}

