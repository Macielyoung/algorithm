#include <stdio.h>
#include <stdlib.h>
#define N 10	        
#define M 80            
#define MM 150			

int max(int i,int j)
{
	return i>j?i:j;
}

void PARTS(int F[],int P[],int W[],int p[],int w[],int next)
{
	int X[N+1];
	int i,j;
	int pnext=P[next-1];
	int wnext=W[next-1];
	for(i=N;i>0;i--)
	{
		for(j=F[i]-1;j>=F[i-1];j--)
		{
			if(pnext==P[j]&&wnext==W[j])
			{
				X[i]=0;
				break;
			}
			if(pnext>P[j]||wnext>W[j])
			{			
				j=F[i-1]-1;
				break;
			}
		}
		if(j<F[i-1])
		{
			X[i]=1;
			pnext-=p[i];
			wnext-=w[i];
		}
	}
	printf("最优决策序列:\n");
	for(int i=1;i<=N;i++)
	{
		printf("X[%d]=%d  ",i,X[i]);
	}
	printf("\n");
}

int find(int W[],int w[],int L,int h,int wi)
{
	int r,k,max;
	k=r=L;
	max=W[r]+wi;
	for(r=L+1;r<=h;r++)
		{
			if(W[r]+wi<=M&&W[r]+wi>max)
				k=r;
		}
	return k;
}

void DKNAP( int p[],int w[])
{
	int L,h,next,k,pp,ww,u;
	int F[N+2];
	int P[MM],W[MM];
	F[0]=1;
	P[0]=W[0]=-1;
	P[1]=W[1]=0;                
	L=h=1;                      
	F[1]=next=2;                
	for(int i=1;i<=N;i++)       
	{
		k=L;
		u=find(W,w,L,h,w[i]);   
		for(int j=L;j<=u;j++)   
		{
			pp=P[j]+p[i];       
			ww=W[j]+w[i];
			while(k<=h&&W[k]<ww)
			{
				P[next]=P[k];
				W[next]=W[k];
				next++;
				k++;
			}
			if(k<=h&&W[k]==ww)
			{
				pp=max(pp,P[k]);
				k++;

			}
			if(pp>P[next-1])
			{
				P[next]=pp;
				W[next]=ww;
				next++;
			}
			while(k<=h&&P[k]<=P[next-1])   
			{
				k++;
			}
		}
		while(k<=h)
		{
			P[next]=P[k];
			W[next]=W[k];
			next++;
			k++;
		}
		L=h+1;
		h=next-1;
		F[i+1]=next;
	}
	
	for(int i=0;i<=N;i++)
	{
		printf("S[%d]={ ",i);
		for(int j=F[i];j<F[i+1];j++)
		{
			printf("<%d,%d> ",P[j],W[j]);
		}
		printf("}\n");
	}
	printf("\n");	
	PARTS(F,P,W,p,w,next);
}

void main()
{
	int p[N+1],w[N+1];
	p[0]=w[0]=-1;
	for(int i=1;i<=N;i++)
	{
		p[i]=rand()%N;
		w[i]=rand()%M;
	}

	printf("各物品效益和重量如下：\n");
	for(int i=1;i<=N;i++)
	{
		printf("p[%d]=%d\t",i,p[i]);
	}
	printf("\n");
	for(int i=1;i<=N;i++)
	{
		printf("w[%d]=%d\t",i,w[i]);
	}
	printf("\n");
	printf("背包总容量：M=%d\n\n",M);
	printf("序偶结果如下：\n");
	DKNAP(p,w);
}
