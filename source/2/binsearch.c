#include<stdio.h>
#include<stdlib.h>

//二分搜索的递归实现
int binary_search(int a[],int low,int high,int k)
{
	if(low <= high)               //判断位置
	{
		int medium = low + (high - low) / 2;      //求出中间位置
		if(k == a[medium])        //若查找的数和中间数相等，则返回中间位置
			return medium;
		else if(k > a[medium])    //若大于中间位置的数，则到后半数组查找    
			return binary_search(a,medium+1,high,k);
		else					  //若小于，则到前半数组查找
			return binary_search(a,low,medium-1,k);
	}
	else{
		return -1;                //若无该数，则返回-1
	}
}

int main()
{
	int array[10];
	int m,pos;
	printf("请输入10个数：");
	for(int i=0;i<10;i++)
	{
		scanf("%d",&array[i]);           //输入10个数
	}
	printf("请输入想要查找的数：");
	scanf("%d",&m);
	pos = binary_search(array,0,9,m);    //求查找数的位置
	if(pos < 0)
		printf("要查找的数不存在\n");
	else
		printf("第%d位数是要查找的数\n",pos+1);
	return 0;
}
