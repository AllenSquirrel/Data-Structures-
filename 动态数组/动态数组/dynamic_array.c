#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dynamic_array.h>

//动态数组初始化
Dynamic_array* Init_array()
{
	Dynamic_array* myarray = (Dynamic_array*)malloc(sizeof(Dynamic_array));//开辟地址空间
	myarray->size = 0;//当前元素数量为0
	myarray->cap = 20;//默认设置数组容量为20
	myarray->pAddr = (int*)malloc(sizeof(int)*myarray->cap);//开辟首地址空间

	return NULL;
}
//插入
void pushback_array(Dynamic_array* arr, int value)
{
	if (arr == NULL)
	{
		return;
	}
	if (arr->size == arr->cap)//插入新元素  空间不足
	{
		//第一步 开辟一块更大容量的空间  新空间是旧空间的2倍
		int* newspace = (int*)malloc(sizeof(int)*arr->cap * 2);
		//第二步 拷贝数据到新空间
		memcpy(newspace,arr->pAddr,arr->cap*sizeof(int));
		//第三步 释放旧空间内存
		free(arr->pAddr);

		//更新容量 地址空间
		arr->cap = arr->cap * 2;
		arr->pAddr = newspace;
	}
	//开始插入--尾插
	arr->pAddr[arr->size] = value;//数组从0开始
	arr->size++;
}
//删除某一位置值
void removebypos_array(Dynamic_array* arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}
	if (pos<0 || pos>arr->size)
	{
		return;
	}
	for (int i = pos; i < arr->size - 1; i++)//删除pos位置  后面元素前移
	{
		arr->pAddr[i] = arr->pAddr[i + 1]; //此时最后一个元素 前移过程中需要注意到arr->size在数组中为空
	}
	arr->size--;
}

//根据值删除
void removebyval_array(Dynamic_array* arr, int value)
{
	int pos = -1;
	if (arr == NULL)
	{
		return ;
	}
	//查找删除值的位置
	pos = find_array(arr, value);
	/*for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAddr[i] == value)
		{
			pos = i;
			break;
		}
	}*/
	//调用位置删除函数
	removebypos_array(arr, pos);
}
//查找
int find_array(Dynamic_array* arr, int value)
{
	int pos = -1;
	if (arr == NULL)
	{
		return -1;
	}
	for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAddr[i] == value)
		{
			pos = i;
			break;
		}
	}
	return pos;
}
//释放
void freespace_array(Dynamic_array* arr)
{
	if (arr == NULL)
	{
		return;
	}
	if (arr->pAddr != NULL)
	{
		free(arr->pAddr);
	}
	free(arr);
}
//打印动态数组元素
void print_array(Dynamic_array* arr)
{
	if (arr == NULL)
	{
		return;
	}
	for (int i = 0; i < arr->size; i++)
	{
		printf("%d ",arr->pAddr[i]);
	}
	printf("\n");
}
//清空数组
void clear_array(Dynamic_array* arr)
{
	if (arr == NULL)
	{
		return;
	}
	arr->size = 0;//直接设置size=0，即便有元素 也可以被其他操作复写覆盖
}
//获得动态数组容量
int cap_array(Dynamic_array* arr)
{
	if (arr == NULL)
	{
		return -1;
	}
	return arr->cap;
}
//获得动态数组当前元素个数
int size_array(Dynamic_array* arr)
{
	if (arr == NULL)
	{
		return -1;
	}
	return arr->size;
}
//根据位置获得该位置元素
int at_array(Dynamic_array* arr, int pos)
{
	if (arr == NULL)
	{
		return -1;
	}
	return arr->pAddr[pos];
}