#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxSize 50

typedef struct {
    int arr[MaxSize];
    int length;
}SqList;

void initList(SqList *list, int length);
void displayList(SqList *list);
void destroyList(SqList *list);

void initList(SqList *list, int length){
    srand((unsigned)time(NULL));
    for(int i = 1;i < length;i++){
        list->arr[i] = rand() % (100);
        list->length++;
    }
}

void displayList(SqList *list){
    for(int i = 1;i < list->length;i++)
        printf("%d ", list->arr[i]);
    printf("\n");
}

void destroyList(SqList *list){
    free(list);
}