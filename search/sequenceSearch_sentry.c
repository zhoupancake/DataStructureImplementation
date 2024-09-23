#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SqList.h"

int sequenceSearch_sentry(SqList *list);

int main(){
    SqList *list = (SqList*)malloc(sizeof(SqList));
    initList(list, 15);
    printf("The list generated randomly is:\n");
    displayList(list);
    printf("Please input a target to search:");
    int target = 0;
    scanf("%d", &list->arr[0]);
    printf("The index of the target in the list is: %d\n", sequenceSearch_sentry(list));
    destroyList(list);
    return 0;
}

int sequenceSearch_sentry(SqList *list){
    for(int i = list->length-1;i > 0;i--){
        printf("%d\n", list->arr[i]);
        if(list->arr[i] == list->arr[0])
            return i;
    }
    return 0;
}

