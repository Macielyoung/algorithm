#include<stdio.h>
#include<stdlib.h>
#define n 8                               //物品数量

int W[8] = {1,11,21,23,33,43,45,55};      //物品重量
int P[8] = {11,21,31,33,43,53,55,65};     //物品效益
int fw,fp=-1;                             //fw背包最后容量，fp为背包最大效益
int X[8] = {0};                           //表示物品放入情况

//复制函数
void copy(int X[],int Y[])
{
	for(int i=0;i<n;i++)
	{
		X[i] = Y[i];
	}
}

//限界函数
//p为当前效益总量，w为当前背包重量，k为上次去掉的物品，M为背包容量
double bound(int p,int w,int k,int M)
{
	double b = p;
	double c = w;
	for(int i=k+1;i<=n;i++)
	{
		c += W[i-1];
		if(c < M)
		{
			b += P[i-1];
		}
		else{
			return (b+(1-(c-M)/W[i-1])*P[i-1]);
		}
	}
	return b;
}

//回溯法递归实现
void back(int M,int cw,int cp,int k,int Y[n+1])
{
	if(k >= n)
	{
		if(cp > fp)
		{
			fp = cp;
			fw = cw;
			copy(X,Y);
		}
		return;
	}

	if(cw + W[k-1] <= M)                          //如果小于背包容量，则放入
	{
		Y[k-1] = 1;
		back(M,cw+W[k-1],cp+P[k-1],k+1,Y);
		Y[k-1] = 0;
	}

	if(bound(cp,cw,k,M) > fp)
	{
		back(M,cw,cp,k+1,Y);
	}
}

int main()
{
	int Y[8];
	int M = 110;
	int cw=0;
	int cp=0;
	int k=1;
	back(M,cw,cp,k,Y);
	printf("各物品放入状况：1 = 放入,0 = 未放入\n");
	for(int i=0;i<n;i++)
	{
		printf("%d号物品:%d\n",i+1,X[i]);
	}
	return 0;
}
