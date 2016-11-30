#include<stdio.h>
#include<stdlib.h>

int max(int a[],int n)
{
	if(n == 1)
	{
		return a[0];
	}
	int x = a[0];
	int *s = a;
	s++;
	int y = max(s,n-1);
	return (x>y)?x:y;
}

int main()
{
	int p[5];
	printf("请输入5个数据:");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&p[i]);
	}
	int m;
	m = max(p,5);
	printf("最大数：%d\n",m);
	return 0;
}

