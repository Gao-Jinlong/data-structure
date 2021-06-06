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
	if(N<0)
	{
		printf("Invalid input");
		return;
	}
	else if(N==0)
	{
		printf("%d\n",1);
		return;
	}
	int a[2570]={1},i,j;
	int t=0,len=1,tem;//t为进位，len为位数 
	for(i=2;i<=N;i++) 
	{
		t=0;
		for(j=0;j<len;j++)
		{
			tem=a[j]*i;//乘积的值
	    	a[j]=(tem+t)%10;//每一位分离出来 同时将进位加入
			t=(tem+t)/10;
			if(t!=0&&j==len-1)//判断位数是否增加 长度到顶时如果还有进位则增加len添加一轮循环
			    len++;
            // printf("i = %d\t的%d位\ttem = %d\t\t a[j] = %d\t\t t = %d\t\t位长%d\t\n",i,j+1,tem, a[j],t,len);
		}
	}
	for(i=len-1;i>=0;i--) 
	{
		printf("%d",a[i]);//输出结果 
	}
}