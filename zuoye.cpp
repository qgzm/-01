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
	SeqQueue(int sz=10);		//���캯��
	~SeqQueue() { makeEmpty(); };
	bool getFront(T& x);		//��ȡ����ͷ��Ԫ�ص�ֵ
	bool EnQueue(const T& x); // ��ָ��Ԫ����ջ
	bool DeQueue(T& x);			//���ж�Ԫ�س�ջ��
	bool isEmpty()const {
		return (front==rear ? true : false);
	}		//�ж�ջ�Ƿ�Ϊ��
	void makeEmpty(){ front = rear = 0; }	//��ն����е�Ԫ��
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
	if (isEmpty() == true)return false;//��top=-1ʱ,�᷵�ؼ�ֵ
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
	if (seq.isEmpty())cout << "˳��ջΪ��" << endl;
	else cout << "˳��ջ��Ϊ��" << endl;
	for (int i = 0; i < 5; i++)
	{
		seq.EnQueue(i);
	}
	int x;
	seq.DeQueue(x);
	cout << "��ջԪ����" << x << endl;
	if (seq.isEmpty())cout << "˳��ջΪ��" << endl;
	else cout << "˳��ջ��Ϊ��" << endl;
	x = 100; seq.EnQueue(x);
	cout << "��ջ�ɹ�" << endl;
	seq.makeEmpty();
	if (seq.isEmpty())cout << "˳��ջΪ��" << endl;
	else cout << "˳��ջ��Ϊ��" << endl;
}