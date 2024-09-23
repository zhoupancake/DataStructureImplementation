#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5

int upperOrLower(int mat[N][N]);
void displayMatrx(int mat[N][N]);
void lowerTriangle(int mat[N][N]);
void upperTriangle(int mat[N][N]);
void initMatrix_up(int mat[N][N]);
void initMatrix_lower(int mat[N][N]);
void initArray_upper_row(int arr[N*(N+1)/2+1], int mat[N][N]);
int map_upper_row(int row, int col);
void initArray_upper_col(int arr[N*(N+1)/2+1], int mat[N][N]);
int map_upper_col(int row, int col);
void initArray_lower_row(int arr[N*(N+1)/2+1], int mat[N][N]);
int map_lower_row(int row, int col);
void initArray_lower_col(int arr[N*(N+1)/2+1], int mat[N][N]);
int map_lower_col(int row, int col);

int main(){
    //4种情况：上三角行优先， 上三角列优先，下三角行优先, 下三角列优先
    //此处分上下三角分析
    int mat_upper[N][N];
    initMatrix_up(mat_upper);
    printf("The original matrix is:\n");
    displayMatrx(mat_upper);
    int flag = upperOrLower(mat_upper);
    if(flag == 1){
        printf("This metrix is a lower triangle metrix.\n");
        lowerTriangle(mat_upper);
    }
    else if(flag == 2){
        printf("This metrix is an upper triangle metrix.\n");
        upperTriangle(mat_upper);
    }
    else
        printf("This metrix is not upper triangle metrix or lower triangle metrix.\n");
    

    int mat_lower[N][N];
    initMatrix_lower(mat_lower);
    printf("The original matrix is:\n");
    displayMatrx(mat_lower);
    int flag = upperOrLower(mat_lower);
    if(flag == 1){
        printf("This metrix is a lower triangle metrix.\n");
        lowerTriangle(mat_lower);
    }
    else if(flag == 2){
        printf("This metrix is an upper triangle metrix.\n");
        upperTriangle(mat_lower);
    }
    else
        printf("This metrix is not upper triangle metrix or lower triangle metrix.\n");
    return 0;
}

void upperTriangle(int mat[N][N]){
    int arr_row[N*(N+1)/2+1], arr_col[N*(N+1)/2+1];
    initArray_upper_row(arr_row, mat);
    initArray_upper_col(arr_col, mat);
    printf("Please input a index of the element in (row,col) type:");
    int row,col;
    scanf("%d, %d", &row, &col);
    int index_row = map_upper_row(row, col);
    int index_col = map_upper_col(row, col);
    printf("The index of the element in the row-first array is %d, the element is %d\n", index_row, arr_row[index_row]);
    printf("The index of the element in the colum-first array is %d, the element is %d\n", index_col, arr_col[index_col]);

}

void lowerTriangle(int mat[N][N]){
    int arr_row[N*(N+1)/2], arr_col[N*(N+1)/2];
    initArray_lower_row(arr_row, mat);
    initArray_lower_col(arr_col, mat);
    printf("Please input a index of the element in (row,col) type:");
    int row,col;
    scanf("%d, %d", &row, &col);
    int index_row = map_lower_row(row, col);
    int index_col = map_lower_col(row, col);
    printf("The index of the element in the row-first array is %d, the element is %d\n", index_row, arr_row[index_row]);
    printf("The index of the element in the colum-first array is %d, the element is %d\n", index_col, arr_col[index_col]);
}

//return 1 for lower triangle metrix, 2 for upper triangle metrix
int upperOrLower(int mat[N][N]){
    int isUpper = 1;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < i;j++)
            if(mat[i][j] != 0){
                isUpper = 0;
                break;
            }
        if(isUpper == 0)
            break;
    }

    int isLower = 1;
    for(int i = 0;i < N;i++){
        for(int j = i+1;j < N;j++)
            if(mat[i][j] != 0){
                isLower = 0;
                break;
        }
        if(isLower == 0)
            break;
    }
    if(isLower == 0 && isUpper == 1)
        return 2;
    else if(isLower == 1 && isUpper == 0)
        return 1;
    else
        return 0;
}

void initArray_upper_row(int arr[N*(N+1)/2+1], int mat[N][N]){
    for(int row = 0;row < N ;row++)
        for(int col = row;col < N;col++){
            arr[row*N - (row*(row+1)/2) + col] = mat[row][col];
        }
    arr[N*(N+1)/2] = 0;
}

int map_upper_row(int row, int col){
    row--;col--;
    return row > col? N*(N+1)/2 : row*N - (row*(row+1)/2) + col;
}

void initArray_upper_col(int arr[N*(N+1)/2+1], int mat[N][N]){
    for(int row = 0;row < N;row++)
        for(int col = row;col < N;col++)
            arr[row + (col*(col+1))/2] = mat[row][col];
    arr[N*(N+1)/2] = 0;
}

int map_upper_col(int row, int col){
    row--;col--;
    return row > col? N*(N+1)/2 : row + (col*(col+1))/2;
}

void initArray_lower_row(int arr[N*(N+1)/2+1], int mat[N][N]){
    for(int row = 0;row < N;row++)
        for(int col = 0;col <= row;col++)
            arr[col + (row*(row+1))/2] = mat[row][col];
    arr[N*(N+1)/2] = 0;
}

int map_lower_row(int row, int col){
    row--;col--;
    return row < col? N*(N+1)/2 : col + (row*(row+1))/2;
}

void initArray_lower_col(int arr[N*(N+1)/2+1], int mat[N][N]){
    for(int row = 0;row < N;row++)
        for(int col = 0;col <= row;col++)
            arr[col*N - (col*(col+1)/2) + row] = mat[row][col];
    arr[N*(N+1)/2] = 0;
}

int map_lower_col(int row, int col){
    row--;col--;
    return row < col? N*(N+1)/2 : col*N - (col*(col+1)/2) + row;
}

void initMatrix_up(int mat[N][N]){
    srand((unsigned int)time(NULL));
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++){
            if(i > j)
                mat[i][j] = 0;
            else
                mat[i][j] = (rand() % (1000)) + 1;
        }
}

void initMatrix_lower(int mat[N][N]){
    srand((unsigned int)time(NULL));
    for(int i = 0;i < N;i++)
        for(int j = i;j < N;j++){
            mat[i][j] = 0;
            mat[j][i] = (rand() % (1000)) + 1;
        }
}

void displayMatrx(int mat[N][N]){
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++)
            printf("%3d,", mat[i][j]);
        printf("\n");
    }
}