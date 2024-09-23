#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MaxSize 10

typedef struct TNode{
    int data;
    int isEmpty;
}TNode;

typedef struct SqTree{
    TNode tree[100];
    int length;
}BSTree;

void initArray(int *arr);
void initBST(int *arr, BSTree *head);
void BSTInsert(BSTree *head, int index, int key);
int BSTSearch(BSTree *head, int index, int key);
int BSTDelete(BSTree *head, int index, int key);
void preOrder(BSTree *t, int index);
void destoryTree(BSTree *head);

int main(){
    int arr[MaxSize];
    initArray(arr);
    printf("The keys array generated randomly is:\n");
    for(int i = 0;i < MaxSize;i++)
        printf("%d ", arr[i]);
    printf("\n");
    BSTree *head = (BSTree*)malloc(sizeof(BSTree));
    initBST(arr, head);
    printf("The pre-order transverse of the generated binary serach tree is:\n");
    preOrder(head, 1);
    printf("\n");
    printf("Please input a target to search:");
    int target = 0;
    scanf("%d", &target);
    printf("The index of the target in the list is: %d\n", BSTSearch(head,1, target));
}

void initArray(int *arr){
    srand(time(NULL));
    for(int i = 0;i < MaxSize;i++)
        arr[i] = rand() % 100;
}

void initBST(int *arr, BSTree *head){
    for(int i = 0;i < MaxSize;i++)
        head->tree[i].isEmpty = 1;
    for(int i = 0;i < MaxSize;i++)
        BSTInsert(head, 1, arr[i]);
}

void BSTInsert(BSTree *head, int index, int key){
    printf("%d\n", key);
    if(head->tree[index].isEmpty == 1){
        head->tree[index].data = key;
        head->tree[index].isEmpty = 0;
        head->length++;
    }
    else{
        printf("fuck\n");
        if(head->tree[index].data > key)
            BSTInsert(head, index*2, key);
        else if(head->tree[index].data < key)
            BSTInsert(head, index*2 + 1, key);
        else
            return;
    }

}

int BSTSearch(BSTree *head, int index, int key){
    if(head == NULL)
        return -1;
    if(head->tree[index].data > key)
        return BSTSearch(head, index*2, key);
    else if(head->tree[index].data < key)
        return BSTSearch(head, index*2 + 1, key);
    else
        return head->tree[index].data;
}

int BSTDelete(BSTree *head, int index, int key){}

void preOrder(BSTree *t, int index){
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

void destoryTree(BSTree *head){
    free(head);
}

