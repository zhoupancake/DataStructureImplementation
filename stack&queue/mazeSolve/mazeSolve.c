#include<stdio.h>
#include<stdlib.h>
#include"Stack_maze.h"
#include"maze.h"
#define MAX_INT 65535
#define WEITH 21
#define HEIGHT 21
int mazeSolve(int maze[HEIGHT][WEITH], int start[2], int end[2]);
void initVisited(int visited[HEIGHT][WEITH]);
int legalMove(int position[2], int move, int maze[HEIGHT][WEITH], int visited[HEIGHT][WEITH]);

int mazeSolve(int maze[HEIGHT][WEITH], int start[2], int end[2]){
    int visited[HEIGHT][WEITH];
    initVisited(visited);
    LiStack *s = (LiStack*)malloc(sizeof(LiStack));
    initStack(s);
    int current[2] = {start[0], start[1]};
    while(current[0] != end[0] && current[1] != end[1]){
        if(legalMove(current, 0, maze, visited)){
            push(s, s->length + 1, current, 0);
            current[1] = current[1] + 1;
            visited[current[0]][current[1]] = 1;
            continue;
        }
        if(legalMove(current, 1, maze, visited) == 1){
            push(s, s->length + 1, current, 1);
            current[0] = current[0] + 1;
            visited[current[0]][current[1]] = 1;
            continue;
        }
        if(legalMove(current, 2, maze, visited) == 1){
            push(s, s->length + 1, current, 2);
            current[1] = current[1] - 1;
            visited[current[0]][current[1]] = 1;
            continue;
        }
        if(legalMove(current, 3, maze, visited) == 1){
            push(s, s->length + 1, current, 3);
            current[0] = current[0] - 1;
            visited[current[0]][current[1]] = 1;
            continue;
        }
        int order = 0, dirt = 0;
        int position[2] = {0,0};
        pop(s, &order, position, &dirt);
        current[0] = position[0];
        current[1] = position[1];
    }
    displayStack(s);
    destoryStack(s);
    return 0;
}

void initVisited(int visited[HEIGHT][WEITH]){
    for(int i = 0;i < HEIGHT;i++)
        for(int j = 0;j < WEITH;j++)
            visited[i][j] = 0;
}

int legalMove(int position[2], int move, int maze[HEIGHT][WEITH], int visited[HEIGHT][WEITH]){
    switch (move){
        case 3:
            if(position[0] == 0) 
                return 0; 
            else{
                if(maze[position[0]-1][position[1]] == 1 || visited[position[0]-1][position[1]] == 1)
                    return 0; 
                return 1;
            }
        case 1:
            if(position[0] == HEIGHT) 
                return 0; 
            else{
                if(maze[position[0]+1][position[1]] == 1 || visited[position[0]+1][position[1]] == 1)
                    return 0; 
                return 1;
            }
        case 2:
            if(position[1] == 0) 
                return 0; 
            else{
                if(maze[position[0]][position[1]-1] == 1 || visited[position[0]][position[1]-1] == 1)
                    return 0; 
                return 1;
            }
        case 0:
            if(position[1] == WEITH) 
                return 0; 
            else{
                if(maze[position[0]][position[1]+1] == 1 || visited[position[0]][position[1]+1] == 1)
                    return 0; 
                return 1;
            }
        default:return 0;
    }
}


int main(){
    int maze[HEIGHT][WEITH];
    run(maze);
    int start[2] = {0,1}, end[2] = {20, 20};
    mazeSolve(maze, start, end);
    return 0;
}