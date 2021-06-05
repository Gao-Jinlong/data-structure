#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;

    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Count_Digit ( const int N, const int D ){
    int num = N;
    int count = 0;
    if ( N == 0 && D == 0){
        return 1;    
    }
    if (num < 0)
    {
        num *= -1;
    }
    for(;num > 0;num /= 10){
        if(num % 10 == D){
            count++;
        }
    }
    return count;
}