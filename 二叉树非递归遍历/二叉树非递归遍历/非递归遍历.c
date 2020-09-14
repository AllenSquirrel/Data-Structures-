#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"link_stack.h"

#define MY_FALSE 0
#define MY_TRUE 1

typedef struct BinaryNode {
	char c;
	struct BinaryNode* lchild;
	struct BinaryNode* rchild;

}Binarynode;


typedef struct Binary_stack_node {
	link_stackNode node;
	Binarynode* root;
	int flag;

}Binarystacknode;

//����ջ�нڵ�  ��װ�ڵ����־λ
Binarystacknode* createtreestackNode(Binarynode* root,int flag)
{
	Binarystacknode* newnode = (Binarystacknode*)malloc(sizeof(Binarystacknode));
	newnode->root = root;
	newnode->flag = flag;
	return newnode;
}
//�ǵݹ����   
void nonRecursion(Binarynode* root)
{
	//����ջ
	link_stack* stack = init_linkstack();
	//�Ѹ�����ӵ�ջ��
	push_linkstack(stack,(link_stackNode*)createtreestackNode(root,MY_FALSE));
	
	while (size_linkstack(stack)>0)
	{
		//�ȵ���ջ��Ԫ��
		Binarystacknode* node = (Binarystacknode*)top_linkstack(stack);
		pop_linkstack(stack);

		//�жϵ����ڵ��Ƿ�Ϊ��
		if (node->root == NULL)
		{
			continue;
		}
		if (node->flag == MY_TRUE)
		{
			printf("%c",node->root->c);
		}
		else
		{
			//��ջ˳���������˳��  
			//��ʱ��ջ˳�� �� �� ��     Ϊ�������� ���Ҹ�  ���պ÷�������

			//��ǰ�ڵ�� true   ��ջ
			node->flag = MY_TRUE;
			push_linkstack(stack, (link_stackNode*)node);

			push_linkstack(stack, (link_stackNode*)createtreestackNode(node->root->rchild, MY_FALSE));
			push_linkstack(stack, (link_stackNode*)createtreestackNode(node->root->lchild, MY_FALSE));

			
		}
	}
}
int main()
{

	//�����ڵ�
	Binarynode node1 = { 'A',NULL,NULL };
	Binarynode node2 = { 'B',NULL,NULL };
	Binarynode node3 = { 'C',NULL,NULL };
	Binarynode node4 = { 'D',NULL,NULL };
	Binarynode node5 = { 'E',NULL,NULL };
	Binarynode node6 = { 'F',NULL,NULL };
	Binarynode node7 = { 'G',NULL,NULL };
	Binarynode node8 = { 'H',NULL,NULL };

	//�����ڵ��ϵ
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	nonRecursion(&node1);

	system("pause");
	return 0;
}