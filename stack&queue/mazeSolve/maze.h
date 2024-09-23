#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21  // 迷宫的宽度（奇数）
#define HEIGHT 21 // 迷宫的高度（奇数）

int maze[HEIGHT][WIDTH];
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// 函数声明
void generate_maze(int x, int y);
void shuffle(int array[], int n);
void print_maze(int start_x, int start_y, int end_x, int end_y);
void find_start_end(int *start_x, int *start_y, int *end_x, int *end_y);

void run(int arr[HEIGHT][WIDTH]) {
    int start_x, start_y, end_x, end_y;

    // 初始化随机数种子
    srand(time(NULL));

    // 初始化迷宫，全部设置为墙（1）
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }

    // 从(1, 1)开始生成迷宫
    generate_maze(1, 1);

    // 寻找起点和终点
    find_start_end(&start_x, &start_y, &end_x, &end_y);

    // 输出迷宫，标记起点和终点
    print_maze(start_x, start_y, end_x, end_y);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            arr[i][j] = maze[i][j];
        }
    }

    return;
}

void generate_maze(int x, int y) {
    maze[x][y] = 0; // 当前单元设为通路（0）

    // 随机打乱方向
    int dir_order[4] = {0, 1, 2, 3};
    shuffle(dir_order, 4);

    // 遍历每个方向
    for (int i = 0; i < 4; i++) {
        int dx = directions[dir_order[i]][0];
        int dy = directions[dir_order[i]][1];
        int nx = x + dx * 2;
        int ny = y + dy * 2;

        // 检查新坐标是否在迷宫范围内且未访问
        if (nx > 0 && nx < HEIGHT-1 && ny > 0 && ny < WIDTH-1 && maze[nx][ny] == 1) {
            maze[x + dx][y + dy] = 0; // 破墙连通两个单元
            generate_maze(nx, ny);
        }
    }
}

void shuffle(int array[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void print_maze(int start_x, int start_y, int end_x, int end_y) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d,",maze[i][j]);
        }
        printf("\n");
    }
}

void find_start_end(int *start_x, int *start_y, int *end_x, int *end_y) {
    // 起点设置在左上角（1,1）处，终点设置在右下角（HEIGHT-2, WIDTH-2）处
    *start_x = 1;
    *start_y = 1;
    *end_x = HEIGHT - 2;
    *end_y = WIDTH - 2;

    // 打开起点和终点的墙壁
    maze[*start_x-1][*start_y] = 0;
    maze[*end_x+1][*end_y] = 0;
}
