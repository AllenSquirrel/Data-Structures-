#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dynamic_array.h"

int main()
{
	//��ʼ����̬����
	Dynamic_array* myarr= Init_array();
	//��ӡ����
	printf("������%d", myarr->cap);
	printf("��С: %d",myarr->size);

	//����һ��Ԫ��
	for (int i = 0; i < 30; i++)
	{
		pushback_array(myarr, i);
	}
	printf("������%d", myarr->cap);
	printf("��С: %d", myarr->size);
	print_array(myarr);
	

	//ɾ��
	removebypos_array(myarr,0);
	removebyval_array(myarr,27);
	print_array(myarr);

	//����
	printf("���ҵ�Ԫ��λ�ã�%d", find_array(myarr, 5));
	freespace_array(myarr);

	return 0;
}