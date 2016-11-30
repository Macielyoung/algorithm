#include<stdio.h>
#include<stdlib.h>
#define n 12
#define k 5
#define max 999

void input(int cost[][n],int fcost[n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cost[i][j] = max;
		}
	}
	
	//输入多段图的边
	cost[0][1] = 9;
	cost[0][2] = 7;
	cost[0][3] = 3;
	cost[0][4] = 2;
	cost[1][5] = 4;
	cost[1][6] = 2;
	cost[1][7] = 1;
	cost[2][5] = 2;
	cost[2][6] = 7;
	cost[3][7] = 11;
	cost[4][6] = 11;
	cost[4][7] = 8;
	cost[5][8] = 6;
	cost[5][9] = 5;
	cost[6][8] = 4;
	cost[6][9] = 3;
	cost[7][9] = 5;
	cost[7][10] = 6;
	cost[8][11] = 4;
	cost[9][11] = 2;
	cost[10][11] = 5;

	for(int i=0;i<n;i++)
	{
		fcost[i] = 0;
	}
}

int find(int l,int cost[][n],int fcost[n])
{
	int min,m;
	min = max;
	for(int i=l;i<n;i++)
	{
		if(fcost[i]+cost[l][i]<min)
		{
			min = cost[l][i]+fcost[i];
			m = i;
		}
	}
	return m;
}

void FGRAPH(int cost[][n],int fcost[n],int D[n],int p[k+1])
{
	int r,j;
	fcost[n] = 0;
	printf(" j\t r\tfcost[j]\n");
	for(j=n-2;j>=0;j--)
	{
		r = find(j,cost,fcost);
		//printf("%d",r);
		fcost[j] = cost[j][r] + fcost[r];
		printf("%d\t%d\t%d\n",j,r,fcost[j]);
		D[j] = r;
	}
	p[1] = 0;
	p[k] = n-1;
	for(j=2;j<=k-1;j++)
	{
		p[j] = D[p[j-1]];
	}
}

void print(int cost[][n],int p[k+1])
{
	int sum = 0;
	printf("请输出cost矩阵：\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(cost[i][j]==max)
			{
				printf("  --");
			}
			else{
				printf("%4d",cost[i][j]);
			}
		}
		printf("\n");
	}
	printf("请输出最小成本路径：%d",p[1]);
	for(int i=2;i<=k;i++)
	{
		printf(" --> %d",p[i]);
		sum += cost[p[i-1]][p[i]];
	}
	printf("\n最小成本：%d\n",sum);
}

int main()
{
	int cost[n][n],fcost[n],D[n],p[k+1];
	input(cost,fcost);
	FGRAPH(cost,fcost,D,p);
	print(cost,p);
	return 0;
}
