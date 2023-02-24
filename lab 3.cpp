#include<iostream>
#include<malloc.h>
#include<stdio.h>
#include"sqlist.h"
using namespace std;

int main() {
	SqList* L1, * L2, * L3, * L4;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	InitList(L4);
	int i = 0, j = 0, k = 0;
	cout << "请按指数的升序输入第一个多项式各项的指数和系数" << endl;
	while (true) {
		cin >> L1->data[i].power >> L1->data[i].coe;
		if (L1->data[i].power == 0 && L1->data[i].coe == 0)	break;
		i++;
	}//存储第一个多项式
	L1->length = i;
	i = 0;
	cout << "请按指数的升序输入第二个多项式各项的指数和系数" << endl;
	while (true) {
		cin >> L2->data[i].power >> L2->data[i].coe;
		if (L2->data[i].power == 0 && L2->data[i].coe == 0)	break;
		i++;
	}//存储第二个多项式
	L2->length = i;
	i = 0;
	for (j = 0; j < L1->length; j++) {
		for (k = 0; k < L2->length; k++) {
			L3->data[j + k + i].coe = L1->data[j].coe * L2->data[k].coe;
			L3->data[j + k + i].power = L1->data[j].power + L2->data[k].power;
		}
		i++;
	}//计算乘法
	L3->length = j + k + i - 2;
	i = 0; j = 0; k = 0;
	merge_type(L3);
	if (L1->data[L1->length - 1].power > L2->data[L2->length - 1].power) {
		while (i < L1->length) {
			while (j < L2->length) {
				if (L1->data[i].power > L2->data[j].power) {
					L4->data[k] = L2->data[j];
					k++; j++;
					continue;
				}
				if (L1->data[i].power < L2->data[j].power) {
					L4->data[k] = L1->data[i];
					k++;
					break;
				}
				else {
					L4->data[k].coe = L1->data[i].coe + L2->data[j].coe;
					L4->data[k].power = L1->data[i].power;
					k++; j++;
					break;
				}
			}
			i++;
		}
		L4->data[k] = L1->data[i - 1];
	}
	if (L1->data[L1->length - 1].power >= L2->data[L2->length - 1].power) {
		while (i < L2->length) {
			while (j < L1->length) {
				if (L2->data[i].power > L1->data[j].power) {
					L4->data[k] = L1->data[j];
					k++; j++;
					continue;
				}
				if (L2->data[i].power < L1->data[j].power) {
					L4->data[k] = L2->data[i];
					k++;
					break;
				}
				else {
					L4->data[k].coe = L1->data[j].coe + L2->data[i].coe;
					L4->data[k].power = L2->data[i].power;
					k++; j++;
					break;
				}
			}
			i++;
		}
		k--;
	}
	else {
		while (i < L2->length) {
			while (j < L1->length) {
				if (L2->data[i].power > L1->data[j].power) {
					L4->data[k] = L1->data[j];
					k++; j++;
					continue;
				}
				if (L2->data[i].power < L1->data[j].power) {
					L4->data[k] = L2->data[i];
					k++;
					break;
				}
				else {
					L4->data[k].coe = L1->data[j].coe + L2->data[i].coe;
					L4->data[k].power = L2->data[i].power;
					k++; j++;
					break;
				}
			}
			i++;
		}
		L4->data[k] = L2->data[i - 1];
	}
	L4->length = k + 1;
	cout << "加法：";
	DispList(L4);
	cout << "乘法：";
	DispList(L3);

	return 0;
}