#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int length;
} SqList_s;

typedef struct {
    int *data;
    int length;
    int maxLength;
} SqList_d;


