#include <stdio.h>
#include <stdlib.h>

/*
	ʵ�ֳ�������
	--zjp
	marc07@qq.com
*/

#define MAXSIZE	10
typedef struct
{
	int r[MAXSIZE + 1];	//���ڴ洢Ҫ��������飬r[0]�����ڱ�����ʱ����
	int length;			//���ڼ�¼˳���ĳ���
}SqList;

typedef enum
{
	FALSE = 0,
	TRUE
}Status;

//��������ǰ������Ԫ��
void Swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

//��ӡ������
void Print_Result(SqList *L)
{
	printf("sort result: \n");
	for (int i = 1; i <= L->length; i++)
	{
		printf("%d ", L->r[i]);
	}
	printf("\n");
}

/****************************************1��ð������**************************************************/
//ð�������㷨1--����ð������
void BubbleSort_1(void)
{
	int i, j;
	SqList L = { { 9999, 9, 1, 5, 8, 3, 7, 2, 4, 6, 10 }, MAXSIZE };//��Ԫ�ر���ʹ�ã���������������

	for (i = 1; i <= L.length; i++)
	{
		for (j = i + 1; j <= L.length; j++)
		{
			if (L.r[i] > L.r[j])	//����
			{
				Swap(&L, i, j);
			}
		}
	}

	Print_Result(&L);//��ӡ������
}

//ð�������㷨2--����ð������
void BubbleSort_2(void)
{
	int i, j;
	SqList L = { { 9999, 9, 1, 5, 8, 3, 7, 2, 4, 6, 10 }, MAXSIZE };//��Ԫ�ر���ʹ�ã���������������

	for (i = 1; i < L.length; i++)
	{
		for (j = L.length - 1; j >= i; j--)
		{
			if (L.r[j] > L.r[j + 1])//ð������
			{
				Swap(&L, j, j+1);
			}
		}
	}

	Print_Result(&L);//��ӡ������
}

//ð�������㷨2--ð���Ż�
//�ɱ����ڴ󲿷�Ԫ�������������½����������ѭ���ж�
void BubbleSort_2_Improve(void)
{
	int i, j;
	Status flag = TRUE;//��ӱ�Ǵ���
	SqList L = { { 9999, 2, 1, 3, 4, 5, 6, 7, 8, 9, 10 }, MAXSIZE };//��Ԫ�ر���ʹ�ã���������������
	//ע�⣬����Ԫ���Ѵ󲿷�����
	for (i = 1; i < L.length && flag; i++)//����flag
	{
		flag = FALSE;//Ĭ��FALSE
		for (j = L.length - 1; j >= i; j--)
		{
			if (L.r[j] > L.r[j+1])
			{
				Swap(&L, j, j+1);
				flag = TRUE; //�޸ı�ǣ�����ָʾ��Ҫ������һ��ѭ���жϣ�����������ɡ�
			}
		}
	}

	Print_Result(&L);//��ӡ������
}

/****************************************2��ѡ������**************************************************/
void SelectSort(void)
{
	int i, j, min;
	SqList L = { { 9999, 9, 1, 5, 8, 3, 7, 2, 4, 6, 10 }, MAXSIZE };//��Ԫ�ر���ʹ�ã���������������

	for (i = 1; i < L.length; i++)
	{
		min = i;
		for (j = i + 1; j <= L.length; j++)
		{
			if (L.r[min] > L.r[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(&L, i, min);
		}
	}

	Print_Result(&L);//��ӡ������
}

/****************************************3��ֱ�Ӳ�������**************************************************/
void InsertSort(void)
{
	int i, j;
	SqList L = { { 0, 5, 1, 4, 6, 2 }, 5 };//��Ԫ�����ڱ�����������������

	for (i = 2; i <= L.length; i++)
	{
		if (L.r[i] < L.r[i - 1])
		{
			L.r[0] = L.r[i];
			for (j = i - 1; L.r[j] > L.r[0]; j--)
			{
				L.r[j + 1] = L.r[j];
			}
			L.r[j + 1] = L.r[0];
		}
	}

	Print_Result(&L);//��ӡ������
}

/****************************************4��ϣ������**************************************************/



void test_Sort(void)
{
	//1��ð������
	//BubbleSort_1();
	//BubbleSort_2();
	//BubbleSort_2_Improve();

	//2��ѡ������
	//SelectSort();

	//3��ֱ�Ӳ�������
	InsertSort();
}

