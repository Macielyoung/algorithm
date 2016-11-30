#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct
{
    int data[max];           //定义数组来存储数据
    int last;                //定义数组最后一个元素位置
}List;

//输出函数，用来输出表中的数据
int output(List *L)
{
    int i;
    for(i=0;i<=L->last;i++)
    {
	printf("%d ",L->data[i]);
    }
    printf("\n");
    return 1;
}

//输入函数，向表输入原始数据
int input(List *L)
{
    int i;
    printf("请输入原始数据个数：");
    scanf("%d",&(L->last));
    L->last--;
    printf("请输入原始数据：");
    for(i=0;i<=L->last;i++)
    {
		scanf("%d",&(L->data[i]));     //输入原始数据
    }
    printf("原始数据为：");
    output(L);                         //输出原始数据
    return 1;
}

//线性插入排序
void insert_sort(List *L,int first,int last)
{
	int i,j;
	int tmp;
	for(i=first+1;i<=last;i++)
	{
		tmp = L->data[i];         //用O(1)的额外空间将代排序的数存储起来
		j = i - 1;
		while((j>=first)&&(L->data[j]>tmp))   //待排序的数和它前面的每个数作比较
		{
			L->data[j+1] = L->data[j];
			j--;
		}
		L->data[j+1] = tmp;
	}
}

int main()
{
   List s,*p = &s;
   int data;
   input(p);
   insert_sort(p,0,p->last);
   printf("排序结果为：");
   output(p);
   return 0;
}
