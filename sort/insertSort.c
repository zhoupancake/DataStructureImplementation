#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SqList.h"

void insertSort(SqList *list);
void insertSort_process(SqList *list);

int main(){
    SqList *list = (SqList*)malloc(sizeof(SqList));
    initList(list, 15, 0);
    printf("The list generated randomly is:\n");
    displayList(list, 0);
    insertSort_process(list);
    printf("The sorted list is:\n");
    displayList(list, 0);
    destroyList(list);
    return 0;
}

void insertSort(SqList *list){
    for(int i = 1;i < list->length;i++){
        int j = i;
        while(list->arr[j] < list->arr[j-1] && j > 0){
            list->arr[j] = list->arr[j] + list->arr[j-1];
            list->arr[j-1] = list->arr[j] - list->arr[j-1];
            list->arr[j] = list->arr[j] - list->arr[j-1];
            j--;
        }
    }
}

void insertSort_process(SqList *list){
    for(int i = 1;i < list->length;i++){
        int j = i;
        while(j > 0){
            printf("The elements from 0 to %d are sorted, compare the %d with %d, ", j-1, list->arr[j], list->arr[j-1]);
            if(list->arr[j] < list->arr[j-1]){
                printf("the %d is smaller than the %d, exchange their positions.\n", list->arr[j], list->arr[j-1]);
                list->arr[j] = list->arr[j] + list->arr[j-1];
                list->arr[j-1] = list->arr[j] - list->arr[j-1];
                list->arr[j] = list->arr[j] - list->arr[j-1];
            }
            else
                printf("the %d is greater than the %d, keep their positions.\n", list->arr[j], list->arr[j-1]);
            displayList(list, 0);
            j--;
        }
    }
}