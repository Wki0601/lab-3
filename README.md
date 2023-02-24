# lab-3
顺序表

整体建表算法

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


运行结果

![122](https://user-images.githubusercontent.com/95995939/221172916-becda6e7-13f4-41d3-a71b-0b7fdfb1db4d.png)


![12](https://user-images.githubusercontent.com/95995939/221172928-2613631e-a1a4-45fa-bf31-dec47002ae98.png)
