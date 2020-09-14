#include<stdio.h>
#include<stdlib.h>

//线性表是零个或多个数据元素的有限序列
//特性：（1）元素间有顺序 (2)元素个数有限（3）元素类型必须相同

//*****************************************************************************
// (1)顺序存储结构 （线性表）执行查找操作  可根据索引直接查找  时间复杂度O（1）
//（2）顺序存储结构 （线性表）执行插入/删除操作  需要平均移动表长一半的元素   时间为O（n）

//空间存储：需要预先分配存储空间  分大->空间浪费, 分小->溢出

//若线性表需要频繁查找，很少进行插入删除操作，宜采用顺序存储结构

//*****************************************************************************

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int status;

typedef struct Aarea
{
	float data;//数据域
	
}ElemType;

typedef struct Node {
	ElemType *data;//数据域
	int length; //表长度
}list;
//typedef struct Node* list;//创建线性表


status GetElem(list L, int i, ElemType *e)//获取线性表值
{
	if (L.length == 0 || i<1 || i>L.length)
	{
		return ERROR;
	}
	*e = L.data(i - 1);//线性表从1到n   实际存储从0到n
	return OK;
}
//*****************************************************************************
status LocateElem(list LA, ElemType *e)//比较线性表值
{
	int LA_len, i;
	ElemType e;
	LA_len = ListLength(*LA);//获取线性表长度
	
	for (i = 1; i < LA_len; i++)
	{
		if (LA.data(i - 1) == *e)
			return OK;
	}
	return ERROR;
	
}
//*****************************************************************************
status ListInsert(list L, , int i, ElemType *e)
{
	int k;
	if (L.length == MAXSIZE)
	{
		return ERROR;
	}
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	if (i <= L.length)
	{
		for (k = L.length - 1; k > i - 1; k--)
		{
			L.data[k + 1] = L.data[k];//插入位置后数据元素向后移一位
		}
	}
	L.data[i - 1] = e;//将元素插入第i位置  线性表i位置对应存储data的i-1位置
	L.length++;

	return OK;
}
//*****************************************************************************
status ListDelete(list L, , int i, ElemType *e)
{
	int k;
	if (L.length == 0) //此处0 即为最小长度  小于0 将无法删除
	{
		return ERROR;
	}
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	*e = L.data[i - 1];
	free(*e);
	if (i <= L.length)
	{
		for (k = i; k<L.length; k++)
		{
			L.data[k -1 1] = L.data[k];//删除位置后数据元素向前移一位
		}
	}
	
	L.length--;

	return OK;
}
//*****************************************************************************
void UnionL(list LA,list LB)//两个线性表集合 求并集
{
	int LA_len,LB_len,i;
	ElemType e;
	LA_len = ListLength(*LA);//获取线性表长度
	LB_len = ListLength(LB);

	for (i = 1; i < LB_len; i++)
	{
		GetElem(LB,i.&e);//获取线性表LB中第i个元素值 并赋值给e中保存
		if (!LocateElem(*LA, e))//在LA中查找是否存在于e中相同元素
		{
			ListInsert(LA,++LA_len,e);//将不重复的元素添加进LA
		}
	}
}