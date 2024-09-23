#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
} SqList_s;

void listInit(SqList_s *L);
void displayList(SqList_s *L);
int listInsert(SqList_s *L, int index, int data);
int listDelete(SqList_s *L, int index, int *result);
int locateElem(SqList_s *L, int e);

int main(){
    SqList_s *L = (SqList_s*)malloc(sizeof(SqList_s));
    listInit(L);
    printf("This is the linear list:\n");
    displayList(L);
    listInsert(L, 0, 23);
    displayList(L);
    listInsert(L, 3, 43);
    displayList(L);
    listInsert(L, 1, 23);
    displayList(L);
    listInsert(L, 7, 33);
    listInsert(L, 6, 123);
    listInsert(L, 4, 33);
    listInsert(L, 6, 63);
    displayList(L);
    free(L);
}

void listInit(SqList_s *L){
    for(int i = 0;i < MaxSize;i++){
        L -> data[i] = 0;
    }
}

void displayList(SqList_s *L){
    if(L->length == 0){
        printf("Empty list\n");
        return;
    }
    for(int i = 0;i < L -> length;i++){
        if(i == 0)
            printf("%d", L -> data[i]);
        else
            printf(",%d", L -> data[i]);
    }
}

int listInsert(SqList_s *L, int index, int data){
    if (L -> length + 1 > MaxSize)
        return 0;
    int i = 0;
    for(i = L -> length;i > index;i--)
        L -> data[i] = L -> data[i-1];
    L -> data[i-1] = data;
    L -> length++;
    return 1;
}






