#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef struct TNode_Q{
    int data;
    struct TNode_Q *left;
    struct TNode_Q *right;
}TNode, LiTree;

typedef struct PTNode{
    int data;
    int parent;
} PTNode;

typedef struct PTree{
    PTNode tree[MaxSize];
    int length;
} PTree;


void treeToPTree(PTree *p, LiTree *t, int parent);
void displayTree(PTree* p);
void destroyPTree(PTree *p);


// The function below are used for initiate a tree in normal style
int readArr(int *arr);
void PtreeToTree(PTree *p, LiTree *t, int parent);
void preOrder(LiTree *head);
void sequenceToLink_pre(LiTree *head, int index, int *arr, int length);
void destroyTree(LiTree *head);

int main(){
    int arr[MaxSize];
    int length = readArr(arr);
    LiTree *head = (TNode*)malloc(sizeof(TNode));
    sequenceToLink_pre(head, 1, arr, length);
    printf("The sequence of the pre-order traverse of the tree is:\n");
    preOrder(head);
    printf("\n");
    PTree *t = (PTree*)malloc(sizeof(PTree));
    treeToPTree(t, head, -1);
    displayTree(t);

    LiTree *head_created = (TNode*)malloc(sizeof(TNode));
    head_created->data = t->tree[0].data;
    head_created->left = NULL;
    head_created->right = NULL;
    PtreeToTree(t, head_created, 0);
    printf("The sequence of the pre-order traverse of the tree from parent-stored tree is:\n");
    preOrder(head);
    printf("\n");


    destroyTree(head);
    destroyTree(head_created);
    destroyPTree(t);
}

void treeToPTree(PTree *p, LiTree *t, int parent){
    int index = p->length;
    if(t != NULL){
        p->tree[p->length].data = t->data;
        p->tree[p->length].parent = parent;
        p->length++;
    }
    if(t->left != NULL)
        treeToPTree(p, t->left, index);
    if(t->right != NULL)
        treeToPTree(p, t->right, index);
}

void PtreeToTree(PTree *p, LiTree *t, int parent){
    for(int i = 0;i < p->length;i++){
        if(p->tree[i].parent == parent){
            if(t->left == NULL){
                TNode *temp = (TNode*)malloc(sizeof(TNode));
                temp->data = p->tree[i].data;
                t->left = temp;
                PtreeToTree(p, t->left, i);
                continue;
            }
            if(t->right == NULL){
                TNode *temp = (TNode*)malloc(sizeof(TNode));
                temp->data = p->tree[i].data;
                t->right = temp;
                PtreeToTree(p, t->right, i);
            }
        }
    }
}

void displayTree(PTree* p){
    printf("The array storing the tree in parent storage is:\n");
    for(int i = 0;i < p->length;i++)
        printf("%d %d\t", p->tree[i].data, p->tree[i].parent);
    printf("\n");
}

void destroyPTree(PTree *p){
    free(p);
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