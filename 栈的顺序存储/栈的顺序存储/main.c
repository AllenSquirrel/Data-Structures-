#include<stdio.h>
#include<string.h>
#include"seqstack.h"

typedef struct person {
	char name[64];
	int age;
}person;
int main()
{
	//����ջ
	seqStack*stack = init_seqstack();

	//��������
	person p1 = { "aaa",10 };
	person p2 = { "bbb",20 };
	person p3 = { "ccc",30 };
	person p4 = { "ddd",40 };
	person p5 = { "eee",50 };

	//��ջ
	push_seqstack(stack, &p1);
	push_seqstack(stack, &p2);
	push_seqstack(stack, &p3);
	push_seqstack(stack, &p4);
	push_seqstack(stack, &p5);

	//���� ��ջ
	while (size_seqstack(stack) > 0)
	{
		person* tmp = (person*)top_seqstack(stack);//����ջ��Ԫ��ǿת���
		printf("name:%s,age:%d\n", tmp->name, tmp->age);

		//������ǰջ��Ԫ��  ���������һջ��Ԫ�����
		pop_seqstack(stack);
	}
	return 0;
}