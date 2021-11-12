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
class MinHeap {	// 最小堆类定义
private:
	TreeNode<T>** heap;	// 最小堆元素存储数组
	int currentSize;		// 最小堆当前元素个数
	int maxHeapSize;		// 最小堆最大容量

	void siftDown(int start, int m);	// 调整算法：从 start 开始向下调整到 m
	void siftUp(int start);			// 调整算法：从 start 开始向上调整

public:
	MinHeap(int sz = 10);		// 构造函数：长度为 sz

	MinHeap(T arr[], int n);			// 构造函数：用数组 arr[ ] 里的元素创建堆

	~MinHeap() { delete[]heap; }		// 析构函数

	bool Insert(TreeNode<T>*& d);			// 插入
	bool Remove(TreeNode<T>*& d);					// 删除

	bool IsEmpty()const;				// 判堆空否
	bool IsFull() const;				// 判堆满否
	void MakeEmpty();					// 置空堆

	void Display()const {
		for (int i = 0; i < currentSize; i++)
			cout << heap[i] << "  ";
		cout << endl;
	}

};

template <class T>
void MinHeap<T>::siftDown(int start, int m) {
	// 私有函数：从结点 start 开始到 m 为止，自上向下比较，
	// 将当前start所指的节点放到正确的位置。
	int i = start, j = 2 * i + 1;  	// j 是 i 的左子女位置
	TreeNode<T>* temp = heap[i];
	while (j <= m) {	// 检查是否到最后位置
		if (j < m && heap[j]->data > heap[j + 1]->data)	// 让 j 指向两子女中的小者
			j++;
		if (temp->data <= heap[j]->data)	// 小则不做调整
			break;
		else {		// 否则小者上移, i, j下降
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;	// 回放temp中暂存的元素
}

template <class T>
void MinHeap<T>::siftUp(int start) {
	// 私有函数：从结点 start 开始到结点 0 为止，自下向上比较，
	// 将当前start所指的节点放到正确的位置。
	int j = start, i = (j - 1) / 2;
	TreeNode<T>* temp = heap[j];
	while (j > 0) {	// 沿父结点路径向上直达根
		if (heap[i]->data <= temp->data) break;	// 父结点值小, 不调整
		else {	// 父结点结点值大, 调整
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;	// 回送
}

template <class T>
MinHeap<T>::MinHeap(int sz) {
	// 构造函数：建立大小为 sz 的堆
	maxHeapSize = (10 < sz) ? sz : 10;
	heap = new TreeNode<T> *[maxHeapSize];	// 创建堆空间
	if (heap == NULL) {
		cerr << "堆存储分配失败！" << endl;	exit(1);
	}
	currentSize = 0;	// 建立当前大小
}

template <class T>
MinHeap<T>::MinHeap(T arr[], int n) {
	// 构造函数：用数组 arr[ ] 里的元素创建堆
	maxHeapSize = (10 < n) ? n : 10;
	heap = new TreeNode<T> *[maxHeapSize];
	if (heap == NULL) {
		cerr << "堆存储分配失败！" << endl;	exit(1);
	}
	for (int i = 0; i < n; i++)
		heap[i] = arr[i];
	currentSize = n;	// 复制堆数组, 建立当前大小
	int m = 1;
	int currentPos = (currentSize - 2) / 2;	// 找最初调整位置：即最后分支结点
	while (currentPos >= 0) {	// 逐步向上扩大堆
		siftDown(currentPos, currentSize - 1);	// 局部自上向下下滑调整
		currentPos--;
	}
}

template <class T>
bool MinHeap<T>::Insert(TreeNode<T>*& x) {
	// 将 x 插入到最小堆中
	if (currentSize == maxHeapSize)	// 堆满
	{
		cout << "Heap Full" << endl;  return false;
	}
	heap[currentSize] = x;	// 插入
	siftUp(currentSize);	// 向上调整
	currentSize++;			// 堆计数加1
	return true;
}

template <class T>
bool MinHeap<T>::Remove(TreeNode<T>*& x) {
	// 从堆中删除元素，并用 x 返回
	if (currentSize <= 0)	// 堆空, 返回 false
	{
		cout << "Heap empty" << endl;	return false;
	}
	x = heap[0];
	heap[0] = heap[--currentSize];
	siftDown(0, currentSize - 1);	// 自上向下调整为堆
	return true;	// 返回最小元素
}

template <class T>
bool MinHeap<T>::IsEmpty() const {
	// 判堆空否
	return  currentSize == 0;
}
template <class T>
bool MinHeap<T>::IsFull() const {
	// 判堆满否
	return currentSize == maxHeapSize;
}
template <class T>
void MinHeap<T>::MakeEmpty() {
	// 置空堆
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