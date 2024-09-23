#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SqList.h"

void insertSort(SqList *list);
void insertSort_process(SqList *list);

int main(){
    SqList *list = (SqList*)malloc(sizeof(SqList));
    initList(list, 15, 1);
    printf("The list generated randomly is:\n");
    displayList(list, 1);
    insertSort(list);
    printf("The sorted list is:\n");
    displayList(list, 1);
    destroyList(list);
    return 0;
}

void insertSort(SqList *list){
    for(int i = 2;i < list->length; i++){
        if(list->arr[i] < list->arr[i-1]){
            list->arr[0] = list->arr[i];
            int j;
            for(j = i-1;list->arr[0] < list->arr[j];j--)
                list->arr[j+1] = list->arr[j];
            list->arr[j+1] = list->arr[0];
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
            displayList(list, 1);
            j--;
        }
    }
}