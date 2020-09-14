#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//树的结构特点：
//（1）非线性结构，有一个直接前驱，但可能有多个直接后继（1：n）
//（2）树的定义具有递归性，树中有树
//(3)树可以为空

//左孩子 右兄弟表示法  将一棵普通树转换为二叉树
//性质1：在二叉树的第i层至多有2^(i-1)个节点
//性质2：深度为k的二叉树至多有2^k-1个节点
//性质3：对于任何一棵二叉树，若度为2的节点数有n2个，则叶子数（n0）必定为n2+1；（即n0=n2+1）
//性质4：具有n个节点的完全二叉树的深度必为log2（n）+1
//性质5：对完全二叉树，从上至下，从左至右，则编号为i的节点，其左孩子编号为2i，右孩子编号为2i+1；其双亲的编号必为i/2（i=1为根除外）

//DLR--先序遍历  根左右
//LDR--中序遍历  左根右
//LRD--后序遍历  左右根

typedef struct BinaryNode {
	char c;
	struct BinaryNode* lchild;
	struct BinaryNode* rchild;

}Binarynode;


//递归遍历
void recursion(Binarynode* root)
{
	if (root = NULL)
	{
		return;
	}
	//先访问根结点 在左子树 后右子树
	printf("%c",root->c);
	recursion(root->lchild);
	recursion(root->rchild);
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

	//先序遍历
	recursion(&node1);
	system("pause");
	return 0;
}