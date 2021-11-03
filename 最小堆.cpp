#include <iostream>
using namespace std;

template <class T>
class MinHeap {	// 最小堆类定义
private:
	T* heap;				// 最小堆元素存储数组
	int currentSize;		// 最小堆当前元素个数
	int maxHeapSize;		// 最小堆最大容量

	void siftDown(int start, int m);	// 调整算法：从 start 开始向下调整到 m
	void siftUp(int start);			// 调整算法：从 start 开始向上调整

public:
	MinHeap(int sz = 10);		// 构造函数：长度为 sz

	MinHeap(T arr[], int n);			// 构造函数：用数组 arr[ ] 里的元素创建堆

	~MinHeap() { delete[]heap; }		// 析构函数

	bool Insert(const T d);			// 插入
	bool Remove(T& d);					// 删除

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
	int i = start, j = 2 * i + 1;		//j是左子女的位置
	T temp = heap[i];
	while (j <= m)
	{
		if (j<m && heap[j]>heap[j + 1])j++;	//让j只想两个子女中的较小的那个
		if (temp <= heap[j])break;		//小的话就不需要调整
		else {
			heap[i] = heap[j]; i = j; j = 2 * j + 1;	//小者上移，且i与j往下调整
		}
	}
	heap[i] = temp;
}

template <class T>
void MinHeap<T>::siftUp(int start) {
	// 私有函数：从结点 start 开始到结点 0 为止，自下向上比较，
	// 将当前start所指的节点放到正确的位置。
	int j = start, i = (j - 1) / 2; T temp = heap[j];	//定义j为要调整的数据，i为他的双亲结点,j的值暂时存着，减少判断时多余的赋值步骤
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
MinHeap<T>::MinHeap(int sz) {		//该堆是一个空堆，空间大小起码为十
// 构造函数：建立大小为 sz 的堆
	maxHeapSize = (10 < sz) ? sz : 10;
	heap = new T[maxHeapSize];	// 创建堆空间
	if (heap == NULL) {
		cerr << "堆存储分配失败！" << endl;	exit(1);
	}
	currentSize = 0;	// 建立当前大小
}

template <class T>
MinHeap<T>::MinHeap(T arr[], int n) {    //该堆是将一个数组放入堆中
// 构造函数：用数组 arr[ ] 里的元素创建堆
	maxHeapSize = (10 < n) ? n : 10;
	heap = new T[maxHeapSize];
	if (heap == NULL) { cerr << "堆存储分配失败！" << endl; exit(1); }
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
	// 将 x 插入到最小堆中
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
	// 从堆中删除元素，并用 x 返回
	if (!currentSize)		//判断是否为零
	{
		cout << "Heap empty " << endl; return false;
	}
	x = heap[0]; heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);
	return true;	// 返"回最小元素
}

template <class T>
bool MinHeap<T>::IsEmpty() const {
	// 判堆空否
	if (currentSize == 0)
		return  true;
	else
		return false;
}
template <class T>
bool MinHeap<T>::IsFull() const {
	// 判堆满否
	if (currentSize == maxHeapSize)
		return true;
	else
		return false;
}
template <class T>
void MinHeap<T>::MakeEmpty() {
	// 置空堆
	currentSize = 0;
}

int main(void) {

	MinHeap<int> mp(10);

	int k[] = { 4, 2, 5, 8, 3, 6, 10, 14 };

	int i;
	for (i = 0; i < 8; i++) {
		mp.Insert(k[i]);
		cout << "插入 " << k[i] << " ：\t";
		mp.Display();
	}

	cout << "*******************************************************" << endl;
	int a;
	mp.Remove(a);
	cout << "第 1 次删除的数据为：" << a << "，堆为：";
	mp.Display();

	mp.Remove(a);
	cout << "第 2 次删除的数据为：" << a << "，堆为：";
	mp.Display();


	cout << endl << endl;

	int data[] = { 100, 86, 48, 73, 35, 39, 42, 57, 66, 21 };
	cout << "调整前次序：";
	for (i = 0; i < 10; i++) {
		cout << data[i] << "  ";
	}
	cout << endl;

	MinHeap<int> mp1(data, 10);
	cout << "放入堆后次序：";
	mp1.Display();
	cout << endl;

	system("pause");
	return 0;
}