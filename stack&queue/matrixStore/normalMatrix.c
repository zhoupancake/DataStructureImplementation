#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define HEIGHT 3
#define WIDTH 10

void initMatrix(int mat[HEIGHT][WIDTH]);
void initArray_row(int *arr, int mat[HEIGHT][WIDTH]);
void initArray_col(int *arr, int mat[HEIGHT][WIDTH]);
void displayMatrx(int mat[HEIGHT][WIDTH]);
int map_row(int x, int y);
int map_col(int x, int y);


int main(){
    int mat[HEIGHT][WIDTH], arr_row[HEIGHT*WIDTH], arr_col[HEIGHT*WIDTH];
    initMatrix(mat);
    initArray_row(arr_row, mat);
    initArray_col(arr_col, mat);
    printf("The original matrix is:\n");
    displayMatrx(mat);
    printf("Please input a index of the element in (row,col) type:");
    int row,col;
    scanf("%d, %d", &row, &col);
    int index_row = map_row(row, col), index_col=map_col(row, col);
    printf("The index of the element in row-first array is %d, the element is %d\n", index_row, arr_row[index_row]);
    printf("The index of the element in col-first array is %d, the element is %d\n", index_col, arr_col[index_col]);
    return 0;
}

void initMatrix(int mat[HEIGHT][WIDTH]){
    srand((unsigned int)time(NULL));
    for(int i = 0;i < HEIGHT;i++)
        for(int j = 0;j < WIDTH;j++)
            mat[i][j] = (rand() % (1000)) + 1;
}

void initArray_row(int *arr, int mat[HEIGHT][WIDTH]){
    for(int i = 0;i < HEIGHT;i++)
        for(int j = 0;j < WIDTH;j++)
            arr[i*WIDTH+j] = mat[i][j];
}

void initArray_col(int *arr, int mat[HEIGHT][WIDTH]){
    for(int i = 0;i < WIDTH;i++)
        for(int j = 0;j < HEIGHT;j++)
            arr[i*HEIGHT+j] = mat[j][i];
}

void displayMatrx(int mat[HEIGHT][WIDTH]){
    for(int i = 0;i < HEIGHT;i++){
        for(int j = 0;j < WIDTH;j++)
            printf("%3d,", mat[i][j]);
        printf("\n");
    }
}

int map_row(int row, int col){
    return (row - 1) * WIDTH + (col - 1);
}

int map_col(int row, int col){
    return (col - 1) * HEIGHT + (row - 1);
}