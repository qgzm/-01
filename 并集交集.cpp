#include <iostream>
#include "assert.h"
using namespace std;
//����sum aggregate
void sumAggregate(int arr1[], int arr2[], int n = 10)
{
	int i; static int j=0, fag = 0;
	for (i = 0; i < n; i++)			//�������1
		cout << arr1[i] << " ";
	for (i = 0; i < n; i++) {		//���������Ѱ�Ҳ�һ��������,���
		fag = 0;
		for (j = 0; j < n; j++){
			if (arr1[j] == arr2[i])
				fag = 1;
		}
		if(fag==0)cout << arr2[i] << " ";
	}
	cout << endl;

}
//����intersection
void intersection(int arr1[], int arr2[], int n = 10)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (arr1[i] == arr2[j])
				cout << arr1[j] << " ";			
	cout << endl;
}
//**************************************
void input(int* set, int length)
{
	for (int i = 0; i < length; i++)
	{
		cin >> set[i];
	}
}

void main()
{
	int set_1[10];
	int set_2[10];
	cout << "���뼯��1�е�����" << endl;
	input(set_1, sizeof(set_1) / sizeof(int));
	cout << "���뼯��2�е�����" << endl;
	input(set_2, sizeof(set_2) / sizeof(int));
	//����ɽ������Ĵ��룬�ڿ���̨����������ϵĽ����Ͳ���
	sumAggregate(set_1, set_2, 10);
	intersection(set_1, set_2, 10);
}