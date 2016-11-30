#include<stdio.h>
#include<stdlib.h>

//交换函数
void swap(int a,int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//插入排序函数
void sort(int p[],int d[],int m)
{
	int i,j;
	int tmp1,tmp2;
	for(i=1;i<=m;i++)
	{
		tmp1 = p[i];
		tmp2 = d[i];
		j = i - 1;
		while((j>=1)&&(p[j]<tmp1))
		{
			p[j+1] = p[j];
			d[j+1] = d[j];
			j--;
		}
		p[j+1] = tmp1;
		d[j+1] = tmp2;
	}
}

//带有限期和效益的单位时间作业排序贪心算法
int js(int D[],int J[],int n,int k)
{
	int i,j,r;
	D[0] = J[0] = 0;          //初始化
	k = 1;                    //计入作业1
	J[1] = 1;
	for(i=2;i<=n;i++)         //按效益的非增次序考虑作业
	{
		r = k;
		while(D[J[r]] > D[i] && D[J[r]] != r)
		{	
			r--;
		}
		if(D[J[r]] <= D[i] && D[i] > r)
		{
			for(j=k;j>r;j--)
			{
				J[j+1] = J[j];
			}
			J[r+1] = i;
			k++;
		}
	}
	return k;
}

int main()
{
	int p[100]={0},d[100]={0},j[100]={0};
	int n,i,x=1,sum=0;
	printf("请输入作业数：");
	scanf("%d",&n);
	printf("请输入作业期限：");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}
	printf("请输入作业效益：");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	sort(p,d,n);
	x = js(d,j,n,x);
	printf("结果为：\n");
	for(i=1;i<=x;i++)
	{
		printf("效益%d--截止日期%d\n",p[j[i]],d[j[i]]);
		sum = sum + p[j[i]];
	}
	printf("总效益：%d\n",sum);
	return 0;
}	
