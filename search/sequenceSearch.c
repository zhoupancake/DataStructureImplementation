#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SqList.h"

int sequenceSearch(SqList *list, int target);

int main(){
    SqList *list = (SqList*)malloc(sizeof(SqList));
    initList(list, 15);
    printf("The list generated randomly is:\n");
    displayList(list);
    printf("Please input a target to search:");
    int target = 0;
    scanf("%d", &target);
    printf("The indexof the target in the list is: %d\n", sequenceSearch(list,target));
    destroyList(list);
    return 0;
}

int sequenceSearch(SqList *list, int target){
    for(int i = 0;i < list->length;i++)
        if(list->arr[i] == target)
            return i;
    return -1;
}

