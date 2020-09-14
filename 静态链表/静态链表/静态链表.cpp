#include<iostream>

using namespace std;
typedef int status;
//***************************************
//游标  5  2  3  4  0  6  7  ...  1
//数据     A  C  D  E        ...
//下标  0  1  2  3  4  5  6  ...  999
//***************************************

//0 和 MAXSIZE-1 下标对应数据均为空 且注意开始 游标5 指向第一次数据为空的位置（备用链表开头）   游标1 指向第一次存放数据的位置（相当于头结点作用）

//线性表的静态链表存储结构

#define MAXSIZE 1000
#define OK 0
#define ERROR -1
typedef struct
{
	ElemType data;//数据
	int cur;//游标
}component,staticlinklist[MAXSIZE];

//对静态链表进行初始化相当于初始化数组
status Initlist(staticlinklist space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0; //结尾游标指向为头结点

	return 0;
}

//获取空闲分量的下标

int  malloc_sll(staticlinklist space)
{
	int i = space[0].cur;
	if (space[0].cur)
	{
		space[0].cur = space[i].cur;
		//将开始的游标作为备用链表的开始,为下一次存储

	}
	return i;
}

//返回L中数据元素个数
int listlength(staticlinklist L)
{
	int j = 0;
	int i = L[MAXSIZE-1].cur;// i=1

	while (i)
	{
		i = L[i].cur;//i通过游标形式实现i后移  类似于链表中移动指针  游标指向下一节点的下标
		j++;//统计L的长度
	}
	return j;
}
//在静态链表L中第i个元素前插入新数据元素e


//***************************************
//游标  5  2  3  4  0  6  7  ...  1
//数据     A  C  D  E        ...
//下标  0  1  2  3  4  5  6  ...  999
//***************************************

//***************************************
//游标  6  5  3  4  0  2  7  ...  1
//数据     A  C  D  E  B      ...
//下标  0  1  2  3  4  5  6  ...  999
//***************************************

//最终实现 1A5--5B2--2C3--3D4--4E0--0..6--6.. 在不改变其位置基础上  实现逻辑连接
status listinsert(staticlinklist L, int i, ElemType e)
{
	int l, j, k;
	k = MAXSIZE - 1;//数组的最后一个元素
	if (i<1 || i>listlength(L) + 1)
	{
		return ERROR;
	}
	j = malloc_sll(L);//j指向备用数组第一个元素位置下标
	if (j)//获取到后
	{
		L[j].data = e;//将新元素数据暂存在备用数组第一个元素位置上
		//接下来，通过游标位置调动  实现按需插入新元素
		for (l = 1; l <= i - 1; l++)
		{
			k = L[k].cur;//将数组最后一个元素第999 的游标 1给k； k=1；
			             //i=2  只经过一次循环  最终k的取值为数组第一个元素的游标值 k=1

		}
		L[j].cur = L[k].cur; //L[5].cur=L[1].cur=2
		L[k].cur = j;//L[1].cur=5

		return OK;
	}
	return ERROR;
}

//删除L中第i个数据元素  删除i=3 C元素  i的顺序是根据链表结构的顺序 ABCDE

//***************************************
//游标  6  5  3  4  0  2  7  ...  1
//数据     A  C  D  E  B      ...
//下标  0  1  2  3  4  5  6  ...  999
//***************************************

//***************************************
//游标  2  5  6  4  0  3  7  ...  1
//数据     A     D  E  B      ...
//下标  0  1  2  3  4  5  6  ...  999
//***************************************

status listdelete(staticlinklist L, int i)
{
	int j, k;
	if (i<1 || i>listlength(L))
	{
		return ERROR;
	}
	k = MAXSIZE - 1;//K=999
	for (j = 1; j <= i - 1; j++)
	{
		k = L[k].cur; //i=3 执行两次循环 第一次 k=1; 第二次 k=5；
	}
	j = L[k].cur; //j=2;
	L[k].cur = L[j].cur;//L[2].cur=3  则L[5].cur=3

	//链接过程 跳过数据C元素 并重新整理空闲节点作为备用链表
	Free_sll(L, j);
	return OK;
}
//重新整理回收空闲节点作为备用链表
void Free_sll(staticlinklist space, int k)
{
	space[k].cur = space[0].cur; //space[2].cur = space[0].cur=6;
	space[0].cur = k;//space[0].cur =2;  //将下标为2的元素回收到备用数组链表
}