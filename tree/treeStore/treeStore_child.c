#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef struct CNode{
    int child;
    struct CNode *next;    
} CNode;

typedef struct CTBox{
    int data;
    CNode *firstChild;
} CTBox;

typedef struct CTree{
    CTBox tree[MaxSize];
    int length;
    int root;
} CTree;

typedef struct TNode{
    int data;
    struct TNode *left;
    struct TNode *right;
}TNode, LiTree;

void treeToCTree(LiTree *l, CTree *c, int index);
void cTreeToTree(LiTree *l, CTree *c);
void displayCTree(CTree *c);
void destroyCTree(CTree *head);
;
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

    CTree * c = (CTree*)malloc(sizeof(CTree));
    c->length = 0;
    c->tree[0].data = head->data;
    c->root = 0;
    treeToCTree(head, c, -1);
    printf("\n");
    displayCTree(c);
    // destroyTree(head);
    // destroyCTree(c);
}

void treeToCTree(LiTree *l, CTree *c, int parent){
    int index = c->length-1;
    c->tree[index].data = l->data;
    c->tree[index].firstChild = NULL;
    c->length++;
    CNode *temp = (CNode*)malloc(sizeof(CNode));
    temp->child = c->length;
    if(parent != -1)
        temp->next = c->tree[parent].firstChild;
    c->tree[parent].firstChild = temp;
    if(l->left != NULL)
        treeToCTree(l->left, c, index);
    if(l->right != NULL)
        treeToCTree(l->right, c, index);
}

void cTreeToTree(LiTree *l, CTree *c){

}

void displayCTree(CTree *c){
    for(int i = 0;i < c->length;i++){
        printf("%d %d  ",i, c->tree[i].data);
        CNode *temp = c->tree[i].firstChild;
        while(temp != NULL){
            printf("%d ", temp->child);
            temp = temp->next;
        }
        printf("\n");
    }
}

void destroyCTree(CTree *c){
    for(int i = 0;i < c->length;i++){
        CNode *temp = c->tree[i].firstChild;
        while(temp!= NULL){
            CNode *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(c);
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

void destroyTree(LiTree *root){
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        int temp = root->data;
        free(root);
        printf("fuck! %d\n",temp);
        return;
    }
}

