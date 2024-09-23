#include<stdio.h>
#include"Stack.h"

int match(char left, char right);\
int bracketMatch(char* str, int length);

int main(){
    char str[100];
    printf("please input a bracket string: ");
    scanf("%s", str); 
    int count = 0;
    for(count = 0; str[count] != '\0'; count++){}
    printf("The bracket match result is -- %d\n", bracketMatch(str, count));
    return 0;
}

int bracketMatch(char* str, int length){
    SqStack *s = (SqStack*)malloc(sizeof(SqStack));
    initStack(s);
    for(int i = 0;i < length; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            push(s, str[i]);
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
            // there are right bracket left
            char top = 'a';
            if(pop(s, &top) == 0)
                return 0;
            
            // the pop left bracket cannot match the right bracket
            if(match(top, str[i]))
                return 0;
        }
        else{
            printf("invalid input!\n");
            return 0;
        }
    }
    // there are left bracket left
    if(stackEmpty(s) == 0)
        return 0;
    return 1;
}

int match(char left, char right){
    return (left == '(' && right == ')') || (left == '(' && right == ')') || (left == '(' && right == ')');
}