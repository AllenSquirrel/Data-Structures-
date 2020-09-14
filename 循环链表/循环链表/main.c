#include"circle_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PERSON {
	circle_listnode node;
	char name[64];
	int age;
	int score;
}person;

//打印回调函数
void myprint(circle_listnode*data)
{
	person* p = (person*)data;//数据强转
	printf("name:%s,age:%d,sore:%d\n",p->name,p->age,p->score);
}

int mycompare(circle_listnode*data1, circle_listnode*data2)
{
	person*p1 = (person*)data1;
	person*p2 = (person*)data2;

	if (strcmp(p1->age, p2->name) == 0 && p1->age==p2->age && p1->score==p2->score)
	{
		return circle_TRUE;
	}
	return circle_FALSE;
}
int main()
{
	//创建循环链表
	circle_linklist*list = init_circlelinklist();
	//创建数据
	person p1, p2, p3, p4, p5;
	strcpy_s(p1.name,4, "aaa");
	strcpy_s(p2.name,4, "bbb");
	strcpy_s(p3.name,4, "ccc");
	strcpy_s(p4.name,4, "ddd");
	strcpy_s(p5.name,4, "eee");
	p1.age = 1;
	p2.age = 2;
	p3.age = 3;
	p4.age = 4;
	p5.age = 5;
	p1.score = 10;
	p2.score = 20;
	p3.score = 30;
	p4.score = 40;
	p5.score = 50;

	insert_circlelinklist(list, 0, (circle_listnode*)&p1);
	insert_circlelinklist(list, 0, (circle_listnode*)&p2);
	insert_circlelinklist(list, 0, (circle_listnode*)&p3);
	insert_circlelinklist(list, 0, (circle_listnode*)&p4);
	insert_circlelinklist(list, 0, (circle_listnode*)&p5);

	print_circlelinklist(list, myprint);
	printf("*******************************");
	removebypos_circlelinklist(list, 2);
	print_circlelinklist(list, myprint);
	printf("*******************************");
	person del;
	strcpy_s(del.name,4, "ccc");
	del.age = 3;
	del.score = 30;
	removebyvalue_circlelinklist(list, (circle_listnode*)&del, mycompare);
	print_circlelinklist(list, myprint);
	//释放内存
	free_circlelinklist(list);
	return 0;
}