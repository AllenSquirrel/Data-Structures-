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


//�ݹ����
void recursion(Binarynode* root)
{
	if (root = NULL)
	{
		return;
	}
	//�ȷ��ʸ���� �������� ��������
	printf("%c",root->c);
	recursion(root->lchild);
	recursion(root->rchild);
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

	//�������
	recursion(&node1);
	system("pause");
	return 0;
}