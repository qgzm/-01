//#include <iostream>
//#include <string>
//#include<iomanip>
//using namespace std;


//int main()
//{
//	void select_sort(int array[], int n);
//	int a[10], i;
//	cout << "enter the originl:" << endl;
//	for (i = 0; i < 10;i++)
//		cin >> a[i];
//	cout << endl;
//	select_sort(a, 10);
//	cout << "the sorted array" << endl;
//	for (i = 0; i < 10; i++)
//		cout << a[i] << "    ";
//	cout << endl;
//	return 0;
//}
//void select_sort(int array[], int n)
//{
//	int i, j, k, t;
//	for (i = 0; i < n-1; i++)
//	{
//		k = i;
//		for (j = i + 1; j < n; j++)
//			if (array[j] < array[k])k = j;//用中间数k存放最小数角标，减去交换的过程，以减少计算
//		t = array[k]; array[k]=array[i]; array[i] = t;
//	}
//}

//int main()
//{
//	void smallest_string(char str[], int i);
//	int i;
//	char courtry_name[3][30];
//	for (i = 0; i < 3; i++)
//		cin >> courtry_name[i];
//	smallest_string(courtry_name,3);
//	return 0;
//}
//void smallest_string(char str[][30], int n)
//{
//	int i;
//	char string[30];
//	strcpy(string, str[0]);
//	for (i = 0; i < n; i++)
//		if (strcmp(str[i], string) < 0)
//			strcpy(string, str[i]);
//	cout << endl << "the smallest string is" << string << endl;
//}

//struct student
//{
//	int num;
//	float score;
//	struct student* next;
//};
//int main()
//{
//	student a, b, c, * head, * p;
//	a.num = 52; a.score = 9685;
//	b.num = 8653; b.score = 6835;
//	c.num = 352; c.score = 22.14;
//	head = &a;
//	a.next = &b;
//	b.next = &c;
//	c.next = NULL;
//	p = head;
//	do
//	{
//		cout << p  ->num << " " << p->score << endl;
//		p = p->next;
//	} while (p != NULL);
//	return 0;
//}

//int main()
//{
//	enum color{red,yellow,blue,white,black};
//	color pri;
//	int i, j, k, n = 0, loop;
//	for(i=red;i<=black;i++)
//		for(j=red;j<=black;j++)
//			if (i != j)
//			{
//				for(k=red;k<=black;)
//			}
//}


