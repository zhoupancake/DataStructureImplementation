#include<stdio.h>
#include<stdlib.h>
#include"stack_number.h"

char getHead(NuStack *s);
int calculate(char *str, int length);
int countLength(char *str);

int main(){
    char temp[100], ch;
    int i = 0;
    printf("Please input a postfix expression:");
    while ((ch = getchar()) != '\n' && i < 99) {
        temp[i++] = ch;
    }
    temp[i] = '\0';  // 添加字符串结束符
    double result = calculate(temp, countLength(temp));
    printf("The calculated result of the postfix expression is -- %.2lf\n", result);
    return 0;
}

int countLength(char *str){
    int count = 0;
    while(str[count] != '\0')
        count++;
    return count;
}

char getHead(NuStack *s){
    double temp = 0;
    if(!stackEmpty(s))
        getTop(s, &temp);
    return temp;
}

int calculate(char *str, int length){
    NuStack *numStack = (NuStack*)malloc(sizeof(NuStack));
    initStack(numStack);
    int flag = 1;
    for(int i = 0;i < length;i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            double pre, rear, result;
            pop(numStack, &pre);
            pop(numStack, &rear);
            switch (str[i]){
                case '+': push(numStack, (pre + rear));break;
                case '-': push(numStack, (rear - pre));break;
                case '*': push(numStack, (pre * rear));break;
                case '/': push(numStack, (rear / pre));break;
                default:break;
            }
            flag = 1;
        }
        else if(str[i] == ' '){
            flag = 1;
        }
        else{
            if(flag == 0){
                double temp;
                pop(numStack, &temp);
                push(numStack, (str[i] - '0')+(temp*10));
            }
            else{
                push(numStack, str[i] - '0');
            }
            flag = 0;
        }
    }
    double result = 0;
    if(numStack->length > 1){
        printf("illegal expression input!\n");
        return result;
    }
    pop(numStack, &result);
    destoryStack(numStack);
    return result;
}