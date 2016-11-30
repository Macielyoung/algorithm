#include<stdio.h>
#include<stdlib.h>
#define n 4

//求使{C(i，k-1)+C(k，j)}取最小值的k
int find(int c[][n+1],int i,int j)
{
	int k,x,min;
	x=k=i+1;
	min = c[i][k-1]+c[k][j];
	for(k=i+2;k<=j;k++)
	{
		if(c[i][k-1]+c[k][j]<min)
		{
			min = c[i][k-1] + c[k][j];
			x = k;
		}
	}
	return x;
}

void OBST(int P[],int Q[])
{
	int R[n+1][n+1];
	int C[n+1][n+1];
	int W[n+1][n+1];
	for(int i=0;i<n;i++)
	{
		//初始化
		W[i][i] = Q[i];
		R[i][i] = 0;
		C[i][i] = 0;

		//含一个节点的最优树
		W[i][i+1] = Q[i]+Q[i+1]+P[i+1];
		R[i][i+1] = i+1;
		C[i][i+1] = Q[i]+Q[i+1]+P[i+1];
	}

	W[n][n] = Q[n];
	R[n][n] = 0;
	C[n][n] = 0;
	
	int j,k;
	for(int m=2;m<=n;m++)
	{
		for(int i=0;i<=n-m;i++)
		{
			j=i+m;
			W[i][j]=W[i][j-1]+P[j]+Q[j];
			//求使{C(i，k-1)+C(k，j)}取最小值的k
			k=find(C,i,j);
			C[i][j]=W[i][j]+C[i][k-1]+C[k][j];
			R[i][j]=k;
			printf("W[%d][%d]=%d    C[%d][%d]=%d    R[%d][%d]=%d\n",i,j,W[i][j],i,j,C[i][j],i,j,R[i][j]);
		}
	}
}

int main()
{
	/*
	int p[] = {0,3,3,1,1};
	int q[] = {2,3,1,1,1};
	
	int p[] = {0,3,2,1,2};
	int q[] = {2,2,1,1,2};
	*/
	int p[] = {0,1,2,4,1};
	int q[] = {3,2,4,1,2};
	OBST(p,q);
	return 0;
}
