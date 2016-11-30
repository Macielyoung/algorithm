#include<stdio.h>
#include<stdlib.h>
#define m 7

int find(int COST[m][m], int NEAR[], int n)
{
	int i,j,temp = 1000;
	for (i = 1; i <= n; i++)
	{
		if (NEAR[i] != 0)
		{
			if (temp > COST[i][NEAR[i]])
			{
				temp = COST[i][NEAR[i]];
				j = i;
			}
		}
	}
	return j;
}

int PRIM(int COST[m][m], int n, int T[][2], int mincost,int NEAR[])
{
	int i, j, k, l;

	mincost = COST[1][2];
	k = 1; l = 2;
	for (i = 1; i <= n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (mincost > COST[i][j])
			{
				mincost = COST[i][j];
				k = i; l = j;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (i!=k&&i!=l)
		{
			if (COST[i][l] < COST[i][k])
			{
				NEAR[i] = l;
			}
			else
			{
				NEAR[i] = k;
			}
		}
	}
	T[1][0] = k;
	T[1][1] = l;
	NEAR[l] = NEAR[k] = 0;
	for (i = 2; i <= n - 1; i++)
	{
		j = find(COST, NEAR, 6);
		T[i][0] = j;
		T[i][1] = NEAR[j];
		mincost = mincost + COST[j][NEAR[j]];
		NEAR[j] = 0;
		for (k = 1; k <= n; k++)
		{
			if (NEAR[k] != 0&&COST[k][NEAR[k]]>COST[k][j])
			{
				NEAR[k] = j;
			}
		}
	}
	return mincost;
}


int main()
{
	int COST[m][m] = { { 0 }, { 0, 0, 10, 999, 30, 45, 999 }, { 0, 10, 0, 50, 999, 40, 25 }, { 0, 999, 50, 0, 999, 35, 15 }, { 0, 30, 999, 999, 0, 999, 20 }, { 0, 45, 40, 35, 999, 0, 55 }, { 0, 999, 25, 15, 20, 55, 0 } };
	int i, j, T[6][2], mincost = 0, NEAR[m] = {0};

	mincost=PRIM(COST,6,T,mincost,NEAR);
	if (mincost >= 999)
	{
		printf("no spanning tree\n");
	}
	else
	{
		printf("Edge:\n");
		for (i = 1; i < 6; i++)
		{
			printf("%d -- %d\n", T[i][0], T[i][1]);
		}
		printf("Mincost:%d\n", mincost);
	}
	return 0;
}
