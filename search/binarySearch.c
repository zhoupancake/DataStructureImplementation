#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SqList.h"

void insertSort(SqList *list);
int binarySearch(SqList *list);


int main(){
    SqList *list = (SqList*)malloc(sizeof(SqList));
    initList(list, 15);
    insertSort(list);
    printf("The list generated randomly is:\n");
    displayList(list);
    printf("Please input a target to search:");
    int target = 0;
    scanf("%d", &list->arr[0]);
    printf("The index of the target in the list is: %d\n", binarySearch(list));
    destroyList(list);
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

int binarySearch(SqList *list){
    int low = 1, high = list->length, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(list->arr[mid] == list->arr[0])
            return mid;
        else if(list->arr[mid] > list->arr[0])
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return -1;
}