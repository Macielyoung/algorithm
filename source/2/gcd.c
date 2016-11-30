#include<stdio.h>
#include<stdlib.h>

//欧几里得算法求两个数的最大公因子
int gcd(int a,int b)
{
	if(b == 0)                  //若一个数为0，则最大公因子是非0的数
		return a;
	else
		return gcd(b,a % b);    //若都不为0，则和两个数的余数继续比较
}

int main()
{
	int m,n,p;
	printf("请输入两个数：\n");
	printf("m = ");
	scanf("%d",&m);
	printf("n = ");
	scanf("%d",&n);
	p = gcd(m,n);
	printf("最大公因子是：%d\n",p);
	return 0;
}
