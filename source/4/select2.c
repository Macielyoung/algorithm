#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define r 100
#define N 100000

//线性插入排序
void insert_sort(int a[],int first,int last)
{
	int i,j;
	int tmp;
	for(i=first;i<=last;i++)
	{
		tmp = a[i];                //用O(1)的额外空间将代排序的数存储起来
		j = i - 1;
		while((j>=first)&&(a[j]>tmp))  //代排序的数和它前面的每个数做比较
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
}

//交换函数
void swap(int a,int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//分割函数
int partition(int a[],int m,int j)
{
	int p = a[m];
	int i = m;               //记录分割元素位置
	while(i < j)
	{
		while(i<j && p<=a[j])   //从前往后移动，大于等于哨兵元素向前移
		{
			j--;
		}
		if(i<j)
		{
			a[i++] = a[j];      //将小于哨兵元素的元素移到左边
		}
		while(i<j && p>=a[i])   //从前往后移动，小于等于哨兵元素向后移
		{
			i++;
		}
		if(i<j)
		{
			a[j--] = a[i];      //将大于哨兵元素的元素移动到右边
		}
	}
	a[i] = p;
	return i;                   //返回分割元素位置
}

//二次取中规则的选择算法
int select2(int a[],int m,int p,int k)
{
	int n,i,j;
	if(p-m+1<=r){
		insert_sort(a,m,p);
		return m+k-1;
	}
	while(1)
	{
		n = p-m+1;              //元素总数
		for(i=1;i<=n/r;++i)     //计算中间值
		{
			insert_sort(a,m+(i-1)*r,m+i*r-1);    //将中间值收集到数组的前部
			swap(a[m+i-1],a[m+(i-1)*r+r/2-1]);   //交换数据
		}
		if((n/r)%2 == 1)         //转换取上届
		{
			j = select2(a,m,m+n/r-1,(1+(n/r)/2));
		}
		else
        {
			j = select2(a,m,m+n/r-1,(n/r)/2);
		}
		swap(a[m],a[j]);         //产生划分元素
		j = p;        
		j = partition(a,m,j);
		if(k == (j-m+1))
		{
			return j;
		}
		else if(k > (j-m+1))
		{
			k = k - (j-m+1);
			m = j + 1;
		}
		else
		{
			p = j-1;
		}
	}
}

int main()
{
	int a[N];
    	int x=5000,y;
	clock_t start,end;
	double duration;
	srand((int)time(0));           //产生随机数
	int i;
	for(i=0;i<N;i++)
	{
       a[i] = rand();
	}
    for(i=0;i<N;i++)
    {
        if(i%5 == 0)
        {
            printf("\n");
        }
        printf("%12d ",a[i]);
    }
    printf("\n");
    start = clock();
    y=select2(a,0,N-1,x);         //调用select2函数
    printf("查找第%d小元素是：%d\n",x,a[y]);         //输出想要查找的值
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;  //计算消耗时间
    printf("Running time is:%f seconds\n",duration);
    return 0;
}
