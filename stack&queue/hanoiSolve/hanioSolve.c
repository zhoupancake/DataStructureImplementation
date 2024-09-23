#include<stdio.h>
#include<stdlib.h>
#include"stack_hanoi.h"

void hanioSolve(int moveNum, LiStack *start, LiStack *middle, LiStack *end);

int main(){
    LiStack* A = (LiStack*)malloc(sizeof(LiStack));initStack(A, 'A');
    LiStack* B = (LiStack*)malloc(sizeof(LiStack));initStack(B, 'B');
    LiStack* C = (LiStack*)malloc(sizeof(LiStack));initStack(C, 'C');

    // init the hanoi puzzle.
    int target = 4;
    for(int i = target;i > 0;i--)
        push(A, i);

    hanioSolve(target, A, B, C);    
}

void hanioSolve(int moveNum, LiStack *start, LiStack *middle, LiStack *end){
    if(moveNum == 1){
        int startPop;
        pop(start, &startPop);
        push(end, startPop);
        printf("move %d from %c to %c\n", startPop, start->name, end->name);
        return;
    }
    hanioSolve(moveNum-1, start, end, middle);
    hanioSolve(1, start, middle, end);
    hanioSolve(moveNum-1, middle, start, end);
    return;
}