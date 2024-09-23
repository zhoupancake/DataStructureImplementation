#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5

void initMatrix(int mat[N][N]);
void initArray(int *arr, int mat[N][N]);
void displayMatrx(int mat[N][N]);
int map(int x, int y);

int main(){
    int mat[N][N], arr[N*N];
    initMatrix(mat);
    displayMatrx(mat);
    initArray(arr, mat);
    printf("The original matrix is:\n");
    displayMatrx(mat);
    printf("Please input a index of the element in (row,col) type:");
    int row,col;
    scanf("%d, %d", &row, &col);
    int index = map(row, col);
    printf("The index of the element in the array is %d, the element is %d\n", index, arr[index]);
    return 0;

}

void initMatrix(int mat[N][N]){
    srand((unsigned int)time(NULL));
    for(int i = 0;i < N;i++)
        for(int j = i;j < N;j++){
            int temp = (rand() % (1000)) + 1;
            mat[i][j] = temp;
            mat[j][i] = temp;
        }
}

void displayMatrx(int mat[N][N]){
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++)
            printf("%3d,", mat[i][j]);
        printf("\n");
    }
}

void initArray(int *arr, int mat[N][N]){
    for(int i = 0;i < N;i++)
        for(int j = 0;j <= i;j++)
            arr[(i+1) * i / 2 + j] = mat[i][j];
}



int map(int row, int col){
    int min = row >= col ? col-1 : row-1;
    int max = row >= col ? row-1 : col-1;
    return (max + 1) * max / 2 + min;
}