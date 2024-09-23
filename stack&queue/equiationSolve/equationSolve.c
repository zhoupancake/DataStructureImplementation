#include<stdio.h>
#include<stdlib.h>
#include"stack_equation.h"


int middle2Back(char *str, int length, char *result);
char getHead(LiStack *s);
int countLength(char *str);

int main(){
    char str[100];
    printf("Please input an infix expression:");
    scanf("%s", str);
    int length = countLength(str);
    char result[length*2];
    middle2Back(str, length, result);
    printf("%s\n", result);
}

int countLength(char *str){
    int count = 0;
    while(str[count] != '\0')
        count++;
    return count;
}



char getHead(LiStack *s){
    char temp = ' ';
    if(!stackEmpty(s))
        getTop(s, &temp);
    return temp;
}

int middle2Back(char *str, int length, char *result){
    printf("length %d\n", length);
    LiStack *s = (LiStack*)malloc(sizeof(LiStack));
    initStack(s);

    char popResult = 'a';
    int index = 0;

    for(int i = 0;i < length;i++){
        if(str[i] == '(')
            push(s, '(');
        
        else if(str[i] == ')'){
            while(getHead(s) != '(' && getHead(s) != ' '){
                pop(s, &popResult);
                result[index++] = popResult;
            }
            if(getHead(s) == '('){
                char trash = 't';
                pop(s, &trash);
            }
        }

        else if(str[i] == '+' || str[i] == '-'){
            result[index++] = ' ';
            while(getHead(s) != '(' && getHead(s) != ' '){
                pop(s, &popResult);
                result[index++] = popResult;
            }
            push(s, str[i]);
        }
        
        else if(str[i] == '*' || str[i] == '/'){
            result[index++] = ' ';
            while(getHead(s) != '(' && getHead(s) != '+' && getHead(s) != '-' && getHead(s) != ' '){
                pop(s, &popResult);
                result[index++] = popResult;
            }
            push(s, str[i]);
        }

        else{
            result[index++] = str[i];
        }
    }

    while(!stackEmpty(s)){
        pop(s, &popResult);
        result[index++] = popResult;
        printf("index %d %s\n", index, result);
    }
    destoryStack(s);
    return 1;
}