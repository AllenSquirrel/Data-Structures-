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

//创建栈中节点  包装节点带标志位
Binarystacknode* createtreestackNode(Binarynode* root,int flag)
{
	Binarystacknode* newnode = (Binarystacknode*)malloc(sizeof(Binarystacknode));
	newnode->root = root;
	newnode->flag = flag;
	return newnode;
}
//非递归遍历   
void nonRecursion(Binarynode* root)
{
	//创建栈
	link_stack* stack = init_linkstack();
	//把根结点扔到栈里
	push_linkstack(stack,(link_stackNode*)createtreestackNode(root,MY_FALSE));
	
	while (size_linkstack(stack)>0)
	{
		//先弹出栈顶元素
		Binarystacknode* node = (Binarystacknode*)top_linkstack(stack);
		pop_linkstack(stack);

		//判断弹出节点是否为空
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
			//入栈顺序决定遍历顺序  
			//此时入栈顺序 根 右 左     为后续遍历 左右根  （刚好反过来）

			//当前节点给 true   入栈
			node->flag = MY_TRUE;
			push_linkstack(stack, (link_stackNode*)node);

			push_linkstack(stack, (link_stackNode*)createtreestackNode(node->root->rchild, MY_FALSE));
			push_linkstack(stack, (link_stackNode*)createtreestackNode(node->root->lchild, MY_FALSE));

			
		}
	}
}
int main()
{

	//创建节点
	Binarynode node1 = { 'A',NULL,NULL };
	Binarynode node2 = { 'B',NULL,NULL };
	Binarynode node3 = { 'C',NULL,NULL };
	Binarynode node4 = { 'D',NULL,NULL };
	Binarynode node5 = { 'E',NULL,NULL };
	Binarynode node6 = { 'F',NULL,NULL };
	Binarynode node7 = { 'G',NULL,NULL };
	Binarynode node8 = { 'H',NULL,NULL };

	//建立节点关系
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