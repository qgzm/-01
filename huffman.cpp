#include <iostream>
using namespace std;

//--------------------TreeNode--------------------
template <class T>
class TreeNode
{
public:
	T data;
	TreeNode* leftChild;
	TreeNode* rightChild;
	TreeNode* parent;

public:
	TreeNode() { leftChild = NULL; rightChild = NULL; parent = NULL; }
	TreeNode(T elem, TreeNode<T>* left = NULL, TreeNode<T>* right = NULL, TreeNode<T>* pr = NULL) : data(elem), leftChild(left), rightChild(right), parent(pr) { }
	bool operator <= (TreeNode<T>& R) { return data <= R.data; }
	bool operator > (TreeNode<T>& R) { return data > R.data; }
	TreeNode& operator + (TreeNode<T>& R)
	{
		TreeNode<T> a;
		a.data = data + R.data;
		return a;
	}

};

//*********************************************************
//--------------------MinHeap--------------------

template <class T>
class MinHeap {	// ��С���ඨ��
private:
	TreeNode<T>** heap;	// ��С��Ԫ�ش洢����
	int currentSize;		// ��С�ѵ�ǰԪ�ظ���
	int maxHeapSize;		// ��С���������

	void siftDown(int start, int m);	// �����㷨���� start ��ʼ���µ����� m
	void siftUp(int start);			// �����㷨���� start ��ʼ���ϵ���

public:
	MinHeap(int sz = 10);		// ���캯��������Ϊ sz

	MinHeap(T arr[], int n);			// ���캯���������� arr[ ] ���Ԫ�ش�����

	~MinHeap() { delete[]heap; }		// ��������

	bool Insert(TreeNode<T>*& d);			// ����
	bool Remove(TreeNode<T>*& d);					// ɾ��

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
	int i = start, j = 2 * i + 1;  	// j �� i ������Ůλ��
	TreeNode<T>* temp = heap[i];
	while (j <= m) {	// ����Ƿ����λ��
		if (j < m && heap[j]->data > heap[j + 1]->data)	// �� j ָ������Ů�е�С��
			j++;
		if (temp->data <= heap[j]->data)	// С��������
			break;
		else {		// ����С������, i, j�½�
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;	// �ط�temp���ݴ��Ԫ��
}

template <class T>
void MinHeap<T>::siftUp(int start) {
	// ˽�к������ӽ�� start ��ʼ����� 0 Ϊֹ���������ϱȽϣ�
	// ����ǰstart��ָ�Ľڵ�ŵ���ȷ��λ�á�
	int j = start, i = (j - 1) / 2;
	TreeNode<T>* temp = heap[j];
	while (j > 0) {	// �ظ����·������ֱ���
		if (heap[i]->data <= temp->data) break;	// �����ֵС, ������
		else {	// �������ֵ��, ����
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;	// ����
}

template <class T>
MinHeap<T>::MinHeap(int sz) {
	// ���캯����������СΪ sz �Ķ�
	maxHeapSize = (10 < sz) ? sz : 10;
	heap = new TreeNode<T> *[maxHeapSize];	// �����ѿռ�
	if (heap == NULL) {
		cerr << "�Ѵ洢����ʧ�ܣ�" << endl;	exit(1);
	}
	currentSize = 0;	// ������ǰ��С
}

template <class T>
MinHeap<T>::MinHeap(T arr[], int n) {
	// ���캯���������� arr[ ] ���Ԫ�ش�����
	maxHeapSize = (10 < n) ? n : 10;
	heap = new TreeNode<T> *[maxHeapSize];
	if (heap == NULL) {
		cerr << "�Ѵ洢����ʧ�ܣ�" << endl;	exit(1);
	}
	for (int i = 0; i < n; i++)
		heap[i] = arr[i];
	currentSize = n;	// ���ƶ�����, ������ǰ��С
	int m = 1;
	int currentPos = (currentSize - 2) / 2;	// ���������λ�ã�������֧���
	while (currentPos >= 0) {	// �����������
		siftDown(currentPos, currentSize - 1);	// �ֲ����������»�����
		currentPos--;
	}
}

template <class T>
bool MinHeap<T>::Insert(TreeNode<T>*& x) {
	// �� x ���뵽��С����
	if (currentSize == maxHeapSize)	// ����
	{
		cout << "Heap Full" << endl;  return false;
	}
	heap[currentSize] = x;	// ����
	siftUp(currentSize);	// ���ϵ���
	currentSize++;			// �Ѽ�����1
	return true;
}

template <class T>
bool MinHeap<T>::Remove(TreeNode<T>*& x) {
	// �Ӷ���ɾ��Ԫ�أ����� x ����
	if (currentSize <= 0)	// �ѿ�, ���� false
	{
		cout << "Heap empty" << endl;	return false;
	}
	x = heap[0];
	heap[0] = heap[--currentSize];
	siftDown(0, currentSize - 1);	// �������µ���Ϊ��
	return true;	// ������СԪ��
}

template <class T>
bool MinHeap<T>::IsEmpty() const {
	// �жѿշ�
	return  currentSize == 0;
}
template <class T>
bool MinHeap<T>::IsFull() const {
	// �ж�����
	return currentSize == maxHeapSize;
}
template <class T>
void MinHeap<T>::MakeEmpty() {
	// �ÿն�
	currentSize = 0;
}

void outputPr(TreeNode<float>* node)
{
	while (node != 0)
	{
		cout << node->data << " ";
		node = node->parent;
	}
	cout << endl;
}

//*************************************************************************
//--------------------------------HuffmanTree-------------------------------

template <class T>
class HuffmanTree
{
protected:
	TreeNode<T>* root;

protected:
	void deleteTree(TreeNode<T>* t);
	void mergeTree(TreeNode<T>* h1, TreeNode<T>* h2, TreeNode<T>*& pr);
	void PostOrder(TreeNode<T>* node, void (*fun)(TreeNode<T>* node));
public:
	HuffmanTree(T w[], int n);
	~HuffmanTree() { deleteTree(root); }
public:
	void PostOrder(void (*fun)(TreeNode<T>* node));
};

template <class T>
HuffmanTree<T>::HuffmanTree(T w[], int n) {
	MinHeap<T> hp;
	TreeNode<T>* first, * second, * parent;
	for(int i=0;i<n;i++)
	{
		TreeNode<T>* work = new TreeNode<T>;
		work->data = w[i];
		work->leftChild = NULL;
		work->rightChild = NULL;
		work->parent = NULL;
		hp.Insert(work);
	}
	for (int i = 0; i < n - 1; i++) {
		hp.Remove(first);
		hp.Remove(second);
		mergeTree(first, second, parent);
		hp.Insert(parent);
	}
	hp.Remove(root);

}

template <class T>
void HuffmanTree<T>::deleteTree(TreeNode<T>* t) {

	if (t == NULL)return;
	deleteTree(t->leftChild);
	deleteTree(t->rightChild);
	if (t->parent != NULL) {
		if (t == t->parent->leftChild)t->parent->leftChild = NULL;
		else if (t == t->parent->rightChild)t->parent->rightChild = NULL;
	}
	delete t;

}

template <class T>
void HuffmanTree<T>::mergeTree(TreeNode<T>* h1, TreeNode<T>* h2, TreeNode<T>*& pr) {
	pr = new TreeNode<T>;
	pr->leftChild = h1; pr->rightChild = h2;
	pr->data = h1->data + h2->data;
	h1->parent = h2->parent = pr;


}

template <class T>
void HuffmanTree<T>::PostOrder(TreeNode<T>* node, void (*fun)(TreeNode<T>* node))
{
	if (node == NULL)return;
	fun(node);
	PostOrder(node->leftChild, fun);
	PostOrder(node->rightChild, fun);
}

template <class T>
void HuffmanTree<T>::PostOrder(void (*fun)(TreeNode<T>* node))
{
	PostOrder(root, outputPr);
}


void main()
{
	float a[] = { 7,5,2,4 };
	HuffmanTree<float> ht(a, 4);
	ht.PostOrder(outputPr);
}