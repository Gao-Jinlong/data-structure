#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
void Print_Factorial ( const int N ){
    if(N<0){
        printf("Invalid input");
    }
    long long factorial = 1.0;
    for(int i = 2; i <= N; i++){
        factorial *= i;
    }
    printf("%lld",factorial);
}