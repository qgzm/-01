#include <iostream>
#include <fstream>
using namespace std;

template <class T> 
struct BinTreeNode {	// 二叉树结点类定义
	T data;	 								// 数据域
	BinTreeNode<T> *leftChild, *rightChild;	// 左子女、右子女链域

	BinTreeNode ( ): leftChild(NULL), rightChild(NULL){  }  // 构造函数
	BinTreeNode (T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL): data(x), leftChild(l), rightChild(r){ }
};

template <class T> 
class BinaryTree {		// 二叉树类定义
private:
	BinTreeNode<T> *root;	// 二叉树的根指针
	T  RefValue;			// 数据输入停止标志
private:
	void CreateBinTree (ifstream& in, BinTreeNode<T>* &subTree);	// 从文件读入建树
	void destroy (BinTreeNode<T> *subTree);


public:
	BinaryTree ( ) : root (NULL) { }			// 构造函数
	BinaryTree (T value) : RefValue(value), root(NULL) {  }	// 构造函数
	//BinaryTree (BinaryTree<T>& s);				// 复制构造函数

	void CreatePreOrder (ifstream& in){ CreateBinTree(in, root); }
	~BinaryTree ( ) { destroy(root); }			// 析构函数

public:
	bool IsEmpty ( );				// 判二叉树空否
	BinTreeNode<T> *LeftChild (BinTreeNode<T> *t);// 返回左子女	
	BinTreeNode<T> *RightChild (BinTreeNode<T> *t);//返回右子女
	BinTreeNode<T> *getRoot( );		//取根
	int Height ( );					// 求树高度
	int Size ( );					// 求结点数
	void PreOrder ( );				//前序遍历
	void InOrder ();				//中序遍历
	void PostOrder ( );				//后序遍历
private:
	int Height(BinTreeNode<T>*& subTree);			// 求树高度		
	int Size(BinTreeNode<T>*& subTree);			// 求结点数		
	void PreOrder(BinTreeNode<T>*& subTree);		//前序遍历		
	void InOrder(BinTreeNode<T>*& subTree);		//中序遍历		
	void PostOrder(BinTreeNode<T>*& subTree);		//后序遍历		


};


//****************************************************************************************

template<class T> 
void BinaryTree<T>::destroy (BinTreeNode<T> * subTree){
// 私有函数: 删除根为subTree的子树
	if (subTree != NULL) {
		destroy (subTree->leftChild);	// 删除左子树
		destroy (subTree->rightChild);	// 删除右子树
		delete subTree;					// 删除根结点
	}
}

template<class T> 
void BinaryTree<T>::CreateBinTree (ifstream& in, BinTreeNode<T>* &subTree) {
// 私有函数: 以递归方式建立二叉树。
	T item;
	if ( !in.eof ( ) ) {	// 未读完, 读入并建树
		in >> item;			// 读入根结点的值
		if (item != RefValue) {
			subTree = new BinTreeNode<T>(item);	// 建立根结点,重载的函数
			if (subTree == NULL) {  cerr << "存储分配错!" << endl;  exit (1);}
			CreateBinTree (in, subTree->leftChild);	// 递归建立左子树
			CreateBinTree (in, subTree->rightChild);// 递归建立右子树
		}
		else subTree = NULL;						// 封闭指向空子树的指针
     }
};
template<class T>
int BinaryTree<T>::Height (BinTreeNode<T>*& subTree)			// 求树高度		
{
	if(subTree==NULL)return 0;
	else
	{
		int i = Height(subTree->leftChild), j = Height(subTree->rightChild);
		return (i < j) ? j + 1 : i + 1;
	}
}
	
template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>*& subTree)
{
	if(subTree==NULL) return 0;
	else return Size(subTree->leftChild)+Size(subTree->rightChild)+1;
}

template<class T>
void BinaryTree<T>::PreOrder (BinTreeNode<T>* &subTree)
{
	if(subTree==NULL)return;
	else
	{
		cout<<subTree->data<<" ";
		PreOrder(subTree->leftChild);
		PreOrder(subTree->rightChild);
	}
}

template<class T>
void BinaryTree<T>::InOrder (BinTreeNode<T>* &subTree)
{
	if(subTree==NULL)return;
	else
	{		
		InOrder(subTree->leftChild);
		cout<<subTree->data<<" ";
		InOrder(subTree->rightChild);
	}
}

template<class T>
void BinaryTree<T>::PostOrder (BinTreeNode<T>* &subTree)
{
	if(subTree==NULL)return;
	else
	{
		PostOrder(subTree->leftChild);
		PostOrder(subTree->rightChild);		
		cout<<subTree->data<<" ";
	}
}


template<class T>
BinTreeNode<T>* BinaryTree<T>::LeftChild(BinTreeNode<T>* t)// 返回左子女	
{
	return (t != NULL) ? t->leftChild : NULL;
}
template<class T>
BinTreeNode<T>* BinaryTree<T>::RightChild(BinTreeNode<T>* t)//返回右子女
{
	return (t != NULL) ? t->rightChild : NULL;
}
template<class T> 
bool BinaryTree<T>::IsEmpty ()
{
	return (root!=NULL)? false:true;
}

template<class T> 
BinTreeNode<T> * BinaryTree<T>::getRoot()
{
	return root;
}

template<class T> 
int BinaryTree<T>::Height()
{
	return Height (root);			// 求树高度		 
}

template<class T>
int BinaryTree<T>::Size( )
{
	return Size (root);      // 求结点数	
}

template<class T>
void BinaryTree<T>::PreOrder()
{
	PreOrder(root);
}

template<class T>
void BinaryTree<T>::InOrder()
{
	InOrder (root);
}

template<class T>
void BinaryTree<T>::PostOrder( )
{
	PostOrder (root);
}
//*************************************************************************************************************

void main(void)
{
	//创建一个空树，其标志符号位@
	BinaryTree<char> T('@');

	//判断此时树是否为空
	if( T.IsEmpty() )
	{
		cout << "此时二叉树为空" << endl;
	}

	//读取文件中的数据，将数据组织成树的结构
	ifstream ifs("tree.txt");
	if(!ifs.is_open( ))
	{
		cout<<"〉找不到存放树结构的文件！";
		system("pause");
		return;
	}
	T.CreatePreOrder(ifs);
	ifs.close( );
	
	//判断此时树是否不为空
	if( !T.IsEmpty() )
	{
		cout << "此时二叉树不为空" << endl;
	}
	//输出根节点的数据
	cout << T.getRoot() ->data << endl;

	//输出根节点左右孩子的数据
	cout << T.getRoot() ->leftChild ->data << endl;
	cout << T.getRoot() ->rightChild ->data << endl;

	//对树的一些操作
	cout << "前序遍历:";
	T.PreOrder();
	cout << endl;

	cout << "中序遍历:";
	T.InOrder();
	cout << endl;

	cout << "后序遍历:";
	T.PostOrder( );
	cout << endl;

	cout << "节点数:";
    cout << T.Size() << endl;

	cout << "树的高:";
    cout << T.Height() << endl;

	system("pause");
}