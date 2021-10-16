#include <iostream>
#include<iomanip>


//using namespace std;
//class student
//{
//private:
//	int num;
//	int score;
//
//public:
//	void setdata()
//	{
//		cin >> num;
//		cin >> score;
//	}
//	void display()
//	{
//		cout << "num:" << num << endl;
//		cout << "score=" << score << endl;
//	};
//};
//
//student  stud1, stud2;
//int main()
//{
//	/*stud1.setdata();
//	stud2.setdata();
//	stud1.display();
//	stud2.display();*/
//
//	double a = 123.456789012345;
//	cout << a << endl;
//	cout << setiosflags(ios::fixed)<<a;
//
//	return 0;
//}

//using namespace std;
//template<typename T>
//T max(T a, T b, T c)
//{
//	if (b > a)a = b;
//	if (c > a)a = c;
//	return a;
//}
//int main()
//{
//	int i1 = 185, i2 = -76, i3 = 567, i;
//	double d1 = 56.87, d2 = 90.23, d3 = -3214.78,d;
//	long g1 = 67854, g2 = -912456, g3 = 673456, g;
//	i = max(i1, i2, i3);
//	d = max(d1, d2, d3);
//	g = max(g1, g2, g3);
//	cout << "i_max=" << i << endl;
//	cout << "d_max=" << d << endl;
//	cout << "g_max=" << g << endl;
//	return 0;
//}

//汉诺塔问题
//if (1 == n)
//{
//    直接将盘子从A移动到C；
//}
//else
//{
//    将n - 1个盘子从A借助C移动到B；
//        将编号n盘子直接从A移动到C；
//        最后将n - 1个盘子从B借助A移动到C；
//}
#include<iostream>

//using namespace std;
//void HanTowel(int n, char A, char B, char C)
//{
//    if (n == 1)
//    {
//        cout << "将编号为" << n << "盘子从" << A << "柱子移动到" << C << "柱子" << endl;
//    }
//    else
//    {
//        HanTowel(n - 1, A, C, B);
//        cout << "将编号为" << n << "盘子从" << A << "柱子移动到" << C << "柱子" << endl;
//        HanTowel(n - 1, B, A, C);
//
//    }
//}
//int main()
//{
//    char ch1 = 'A';
//    char ch2 = 'B';
//    char ch3 = 'C';
//    int n;
//
//    cout << "请输入要移动的盘子的个数：";
//    cin >> n;
//    HanTowel(n, 'A', 'B', 'C');
//    system("pause");
//    return 0;
//}