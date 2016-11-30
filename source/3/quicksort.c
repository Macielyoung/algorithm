#include<stdio.h>
#include<stdlib.h>

//划分数组
int partition(int array[],int m,int j)
{
	int p = array[m];       //哨兵元素为数组起始元素
	int i = m;				//记录分割元素位置
	while(i < j){
		while(i < j && p <= array[j])  //从后往前移动，大于等于哨兵元素则向前移
		{
			j--;
		}
		if(i < j)
		{
			array[i++] = array[j];   //将小于哨兵元素的元素移到左边
		}
		while(i < j && p >= array[i])   //从前往后移动，小于等于哨兵元素则向后移
		{
			i++;
		}
		if(i < j)
		{
			array[j--] = array[i];   //将大于哨兵元素的元素移动到右边
		}
	}
	array[i] = p;                    //将分割元素移动到其位置
	return i;                        //返回分割元素位置
}

//划分数组后快速排序
void quicksort(int a[],int m,int n)
{
	if(m<n)
	{
		int mid = partition(a,m,n);     //查找分割元素的位置
		quicksort(a,m,mid-1);           //分割元素左边的数组再次快排
		quicksort(a,mid+1,n);			//分割元素右边的数组再次快排
	}
}
		
int main()
{
	int array[10];
	int k;
	printf("请输入10个数：");
	for(k=0;k<10;k++)
	{
		scanf("%d",&array[k]);		  //输入数组元素
	}
	quicksort(array,0,9);            //调用快排函数
	printf("输出排序后的数组：");
	for(k=0;k<10;k++)
 	{
		printf("%d ",array[k]);		  //输出排序后的数组
	}
	printf("\n");
	return 0;
}
