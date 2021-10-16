#include <iostream>
#include "assert.h"
using namespace std;
//并集sum aggregate
void sumAggregate(int arr1[], int arr2[], int n = 10)
{
	int i; static int j=0, fag = 0;
	for (i = 0; i < n; i++)			//输出数组1
		cout << arr1[i] << " ";
	for (i = 0; i < n; i++) {		//在数组二中寻找不一样的数据,输出
		fag = 0;
		for (j = 0; j < n; j++){
			if (arr1[j] == arr2[i])
				fag = 1;
		}
		if(fag==0)cout << arr2[i] << " ";
	}
	cout << endl;

}
//交集intersection
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
	cout << "输入集合1中的内容" << endl;
	input(set_1, sizeof(set_1) / sizeof(int));
	cout << "输入集合2中的内容" << endl;
	input(set_2, sizeof(set_2) / sizeof(int));
	//请完成接下来的代码，在控制台输出两个集合的交集和并集
	sumAggregate(set_1, set_2, 10);
	intersection(set_1, set_2, 10);
}