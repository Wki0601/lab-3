#include<stdio.h>
#include<malloc.h>
#define Maxsize 50
typedef char ElemType;
typedef struct
{
	ElemType data[Maxsize];
	int length;
}SqList;

void CreateList(SqList*& L, ElemType a[], int n)
{
	int i = 0, k = 0;
	L = (SqList*)malloc(sizeof(SqList));
	while (i < n)
	{
		L->data[k] = a[i];
		k++;i++;
	}
	L->length = k;
}

void InitList(SqList*& L)//��ʼ�����Ա�
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
void DestoryList(SqList*& L)//�������Ա�
{
	free(L);
}
bool ListEmpty(SqList*& L)//�ж����Ա��Ƿ�Ϊ�ռ�
{
	return(L->length == 0);
}
int ListLength(SqList* L)//�����Ա�ĳ���
{
	return(L->length);
}
void DispList(SqList* L)//������Ա�
{
	for (int i = 0;i < L->length;i++)
	{
		printf("%d", L->data[i]);
		printf("\n");
	}
}
bool GetElem(SqList* L, int i, ElemType& e)//����������Ա��е�Ԫ��
{
	if (i<1 || i>L->length)
		return false;
	e = L->data[i - 1];
	return true;
}
int LocateElem(SqList* L, ElemType e)//��Ԫ��ֵ����
{
	int i = 0;
	while (i < L->length&& L->data[i] != e)
		i++;
	if (i >= L->length)
		return 0;
	else
		return i + 1;
}
bool ListInsert(SqList*& L, int i, ElemType e)//��������Ԫ��
{
	int j;
	if (i<1 || i>L->length + 1 || L->length == Maxsize)
		return false;
	i--;
	for (j = L->length;j > i;j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
	return true;
}
bool ListDelete(SqList*& L, int i, ElemType& e)//ɾ������Ԫ��
{
	int j;
	if (i<1 || i>L->length)
		return false;
	i--;
	e = L->data[i];
	for (j = i;j < L->length - 1;j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return true;
}

int main()
{
	SqList* L;
	ElemType e;
	printf("˳���Ļ����������£�\n");
	printf("	(1)��ʼ��˳���L\n");
	InitList(L);
	printf("	(2)���β���a,b,c,d,eԪ��\n");
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("	(3)���˳���L��");
	DispList(L);
	printf("	(4)˳���L���ȣ�%d\n", ListLength(L));
	printf("	(5)˳���LΪ%s\n", (ListEmpty(L) ? "��" : "�ǿ�"));
	GetElem(L, 3, e);
	printf("	(6)˳���L�ĵ�3��Ԫ�أ�%c\n", e);
	printf("	(7)Ԫ��a��λ�ã�%d\n", LocateElem(L, 'a'));
	printf("	(8)Ԫ��a��λ���ϲ���fԪ��\n");
	ListInsert(L, 4, 'f');
	printf("	(9)���˳���L��");
	DispList(L);
	printf("	(10)ɾ��L�ĵ�3��Ԫ��\n");
	ListDelete(L, 3, e);
	printf("	(11)���˳���L:");
	DispList(L);
	printf("	(12)�ͷ�˳���L\n");
	DestoryList(L);
	return 1;
}