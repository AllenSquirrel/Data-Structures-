#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dynamic_array.h"

int main()
{
	//初始化动态数组
	Dynamic_array* myarr= Init_array();
	//打印容量
	printf("容量：%d", myarr->cap);
	printf("大小: %d",myarr->size);

	//插入一个元素
	for (int i = 0; i < 30; i++)
	{
		pushback_array(myarr, i);
	}
	printf("容量：%d", myarr->cap);
	printf("大小: %d", myarr->size);
	print_array(myarr);
	

	//删除
	removebypos_array(myarr,0);
	removebyval_array(myarr,27);
	print_array(myarr);

	//查找
	printf("查找到元素位置：%d", find_array(myarr, 5));
	freespace_array(myarr);

	return 0;
}