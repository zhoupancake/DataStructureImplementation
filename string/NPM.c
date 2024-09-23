#include<stdio.h>
#include<stdlib.h>

int NPM(char *target, char *pattern);
void readString(char *str, int max_length);

int main() {
    char target[100], pattern[20];
    printf("Please input the target string: ");
    readString(target, sizeof(target));
    printf("Please input the matching string: ");
    readString(pattern, sizeof(pattern));
    NPM(target, pattern);

    printf("The match index is %d\n");

    return 0;
}


void readString(char *str, int max_length) {
    int length = 1;

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF && length < max_length - 1) {
        str[length] = ch;
        length++;
    }
    str[length] = '\0';
    str[0] = (char)length-1;
    str[length + 1] = '\0';
}


int NPM(char *target, char *pattern){
    int i = 1, j = 1;
    while(i <= target[0] && j <= pattern[0]){
        if(target[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > pattern[0]) return i - pattern[0];
    else return 0;
}