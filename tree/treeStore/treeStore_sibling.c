#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef struct CSNode{
    int data;
    struct CSNode *firstChild, *nextSibling;
} CSNode, CSTree;

typedef struct TNode{
    int data;
    struct TNode *left;
    struct TNode *right;
}TNode, LiTree;


void treeToCSTree(LiTree *head, CSTree *sibling, CSTree *cst);
void displayCSTree(CSTree *head);

int readArr(int *arr);
void sequenceToLink_pre(LiTree *head, int index, int *arr, int length);
void preOrder(LiTree *head);
void destroyTree(LiTree *head);


int main(){
    int arr[MaxSize];
    int length = readArr(arr);
    LiTree *head = (TNode*)malloc(sizeof(TNode));
    sequenceToLink_pre(head, 1, arr, length);
    printf("The sequence of the pre-order traverse of the tree is:\n");
    preOrder(head);
    printf("\n");
    CSTree *cstHead = (CSNode*)malloc(sizeof(CSNode));
    treeToCSTree(head, NULL, cstHead);
    displayCSTree(cstHead);
}

void treeToCSTree(LiTree *head, CSTree *sibling, CSTree *cst){
    if(head != NULL){
        cst->data = head->data;
        cst->nextSibling = sibling;
        cst->firstChild = NULL;
        if(head->left != NULL){
            CSNode *temp_left = (CSNode*)malloc(sizeof(CSNode));
            temp_left->firstChild = NULL;
            temp_left->nextSibling = NULL; 
            cst->firstChild = temp_left;
            CSNode *temp_right = NULL;
            if(head->right != NULL){
                temp_right = (CSNode*)malloc(sizeof(CSNode));
                temp_right->firstChild = NULL;
                temp_right->nextSibling = NULL;
                treeToCSTree(head->right, NULL, temp_right);
            }
            treeToCSTree(head->left, temp_right, temp_left);
        }
        if(head->right != NULL && cst->firstChild == NULL){
            CSNode *temp_left = (CSNode*)malloc(sizeof(CSNode));
            temp_left->firstChild = NULL;
            temp_left->nextSibling = NULL; 
            cst->firstChild = temp_left;
            treeToCSTree(head->right, NULL, temp_left);
        }
    }
    return;
}

void displayCSTree(CSTree *head){
    if(head != NULL)
        printf("%d ", head->data);
    if(head->firstChild != NULL)
        displayCSTree(head->firstChild);
    if(head->nextSibling != NULL)
        displayCSTree(head->nextSibling);
}

void CSTreeToTree(LiTree *parent, LiTree *current, CSTree *cst){
    current->data = cst->data;
    if(cst->firstChild != NULL){
        TNode *temp = (TNode*)malloc(sizeof(TNode));
        current->left = temp;
        CSTreeToTree(current, current->left, cst->firstChild);
    }
    if(cst->nextSibling != NULL){
        TNode *temp = (TNode*)malloc(sizeof(TNode));
        parent->right = temp;
        CSTreeToTree(NULL, parent->right, cst->nextSibling);
    }
    return;
}

void destroyCSTree(CSTree *head){
     if (head != NULL){
        if (head->firstChild != NULL)
            destroyCSTree(head->firstChild);
        if (head->nextSibling != NULL)
            destroyCSTree(head->nextSibling);
        free(head);
    }
}
// The function below are used for initiate a tree in normal style
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

void destroyTree(LiTree *head){
    if (head != NULL){
        if (head->left != NULL)
            destroyTree(head->left);
        if (head->right != NULL)
            destroyTree(head->right);
        free(head);
    }
}