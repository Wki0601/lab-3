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

void InitList(SqList*& L)//初始化线性表
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
void DestoryList(SqList*& L)//销毁线性表
{
	free(L);
}
bool ListEmpty(SqList*& L)//判断线性表是否为空集
{
	return(L->length == 0);
}
int ListLength(SqList* L)//求线性表的长度
{
	return(L->length);
}
void DispList(SqList* L)//输出线性表
{
	for (int i = 0;i < L->length;i++)
	{
		printf("%d", L->data[i]);
		printf("\n");
	}
}
bool GetElem(SqList* L, int i, ElemType& e)//按序号求线性表中的元素
{
	if (i<1 || i>L->length)
		return false;
	e = L->data[i - 1];
	return true;
}
int LocateElem(SqList* L, ElemType e)//按元素值查找
{
	int i = 0;
	while (i < L->length&& L->data[i] != e)
		i++;
	if (i >= L->length)
		return 0;
	else
		return i + 1;
}
bool ListInsert(SqList*& L, int i, ElemType e)//插入数据元素
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
bool ListDelete(SqList*& L, int i, ElemType& e)//删除数据元素
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
	printf("顺序表的基本运算如下：\n");
	printf("	(1)初始化顺序表L\n");
	InitList(L);
	printf("	(2)依次插入a,b,c,d,e元素\n");
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("	(3)输出顺序表L：");
	DispList(L);
	printf("	(4)顺序表L长度：%d\n", ListLength(L));
	printf("	(5)顺序表L为%s\n", (ListEmpty(L) ? "空" : "非空"));
	GetElem(L, 3, e);
	printf("	(6)顺序表L的第3个元素：%c\n", e);
	printf("	(7)元素a的位置：%d\n", LocateElem(L, 'a'));
	printf("	(8)元素a的位置上插入f元素\n");
	ListInsert(L, 4, 'f');
	printf("	(9)输出顺序表L：");
	DispList(L);
	printf("	(10)删除L的第3个元素\n");
	ListDelete(L, 3, e);
	printf("	(11)输出顺序表L:");
	DispList(L);
	printf("	(12)释放顺序表L\n");
	DestoryList(L);
	return 1;
}