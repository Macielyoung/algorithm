#include<stdio.h>
#include<stdlib.h>
#define max 30

typedef struct node
{
	int vertex;
	struct node *connect;
}*Node;

typedef struct
{
	int v;
	int w;
}edge;

Node graph[max];
int n=0;
int DFN[max],L[max];
edge edges[50];
int top=0;
int num=1;

int min(int a,int b)
{
	return a<b?a:b;
}

void print()
{
	int i;
	Node e;
	for(i=0;i<=n;i++)
	{
		printf("[%d]  ",i);
		for(e=graph[i];e;e=e->connect)
		{
			printf("%d->",e->vertex);
		}
		printf("\n");
	}
}


void printDFN()
{
	int i=0;
	while(i<=n)
	{
		printf("[%d]: DFN:%d L:%d\n",i,DFN[i],L[i]);
		i++;
	}
}


void addEdge(int v,int w)
{
	Node e=(Node)malloc(sizeof(struct node));
	e->vertex = w;
	e->connect = graph[v];
	graph[v] = e;
}

void add(int v,int w)
{
	addEdge(v,w);
	addEdge(w,v);
}

void DFNL(int u,int v)
{
	Node ptr;
	int w;
	DFN[u]=L[u]=num;
	num++;
	for(ptr=graph[u];ptr;ptr=ptr->connect)
	{
		w=ptr->vertex;
		if(DFN[w]<0)
		{
			DFNL(w,u);
			L[u]=min(L[u],L[w]);
		}
		else if(w!=v)
		{
			L[u]=min(L[u],DFN[w]);
		}
	}
}

void ART(int u,int v)
{
	Node ptr;
	int w;
	edge e;
	DFN[u]=L[u]=num;
	num++;
	for(ptr=graph[u];ptr;ptr=ptr->connect)
	{
		w=ptr->vertex;
		if(v!=w && DFN[w]<DFN[u])
		{
			edges[top].v=u;
			edges[top].w=w;
			++top;
			if(DFN[w]<0)
			{
				ART(w,u);
				L[u]=min(L[u],L[w]);
				if(L[w]>=DFN[u])
				{
					printf("new biconnected component:");
					do{
						e=edges[--top];
						printf("<%d,%d>",e.v,e.w);
					}while(!(e.v==u && e.w == w));
					printf("\n");
				}
			}
			else if(w!=v)
			{
				L[u]=min(L[u],DFN[w]);
			}
		}
	}
}

void init()
{
	int i=0;
	n=9;
	while(i<=n)
	{
		graph[i]=0;
		DFN[i]=L[i]=-1;
		i++;
	}
	add(2,6);
	add(4,7);
	add(3,5);
	add(2,7);
	add(6,9);
	add(7,5);
	add(0,1);
	add(3,2);
	add(1,5);
	add(4,2);
	add(2,3);
}

void main()
{
	init();
	printf("图的邻接表如下所示：\n");
	print();
	printf("\n该图的双连通分图如下：\n");
	ART(0,-1);
	printf("\n从0节点开始深度优先检索，各节点的DFN和L值如下：\n");
	printDFN();
}
