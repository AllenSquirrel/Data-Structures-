#include<stdio.h>
#include<string.h>
#include"seqstack.h"

typedef struct person {
	char name[64];
	int age;
}person;
int main()
{
	//创建栈
	seqStack*stack = init_seqstack();

	//创建数据
	person p1 = { "aaa",10 };
	person p2 = { "bbb",20 };
	person p3 = { "ccc",30 };
	person p4 = { "ddd",40 };
	person p5 = { "eee",50 };

	//入栈
	push_seqstack(stack, &p1);
	push_seqstack(stack, &p2);
	push_seqstack(stack, &p3);
	push_seqstack(stack, &p4);
	push_seqstack(stack, &p5);

	//访问 出栈
	while (size_seqstack(stack) > 0)
	{
		person* tmp = (person*)top_seqstack(stack);//访问栈顶元素强转输出
		printf("name:%s,age:%d\n", tmp->name, tmp->age);

		//弹出当前栈顶元素  方便访问下一栈顶元素输出
		pop_seqstack(stack);
	}
	return 0;
}