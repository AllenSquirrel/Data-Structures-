#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include<stdio.h>
#include<stdlib.h>

typedef struct DYNAMIC_ARRAY
{
	int* pAddr;//存放数据地址
	int size;//记录当前有多少个元素
	int cap;//容量 当前能够容量的最大元素

}Dynamic_array;

//操作API函数
//初始化
Dynamic_array* Init_array();
//插入
void pushback_array(Dynamic_array* arr,int value);
//删除某一位置值
void removebypos_array(Dynamic_array* arr, int pos);
//根据值删除
void removebyval_array(Dynamic_array* arr, int value);
//查找
int find_array(Dynamic_array* arr, int value);
//释放动态数组内存
void freespace_array(Dynamic_array* arr);
//打印动态数组元素
void print_array(Dynamic_array* arr);
//清空数组
void clear_array(Dynamic_array* arr);
//获得动态数组容量
int cap_array(Dynamic_array* arr);
//获得动态数组当前元素个数
int size_array(Dynamic_array* arr);
//根据位置获得该位置元素
int at_array(Dynamic_array* arr,int pos);
#endif // !DYNAMIC_ARRAY_H
