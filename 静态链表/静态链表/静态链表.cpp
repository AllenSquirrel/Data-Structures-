#include<iostream>

using namespace std;
typedef int status;
//***************************************
//�α�  5  2  3  4  0  6  7  ...  1
//����     A  C  D  E        ...
//�±�  0  1  2  3  4  5  6  ...  999
//***************************************

//0 �� MAXSIZE-1 �±��Ӧ���ݾ�Ϊ�� ��ע�⿪ʼ �α�5 ָ���һ������Ϊ�յ�λ�ã���������ͷ��   �α�1 ָ���һ�δ�����ݵ�λ�ã��൱��ͷ������ã�

//���Ա�ľ�̬����洢�ṹ

#define MAXSIZE 1000
#define OK 0
#define ERROR -1
typedef struct
{
	ElemType data;//����
	int cur;//�α�
}component,staticlinklist[MAXSIZE];

//�Ծ�̬������г�ʼ���൱�ڳ�ʼ������
status Initlist(staticlinklist space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0; //��β�α�ָ��Ϊͷ���

	return 0;
}

//��ȡ���з������±�

int  malloc_sll(staticlinklist space)
{
	int i = space[0].cur;
	if (space[0].cur)
	{
		space[0].cur = space[i].cur;
		//����ʼ���α���Ϊ��������Ŀ�ʼ,Ϊ��һ�δ洢

	}
	return i;
}

//����L������Ԫ�ظ���
int listlength(staticlinklist L)
{
	int j = 0;
	int i = L[MAXSIZE-1].cur;// i=1

	while (i)
	{
		i = L[i].cur;//iͨ���α���ʽʵ��i����  �������������ƶ�ָ��  �α�ָ����һ�ڵ���±�
		j++;//ͳ��L�ĳ���
	}
	return j;
}
//�ھ�̬����L�е�i��Ԫ��ǰ����������Ԫ��e


//***************************************
//�α�  5  2  3  4  0  6  7  ...  1
//����     A  C  D  E        ...
//�±�  0  1  2  3  4  5  6  ...  999
//***************************************

//***************************************
//�α�  6  5  3  4  0  2  7  ...  1
//����     A  C  D  E  B      ...
//�±�  0  1  2  3  4  5  6  ...  999
//***************************************

//����ʵ�� 1A5--5B2--2C3--3D4--4E0--0..6--6.. �ڲ��ı���λ�û�����  ʵ���߼�����
status listinsert(staticlinklist L, int i, ElemType e)
{
	int l, j, k;
	k = MAXSIZE - 1;//��������һ��Ԫ��
	if (i<1 || i>listlength(L) + 1)
	{
		return ERROR;
	}
	j = malloc_sll(L);//jָ���������һ��Ԫ��λ���±�
	if (j)//��ȡ����
	{
		L[j].data = e;//����Ԫ�������ݴ��ڱ��������һ��Ԫ��λ����
		//��������ͨ���α�λ�õ���  ʵ�ְ��������Ԫ��
		for (l = 1; l <= i - 1; l++)
		{
			k = L[k].cur;//���������һ��Ԫ�ص�999 ���α� 1��k�� k=1��
			             //i=2  ֻ����һ��ѭ��  ����k��ȡֵΪ�����һ��Ԫ�ص��α�ֵ k=1

		}
		L[j].cur = L[k].cur; //L[5].cur=L[1].cur=2
		L[k].cur = j;//L[1].cur=5

		return OK;
	}
	return ERROR;
}

//ɾ��L�е�i������Ԫ��  ɾ��i=3 CԪ��  i��˳���Ǹ�������ṹ��˳�� ABCDE

//***************************************
//�α�  6  5  3  4  0  2  7  ...  1
//����     A  C  D  E  B      ...
//�±�  0  1  2  3  4  5  6  ...  999
//***************************************

//***************************************
//�α�  2  5  6  4  0  3  7  ...  1
//����     A     D  E  B      ...
//�±�  0  1  2  3  4  5  6  ...  999
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
		k = L[k].cur; //i=3 ִ������ѭ�� ��һ�� k=1; �ڶ��� k=5��
	}
	j = L[k].cur; //j=2;
	L[k].cur = L[j].cur;//L[2].cur=3  ��L[5].cur=3

	//���ӹ��� ��������CԪ�� ������������нڵ���Ϊ��������
	Free_sll(L, j);
	return OK;
}
//����������տ��нڵ���Ϊ��������
void Free_sll(staticlinklist space, int k)
{
	space[k].cur = space[0].cur; //space[2].cur = space[0].cur=6;
	space[0].cur = k;//space[0].cur =2;  //���±�Ϊ2��Ԫ�ػ��յ�������������
}