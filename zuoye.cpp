#include <iostream>
#include<assert.h>
using namespace std;
template<class T>
class Queue
{
public:
	Queue() {};
	~Queue() {};
	virtual bool EnQueue(const T& x) = 0;
	virtual bool DeQueue(T& x) = 0;
	virtual bool getFront(T& x) = 0;
	virtual bool isEmpty()const = 0;
};
template<class T>
class SeqQueue :public Queue<T>
{
public:
	SeqQueue(int sz=10);		//构造函数
	~SeqQueue() { makeEmpty(); };
	bool getFront(T& x);		//获取队列头部元素的值
	bool EnQueue(const T& x); // 将指定元素入栈
	bool DeQueue(T& x);			//队列顶元素出栈。
	bool isEmpty()const {
		return (front==rear ? true : false);
	}		//判断栈是否为空
	void makeEmpty(){ front = rear = 0; }	//清空队列中的元素
	bool isFull()const { return ((rear + 1) % maxSize == front) ? true:false; }
private:
	int rear, front;
	T* elements;
	int maxSize;
};
template<class T>
SeqQueue<T>::SeqQueue(int sz) :front(0), rear(0), maxSize(sz) {
	elements = new T[maxSize]; assert(elements != NULL);
}
template<class T>
bool SeqQueue<T>::getFront(T& x)
{
	if (isEmpty() == true)return false;//当top=-1时,会返回假值
	x = elements[front];
	return true;
}
template<class T>
bool SeqQueue<T>::EnQueue(const T& x)
{
	if (isFull() == true)return false;
	elements[rear] = x;
	rear = (rear + 1) % maxSize;
	return true;
}
template<class T>
bool SeqQueue<T>::DeQueue(T& x)
{
	if (isEmpty() == true)return false;
	x = elements[front];
	front = (front + 1) % maxSize;
	return true;
}
void main()
{
	SeqQueue <int> seq;
	if (seq.isEmpty())cout << "顺序栈为空" << endl;
	else cout << "顺序栈不为空" << endl;
	for (int i = 0; i < 5; i++)
	{
		seq.EnQueue(i);
	}
	int x;
	seq.DeQueue(x);
	cout << "出栈元素是" << x << endl;
	if (seq.isEmpty())cout << "顺序栈为空" << endl;
	else cout << "顺序栈不为空" << endl;
	x = 100; seq.EnQueue(x);
	cout << "出栈成功" << endl;
	seq.makeEmpty();
	if (seq.isEmpty())cout << "顺序栈为空" << endl;
	else cout << "顺序栈不为空" << endl;
}