#include <iostream>
using namespace std;

template <class T>
struct LinkNode
{
	T data;
	LinkNode <T>* next;
};
//****************************************************************
template <class T>
class LinkedList
{
private:
	LinkNode<T>* temp;
	LinkNode <T>* first;

public:
	LinkedList();
	LinkedList(LinkedList <T>& L);
	~LinkedList();
	int length();
	int search(T& x);
	bool getData(int index, T& x);
	bool setData(int index, T& x);
	bool insert(int index, T& x);
	bool remove(int index, T& x);
	bool isEmpty();
	void makeEmpty();
	void output();
};
//******************************************************************
template <class T>
LinkedList <T>::LinkedList()		//�����ʼ��
{
	first = new LinkNode<T>;
	temp = first;
	first->data = 0;
	first->next = NULL;
}

template <class T>
LinkedList <T>::LinkedList(LinkedList <T>& L)		//���ƹ��캯��
{
	T value;
	LinkNode<T>* srcptr = L.first;
	L.temp = L.first;
	LinkNode<T>* destptr = new LinkNode<T>;
	if (temp != NULL)
	{
		destptr = temp->data;
	}
	while (temp->next != NULL)
	{
		destptr->next = new LinkNode<T>;
		destptr = destptr->next;
		temp = temp->next;
	}

}

template <class T>
LinkedList <T>::~LinkedList()		//��������,�ͷſռ�
{
	makeEmpty();
}

template <class T>
int LinkedList <T>::length()		//����������
{
	int x = 0;
	temp = first;
	while (temp != NULL)
	{
		temp = temp->next;
		x++;
	}
	return x;
}

template <class T>
int LinkedList <T>::search(T& x)		//���������е�Ԫ��
{
	temp = first;
	int n = 0;
	while (temp != NULL)
	{
		if (temp->data == x)
			return n;
		temp = temp->next;
		n++;
	}
	return -1;
}

template <class T>
bool LinkedList <T>::getData(int index, T& x)	//ǰ��Ϊ������xΪҪ�����ֵ
{
	int n = 0;
	temp = first;
	if (index < 0)
		return false;
	while (temp != NULL)
	{
		if (n == index)
		{
			x = temp->data;
			return true;
		}
		temp = temp->next;
		n++;
	}
	return false;
}

template <class T>
bool LinkedList <T>::setData(int index, T& x)		//��������������ֵ
{
	temp = first;
	int n = 0;
	if (index < 0)
		return false;
	while (temp != NULL)
	{
		if (n == index)
		{
			temp->data = x;
			return true;
		}
		temp = temp->next;
		n++;
	}
	return false;
}

template <class T>
bool LinkedList <T>::insert(int index, T& x)	//����
{
	int n = 0;
	temp=first;
	struct LinkNode<T>* p = new LinkNode<T>;
	if (index < 0)
		return false;
	while (temp != NULL)
	{
		if (n == index)
		{
			p->data = x;
			p->next = temp->next;
			temp->next = p;
			return true;
		}
		temp = temp->next;
		n++;
	}
	return false;
}

template <class T>
bool LinkedList <T>::remove(int index, T& x)
{
	int n = 0; temp = first;
	struct LinkNode<T>* del ;
	if (index < 0)
		return false;
	if (n == 1)
	{
		del = temp; first = temp->next; 
	}
	else
	{
		for (n = 1; n < index - 1; n++)
			if (temp == NULL)break;
			else temp = temp->next;
		if(temp==NULL||temp->next==NULL)
		{
			cerr << "��Ч��ɾ��λ��!\n"; return false;
		}
		del = temp->next; temp->next = del->next;
	}
	delete temp; x = del->data;
	return true;
}

template <class T>
bool LinkedList <T>::isEmpty()		//�ж������Ƿ�Ϊ��
{
	if (first == NULL)
		return true;
	else  
		return false;
}

template <class T>
void LinkedList <T>::makeEmpty()		//ʹ����Ϊ��
{
	while (first->next != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
	delete first;
	first=NULL;
}

template <class T>
void LinkedList <T>::output()		//�������
{
	this->temp = this->first;
	while (temp != NULL)
	{
		//cout << temp->data << " ";
		//temp = temp->next;
	}
	cout << endl;
}
//******************************************************************
void main()
{
	LinkedList <int> seq;
	if (seq.isEmpty())cout << "����Ϊ��" << endl;
	else cout << "����Ϊ��" << endl;
	for (int i = 0; i < 5; i++)
	{
		seq.insert(i, i);
	}
	cout << "����ǰ�������£�" << endl;
	seq.output();
	if (seq.isEmpty())cout << "����Ϊ��" << endl;
	else cout << "����Ϊ��" << endl;

	int x;
	seq.remove(1, x);
	cout << "����ǰ�������£�" << endl;
	seq.output();
	if (seq.isEmpty())cout << "����Ϊ��" << endl;
	else cout << "����Ϊ��" << endl;

	cout << "�����ڵ�ǰԪ�ظ�����" << seq.length() << endl;
	x = 3;
	cout << "����" << x << "�������е�����λ��Ϊ��" << seq.search(x) << endl;
	seq.getData(1, x);
	cout << "������1������λ�õ�����ֵΪ��" << x << endl;
	x = 100;
	seq.setData(2, x);
	cout << "����ǰ�������£�" << endl;
	seq.output();
	seq.makeEmpty();
	if (seq.isEmpty())cout << "����Ϊ��" << endl;
	else cout << "����Ϊ��" << endl;
}