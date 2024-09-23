#include<stdio.h>
#include<stdlib.h>
#include"queue_level_li.h"
#define MaxSize_T 100

// typedef struct TNode{
//     int data;
//     struct TNode *left;
//     struct TNode *right;
// }TNode, LiTree;

int readArr(int *arr);
void sequenceToLink_pre(LiTree *head, int index, int *arr, int length);
void preOrder(LiTree *head);
void inOrder(LiTree *head);
void postOrder(LiTree *head);
void levelOrder(SqQueue *queue);
void destoryTree(LiTree *head);


int main(){
    // printf("Please input a bi-tree stored array splited with \",\" and null node with \"n\"\n");
    int arr[MaxSize_T];
    int length = readArr(arr);
    LiTree *head = (TNode*)malloc(sizeof(TNode));
    SqQueue *queue = (SqQueue*)malloc(sizeof(SqQueue));
    sequenceToLink_pre(head, 1, arr, length);
    printf("The sequence of the pre-order traverse of the tree is:\n");
    preOrder(head);
    printf("\n");
    printf("The sequence of the in-order traverse of the tree is:\n");
    inOrder(head);
    printf("\n");
    printf("The sequence of the post-order traverse of the tree is:\n");
    postOrder(head);
    printf("\n");
    printf("The sequence of the level-order traverse of the tree is:\n");
    enQueue(queue, head);
    levelOrder(queue);
    destoryQueue(queue);
    destoryTree(head);
    return 0;
    
    
}

int readArr(int *arr){
    // char temp[100], ch;
    // int i = 0;
    // while ((ch = getchar()) != '\n' && i < 99) {
    //     temp[i++] = ch;
    // }
    // temp[i] = '\0';  // 添加字符串结束符

    char temp[] = "41,15,52,3,45,67,26,n,10,25,0,27";
    int i = 0;
    while(temp[i] != '\0')
        i++;
    printf("The tree stored in array is:\n");
    printf("%s\n", temp);

    int num = 0;
    int index = 1;
    arr[0] = 0;
    for(int j = 0;j < i;j++){
        if(temp[j] == 'n'){
            arr[index++] = -1;
            j++;
        }
        else if(temp[j] == ','){
            arr[index++] = num;
            num = 0;
        }
        else{
            num *= 10;
            num += temp[j] - '0';
        }
    }
    arr[index++] = num;
    return index;
}

void sequenceToLink_pre(LiTree *head, int index, int *arr, int length){
    if(arr[index] != -1){
        head->data = arr[index];
        head->left = NULL;
        head->right = NULL;
    }
    else
        free(head);
    if(index*2 < length && arr[index*2] != -1){
        head->left = (TNode*)malloc(sizeof(TNode));
        sequenceToLink_pre(head->left, index*2, arr, length);
    }  
    if(index*2+1 < length && arr[index*2+1] != -1){
        head->right = (TNode*)malloc(sizeof(TNode));
        sequenceToLink_pre(head->right, index*2+1, arr, length);
    }  
}

void preOrder(LiTree *head){
    if(head != NULL)
        printf("%d ", head->data);
    if(head->left != NULL)
        preOrder(head->left);
    if(head->right != NULL)
        preOrder(head->right);
}

void inOrder(LiTree *head){
    if(head->left != NULL)
        inOrder(head->left);
    if(head != NULL)
        printf("%d ", head->data);
    if(head->right != NULL)
        inOrder(head->right);
}

void postOrder(LiTree *head){
    if(head->left != NULL)
        postOrder(head->left);
    if(head->right != NULL)
        postOrder(head->right);
    if(head != NULL)
        printf("%d ", head->data);
}

void levelOrder(SqQueue *queue){
    if(!QueueEmpty(queue)){
        TNode* temp = (TNode*)malloc(sizeof(TNode));
        deQueue(queue, temp);
        printf("%d ", temp->data);
        if(temp->left != NULL)
            enQueue(queue, temp->left);
        if(temp->right != NULL)
            enQueue(queue, temp->right);
        levelOrder(queue);
    }
}

void destoryTree(LiTree *head){
    if(head->left != NULL)
        destoryTree(head->left);
    if(head->right != NULL)
        destoryTree(head->right);
    if(head != NULL)
        free(head);
}