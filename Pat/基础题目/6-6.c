#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}
// 5! + 3! + 6! = 846
/* 你的代码将被嵌在这里 */
int FactorialSum( List L ){
    int factorial[12];
    factorial[0] = 1;
    int sum = 0;
    int i = 1;
    int max = 0;
    while(L){
        if(max < L->Data){
            max = L->Data;
            while (i <= max)
            {
                factorial[i] = factorial[i-1] * i;
                i++;
            }
        }
        sum += factorial[L->Data];
        L = L->Next;
    }
    return sum;
}