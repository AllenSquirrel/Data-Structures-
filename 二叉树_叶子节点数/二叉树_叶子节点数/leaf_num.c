#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���Ľṹ�ص㣺
//��1�������Խṹ����һ��ֱ��ǰ�����������ж��ֱ�Ӻ�̣�1��n��
//��2�����Ķ�����еݹ��ԣ���������
//(3)������Ϊ��

//���� ���ֵܱ�ʾ��  ��һ����ͨ��ת��Ϊ������
//����1���ڶ������ĵ�i��������2^(i-1)���ڵ�
//����2�����Ϊk�Ķ�����������2^k-1���ڵ�
//����3�������κ�һ�ö�����������Ϊ2�Ľڵ�����n2������Ҷ������n0���ض�Ϊn2+1������n0=n2+1��
//����4������n���ڵ����ȫ����������ȱ�Ϊlog2��n��+1
//����5������ȫ���������������£��������ң�����Ϊi�Ľڵ㣬�����ӱ��Ϊ2i���Һ��ӱ��Ϊ2i+1����˫�׵ı�ű�Ϊi/2��i=1Ϊ�����⣩

//DLR--�������  ������
//LDR--�������  �����
//LRD--�������  ���Ҹ�

typedef struct BinaryNode {
	char c;
	struct BinaryNode* lchild;
	struct BinaryNode* rchild;

}Binarynode;


//�ݹ����Ҷ�ӽڵ���  �ص㣺Ҷ�ӽ�����ӽڵ�
void caculateleafnum(Binarynode* root,int* leafnum)
{
	if (root = NULL)
	{
		return;
	}
	if (root->lchild == NULL && root->rchild == NULL)
	{
		(*leafnum)++;
	}
	caculateleafnum(root->lchild,leafnum);
	caculateleafnum(root->rchild,leafnum);

}

//�ݹ����������߶�
int caculatetreedepth(Binarynode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int depth = 0;
	int left_depth = caculatetreedepth(root->lchild);
	int right_depth = caculatetreedepth(root->rchild);
	depth = left_depth > right_depth ? left_depth + 1 : right_depth + 1;

	return depth;
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

	int leafnum = 0;
	caculateleafnum(&node1,&leafnum);
	printf("Ҷ�ӽڵ�����%d\n", leafnum);
	system("pause");
	return 0;
}