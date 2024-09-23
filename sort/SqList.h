#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxSize 50

typedef struct {
    int arr[MaxSize];
    int length;
}SqList;

void initList(SqList *list, int length, int sentryFlag);
void displayList(SqList *list, int sentryFlag);
void destroyList(SqList *list);

void initList(SqList *list, int length, int sentryFlag){
    srand((unsigned)time(NULL));
    if(sentryFlag == 0){
        for(int i = 0;i < length;i++){
            list->arr[i] = rand() % (100);
            list->length++;
        }
    }
    else{
        list->arr[0] = 0;
        for(int i = 1;i < length;i++){
            list->arr[i] = rand() % (100);
            list->length++;
        }
    }
}

void displayList(SqList *list, int sentryFlag){
    if(sentryFlag == 0)
        for(int i = 0;i < list->length;i++)
            printf("%d ", list->arr[i]);
    else
        for(int i = 0;i < list->length;i++)
            printf("%d ", list->arr[i]);
    printf("\n");
}

void destroyList(SqList *list){
    free(list);
}