#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void readString(char *str, int max_length);
void nextArray(int *arr, char *pattern);
void nextevalArray(int *next, int *nexteval, char *pattern);
int KMP(char *target, char *pattern, int *next);
void displayArr(int *arr, int length);


int main() {
    char target[100], pattern[20];
    printf("Please input the target string: ");
    readString(target, sizeof(target));
    printf("Please input the matching string: ");
    readString(pattern, sizeof(pattern));
    int next[pattern[0]+1], nexteval[pattern[0]+1];
    nextArray(next, pattern);
    nextevalArray(next, nexteval, pattern);
    printf("The next array is: ");
    displayArr(next, pattern[0]+1);
    printf("The nexteval array is: ");
    displayArr(nexteval, pattern[0]+1);
    printf("The match index acquired by next array is %d\n", KMP(target, pattern, next));
    printf("The match index acquired by nexteval array is %d\n", KMP(target, pattern, nexteval));

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

void nextArray(int *next, char *pattern){
    next[0] = 0;
    next[1] = 0;
    next[2] = 1;
    char temp[pattern[0]];
    for(int i = 0;i <= pattern[0]; i++)
        temp[i] = pattern[i];
    int fill = 3;
    // loop to fill the next array
    while(fill <= pattern[0]){
        int i = 1, j = 1, offset = 1;
        // loop to compare the prefix part
        while(offset <= fill -1){
            int sameFlag = 1;
            for(j = 1, i = j + offset;i < fill && j < temp[0]; i++, j++){
                if(temp[i] != pattern[j]){
                    sameFlag = 0;
                    break;
                }
            }
            if(sameFlag == 1){
                next[fill] = j;
                break;
            }
            offset++;
        }
        fill++;
    }
}

void nextevalArray(int *next, int *nexteval, char *pattern){
    nexteval[0] = pattern[0];
    nexteval[1] = 0;
    for(int i = 2;i <= pattern[0];i++){
        if(pattern[next[i]] == pattern[i])
            nexteval[i] = nexteval[next[i]];
        else
            nexteval[i] = next[i];
    }
}

int KMP(char *target, char *pattern, int *next){
    int i = 1, j = 1;
    while(i <= target[0] && j <= pattern[0]){
        if(j == 0 || target[i] == pattern[j]){
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if(j > pattern[0]) return i - pattern[0];
    else return 0;
}

void displayArr(int *arr, int length){
    for(int i = 0;i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}