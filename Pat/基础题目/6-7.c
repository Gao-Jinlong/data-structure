#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */
int IsTheNumber ( const int N ){
    int m = sqrt(N);
    if(m * m != N){
        return 0;
    }
    else{
        int count = 0;
        int num = N;
        int pos_arr[32];
        int pos = 0;

        for(pos = num % 10; num > 0;){
            if(count > 0){
                for(int i = 0; i < count; i++){
                    if (pos == pos_arr[i])
                    {
                        return 1;
                    }
                }
            }
            pos_arr[count] = pos;
            num /= 10;
            pos = num % 10;
            count++;
        }
        return 0;
    }
}