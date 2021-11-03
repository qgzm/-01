#include <iostream>
using namespace std;

template <class T>
class MinHeap {	// ��С���ඨ��
private:
	T* heap;				// ��С��Ԫ�ش洢����
	int currentSize;		// ��С�ѵ�ǰԪ�ظ���
	int maxHeapSize;		// ��С���������

	void siftDown(int start, int m);	// �����㷨���� start ��ʼ���µ����� m
	void siftUp(int start);			// �����㷨���� start ��ʼ���ϵ���

public:
	MinHeap(int sz = 10);		// ���캯��������Ϊ sz

	MinHeap(T arr[], int n);			// ���캯���������� arr[ ] ���Ԫ�ش�����

	~MinHeap() { delete[]heap; }		// ��������

	bool Insert(const T d);			// ����
	bool Remove(T& d);					// ɾ��

	bool IsEmpty()const;				// �жѿշ�
	bool IsFull() const;				// �ж�����
	void MakeEmpty();					// �ÿն�

	void Display()const {
		for (int i = 0; i < currentSize; i++)
			cout << heap[i] << "  ";
		cout << endl;
	}

};

template <class T>
void MinHeap<T>::siftDown(int start, int m) {
	// ˽�к������ӽ�� start ��ʼ�� m Ϊֹ���������±Ƚϣ�
	// ����ǰstart��ָ�Ľڵ�ŵ���ȷ��λ�á�
	int i = start, j = 2 * i + 1;		//j������Ů��λ��
	T temp = heap[i];
	while (j <= m)
	{
		if (j<m && heap[j]>heap[j + 1])j++;	//��jֻ��������Ů�еĽ�С���Ǹ�
		if (temp <= heap[j])break;		//С�Ļ��Ͳ���Ҫ����
		else {
			heap[i] = heap[j]; i = j; j = 2 * j + 1;	//С�����ƣ���i��j���µ���
		}
	}
	heap[i] = temp;
}

template <class T>
void MinHeap<T>::siftUp(int start) {
	// ˽�к������ӽ�� start ��ʼ����� 0 Ϊֹ���������ϱȽϣ�
	// ����ǰstart��ָ�Ľڵ�ŵ���ȷ��λ�á�
	int j = start, i = (j - 1) / 2; T temp = heap[j];	//����jΪҪ���������ݣ�iΪ����˫�׽��,j��ֵ��ʱ���ţ������ж�ʱ����ĸ�ֵ����
	while (j > 0) {
		if (heap[i] <= temp)break;
		else {
			heap[j] = heap[i]; j = i; i = (i - 1) / 2;
		}
		heap[j] = temp;
	}
	heap[j] = temp;
}

template <class T>
MinHeap<T>::MinHeap(int sz) {		//�ö���һ���նѣ��ռ��С����Ϊʮ
// ���캯����������СΪ sz �Ķ�
	maxHeapSize = (10 < sz) ? sz : 10;
	heap = new T[maxHeapSize];	// �����ѿռ�
	if (heap == NULL) {
		cerr << "�Ѵ洢����ʧ�ܣ�" << endl;	exit(1);
	}
	currentSize = 0;	// ������ǰ��С
}

template <class T>
MinHeap<T>::MinHeap(T arr[], int n) {    //�ö��ǽ�һ������������
// ���캯���������� arr[ ] ���Ԫ�ش�����
	maxHeapSize = (10 < n) ? n : 10;
	heap = new T[maxHeapSize];
	if (heap == NULL) { cerr << "�Ѵ洢����ʧ�ܣ�" << endl; exit(1); }
	for (int i = 0; i < n; i++)heap[i] = arr[i];
	currentSize = n;
	int currentPos = (currentSize - 2) / 2;
	while (currentPos >= 0) {
		siftDown(currentPos, currentSize - 1);
		currentPos--;
	}
}

template <class T>
bool MinHeap<T>::Insert(const T x) {
	// �� x ���뵽��С����
	if (currentSize == maxHeapSize)
	{
		cerr << "Heap Full" << endl; return false;
	}
	heap[currentSize] = x;
	siftUp(currentSize);
	currentSize++;
	return true;

}

template <class T>
bool MinHeap<T>::Remove(T& x) {
	// �Ӷ���ɾ��Ԫ�أ����� x ����
	if (!currentSize)		//�ж��Ƿ�Ϊ��
	{
		cout << "Heap empty " << endl; return false;
	}
	x = heap[0]; heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);
	return true;	// ��"����СԪ��
}

template <class T>
bool MinHeap<T>::IsEmpty() const {
	// �жѿշ�
	if (currentSize == 0)
		return  true;
	else
		return false;
}
template <class T>
bool MinHeap<T>::IsFull() const {
	// �ж�����
	if (currentSize == maxHeapSize)
		return true;
	else
		return false;
}
template <class T>
void MinHeap<T>::MakeEmpty() {
	// �ÿն�
	currentSize = 0;
}

int main(void) {

	MinHeap<int> mp(10);

	int k[] = { 4, 2, 5, 8, 3, 6, 10, 14 };

	int i;
	for (i = 0; i < 8; i++) {
		mp.Insert(k[i]);
		cout << "���� " << k[i] << " ��\t";
		mp.Display();
	}

	cout << "*******************************************************" << endl;
	int a;
	mp.Remove(a);
	cout << "�� 1 ��ɾ��������Ϊ��" << a << "����Ϊ��";
	mp.Display();

	mp.Remove(a);
	cout << "�� 2 ��ɾ��������Ϊ��" << a << "����Ϊ��";
	mp.Display();


	cout << endl << endl;

	int data[] = { 100, 86, 48, 73, 35, 39, 42, 57, 66, 21 };
	cout << "����ǰ����";
	for (i = 0; i < 10; i++) {
		cout << data[i] << "  ";
	}
	cout << endl;

	MinHeap<int> mp1(data, 10);
	cout << "����Ѻ����";
	mp1.Display();
	cout << endl;

	system("pause");
	return 0;
}