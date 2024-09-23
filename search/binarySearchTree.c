#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MaxSize 15

typedef struct TNode{
    int data;
    struct TNode *left, *right;
}TNode, BSTree;

void initArray(int *arr);
void initBST(int *arr, BSTree *head);
void BSTInsert(BSTree *head, int key);
TNode *BSTSearch(BSTree *head, int key);
TNode *BSTDelete(BSTree *pre, BSTree *head, int key);
void preOrder(BSTree *head);
void destoryTree(BSTree *head);

int main(){
    int arr[MaxSize];
    initArray(arr);
    printf("The keys array generated randomly is:\n");
    for(int i = 0;i < MaxSize;i++)
        printf("%d ", arr[i]);
    printf("\n");
    BSTree *head = (TNode*)malloc(sizeof(TNode));
    initBST(arr, head);
    printf("The pre-order transverse of the generated binary serach tree is:\n");
    preOrder(head);
    printf("\n");
    printf("test the remove operation operation of the binary search tree.\n");
    printf("Please input a target to remove:");
    int removeTarget = 0;
    scanf("%d", &removeTarget);
    BSTDelete(NULL, head, removeTarget);
    printf("The pre-order transverse of the generated binary serach tree after deletion is:\n");
    preOrder(head);
    printf("test the search operation operation of the binary search tree.\n");
    printf("Please input a target to search:");
    int searchTarget = 0;
    scanf("%d", &searchTarget);
    printf("The index of the target in the list is: %d\n", BSTSearch(head,searchTarget)->data);
}

void initArray(int *arr){
    srand(time(NULL));
    for(int i = 0;i < MaxSize;i++)
        arr[i] = rand() % 100;
}

void initBST(int *arr, BSTree *head){
    head->data = arr[0];
    head->left = NULL;
    head->right = NULL;
    for(int i = 1;i < MaxSize;i++)
        BSTInsert(head, arr[i]);
}

void BSTInsert(BSTree *head, int key){
    if(head == NULL)
        return;
    if(head->data < key){
        if(head->right != NULL)
            BSTInsert(head->right, key);
        else{
            TNode *temp = (TNode*)malloc(sizeof(TNode));
            temp->data = key;
            temp->left = NULL;
            temp->right = NULL;
            head->right = temp;
            return;
        }
    }
    else if(head->data > key){
        if(head->left != NULL)
            BSTInsert(head->left, key);
        else{
            TNode *temp = (TNode*)malloc(sizeof(TNode));
            temp->data = key;
            temp->left = NULL;
            temp->right = NULL;
            head->left = temp;
            return;
        }
    }
    else
        return;
}

TNode *BSTSearch(BSTree *head, int key){
    if(head == NULL)
        return NULL;
    if(head->data > key)
        return BSTSearch(head->left, key);
    else if(head->data < key)
        return BSTSearch(head->right, key);
    else
        return head;
}

TNode *BSTDelete(BSTree *pre, BSTree *head, int key){
    if(head == NULL)
        return NULL;
    if(head->data > key)
        BSTDelete(head, head->left, key);
    else if(head->data < key)
        BSTDelete(head, head->right, key);
    else{
        if(head->left == NULL && head->right == NULL){
            free(head);
            if(pre->data > key)
                pre->left = NULL;
            else
                pre->right = NULL;
        }
        else if(head->left != NULL && head->right == NULL){
            if(pre->data > key)
                pre->left = head->left;
            else
                pre->right = head->left;
        }
        else if(head->left == NULL && head->right != NULL){
            if(pre->data > key)
                pre->left = head->right;
            else
                pre->right = head->right;
        }
        else{
            BSTree *temp = head->right, *pre1 = head;
            while(temp->left != NULL){
                pre1 = temp;
                temp = temp->left;
            }
            pre1->left = temp->right;
            head->data = temp->data;
            free(temp);          
        }
    }
}

void preOrder(BSTree *head){
    if(head != NULL)
        printf("%d ", head->data);
    if(head->left != NULL)
        preOrder(head->left);
    if(head->right != NULL)
        preOrder(head->right);
}

void destoryTree(BSTree *head){
    if(head->left != NULL)
        destoryTree(head->left);
    if(head->right != NULL)
        destoryTree(head->right);
    if(head != NULL)
        free(head);
}

