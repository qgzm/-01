#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
template <class T>
class SeqStack {
private:T* array;
	   int top;
	   int maxsize;
public:SeqStack(int max);
	  ~SeqStack() { delete[]array; }
	  bool gettop(T& x);
	  bool push(T& x);
	  bool pop(T& x);
	  bool isEmpty();
	  bool isFull();
	  void makeEmpty();
};
//********************************************************************
template <class T>
SeqStack<T>::SeqStack(int max) {
	if (max < 0) { exit(1); }
	maxsize = max;
	array = new T[maxsize];
	top = -1;
}
template <class T>
bool SeqStack<T>::gettop(T& x) {
	if (isEmpty() == true)exit(1);
	x = array[top];
	return true;
}
template <class T>
bool SeqStack<T>::push(T& x) {
	if (isFull() == true)exit(1);
	top++;
	array[top] = x;
	return true;
}
template <class T>
bool SeqStack<T>::pop(T& x) {
	if (isEmpty() == true)exit(1);
	x = array[top];
	top--;
	return true;
}
template <class T>
bool SeqStack<T>::isEmpty() {
	if (top == -1)
		return true;
	else return false;
}
template <class T>
bool SeqStack<T>::isFull() {
	if (top + 1 == maxsize)
		return true;
	else return false;
}
template <class T>
void SeqStack<T>::makeEmpty() {
	top = -1;
}

void prin(int x)
{
	int n = x, m, i;
	SeqStack<int> ad(20);
	while (n != 0)//n 是商
	{
		m = n % 2; n = n / 2; ad.push(m);
	}
	while(ad.isEmpty()==false) {
		ad.pop(i); cout << i;
	}
}
void main()
{
	int x;
	cin >> x;
	//完成程序，输出x变量所对应的2进制数。
	prin(x);
}