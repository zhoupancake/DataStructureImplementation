#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SqList.h"
#define IndexMaxSize 5
typedef struct{
    int maxValue;
    int low, high;
} Index;

void initList_partOrder(SqList *list, Index indexs[IndexMaxSize]);
void displayIndexs(Index indexs[IndexMaxSize]);
int blockSearch(SqList *list, Index indexs[IndexMaxSize]);

int main(){
    SqList *list = (SqList*)malloc(sizeof(SqList));
    Index indexs[IndexMaxSize];
    initList_partOrder(list, indexs);
     printf("The list generated randomly is:\n");
    displayList(list);
    printf("The block index of the array is:\n");
    displayIndexs(indexs);
    printf("Please input a target to search:");
    int target = 0;
    scanf("%d", &list->arr[0]);
    printf("The index of the target in the list is: %d\n", blockSearch(list, indexs));
    destroyList(list);
}

void initList_partOrder(SqList *list, Index indexs[IndexMaxSize]){
    srand((unsigned)time(NULL));
    list->arr[0] = 0;
    int currentIndex = 1;
    int lowcase = 20;
    for(int i = 0;i < IndexMaxSize;i++){
        indexs[i].maxValue = lowcase;
        indexs[i].low = 0;
        indexs[i].high = 0;
        lowcase += 20;
    } 
    for(int i = 0;i < IndexMaxSize; i++){
        int length = rand() % (45/IndexMaxSize);
        indexs[i].low = currentIndex;
        for(int j = 0;j < length;j++){
            list->arr[currentIndex] = (rand() % 21) + indexs[i].maxValue - 20;
            currentIndex++;
            list->length++;
        }
        indexs[i].high = currentIndex - 1;
    }
}

void displayIndexs(Index indexs[IndexMaxSize]){
    printf("maxValue low high\n");
    for(int i = 0;i < IndexMaxSize; i++)
        printf("%8d %3d %4d\n", indexs[i].maxValue, indexs[i].low, indexs[i].high);
}

int blockSearch(SqList *list, Index indexs[IndexMaxSize]){
    int low = 0, high = 0, i = 0;
    while(list->arr[0] > indexs[i].maxValue)
        i++;
    low = indexs[i].low;
    high = indexs[i].high;
    for(i = low; i <= high; i++)
        if(list->arr[0] == list->arr[i])
            return i;
    return -1;
}