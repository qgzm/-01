#include <iostream>
#include <fstream>
using namespace std;

template <class T> 
struct BinTreeNode {	// ����������ඨ��
	T data;	 								// ������
	BinTreeNode<T> *leftChild, *rightChild;	// ����Ů������Ů����

	BinTreeNode ( ): leftChild(NULL), rightChild(NULL){  }  // ���캯��
	BinTreeNode (T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL): data(x), leftChild(l), rightChild(r){ }
};

template <class T> 
class BinaryTree {		// �������ඨ��
private:
	BinTreeNode<T> *root;	// �������ĸ�ָ��
	T  RefValue;			// ��������ֹͣ��־
private:
	void CreateBinTree (ifstream& in, BinTreeNode<T>* &subTree);	// ���ļ����뽨��
	void destroy (BinTreeNode<T> *subTree);


public:
	BinaryTree ( ) : root (NULL) { }			// ���캯��
	BinaryTree (T value) : RefValue(value), root(NULL) {  }	// ���캯��
	//BinaryTree (BinaryTree<T>& s);				// ���ƹ��캯��

	void CreatePreOrder (ifstream& in){ CreateBinTree(in, root); }
	~BinaryTree ( ) { destroy(root); }			// ��������

public:
	bool IsEmpty ( );				// �ж������շ�
	BinTreeNode<T> *LeftChild (BinTreeNode<T> *t);// ��������Ů	
	BinTreeNode<T> *RightChild (BinTreeNode<T> *t);//��������Ů
	BinTreeNode<T> *getRoot( );		//ȡ��
	int Height ( );					// �����߶�
	int Size ( );					// ������
	void PreOrder ( );				//ǰ�����
	void InOrder ();				//�������
	void PostOrder ( );				//�������
private:
	int Height(BinTreeNode<T>*& subTree);			// �����߶�		
	int Size(BinTreeNode<T>*& subTree);			// ������		
	void PreOrder(BinTreeNode<T>*& subTree);		//ǰ�����		
	void InOrder(BinTreeNode<T>*& subTree);		//�������		
	void PostOrder(BinTreeNode<T>*& subTree);		//�������		


};


//****************************************************************************************

template<class T> 
void BinaryTree<T>::destroy (BinTreeNode<T> * subTree){
// ˽�к���: ɾ����ΪsubTree������
	if (subTree != NULL) {
		destroy (subTree->leftChild);	// ɾ��������
		destroy (subTree->rightChild);	// ɾ��������
		delete subTree;					// ɾ�������
	}
}

template<class T> 
void BinaryTree<T>::CreateBinTree (ifstream& in, BinTreeNode<T>* &subTree) {
// ˽�к���: �Եݹ鷽ʽ������������
	T item;
	if ( !in.eof ( ) ) {	// δ����, ���벢����
		in >> item;			// ���������ֵ
		if (item != RefValue) {
			subTree = new BinTreeNode<T>(item);	// ���������,���صĺ���
			if (subTree == NULL) {  cerr << "�洢�����!" << endl;  exit (1);}
			CreateBinTree (in, subTree->leftChild);	// �ݹ齨��������
			CreateBinTree (in, subTree->rightChild);// �ݹ齨��������
		}
		else subTree = NULL;						// ���ָ���������ָ��
     }
};
template<class T>
int BinaryTree<T>::Height (BinTreeNode<T>*& subTree)			// �����߶�		
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
BinTreeNode<T>* BinaryTree<T>::LeftChild(BinTreeNode<T>* t)// ��������Ů	
{
	return (t != NULL) ? t->leftChild : NULL;
}
template<class T>
BinTreeNode<T>* BinaryTree<T>::RightChild(BinTreeNode<T>* t)//��������Ů
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
	return Height (root);			// �����߶�		 
}

template<class T>
int BinaryTree<T>::Size( )
{
	return Size (root);      // ������	
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
	//����һ�����������־����λ@
	BinaryTree<char> T('@');

	//�жϴ�ʱ���Ƿ�Ϊ��
	if( T.IsEmpty() )
	{
		cout << "��ʱ������Ϊ��" << endl;
	}

	//��ȡ�ļ��е����ݣ���������֯�����Ľṹ
	ifstream ifs("tree.txt");
	if(!ifs.is_open( ))
	{
		cout<<"���Ҳ���������ṹ���ļ���";
		system("pause");
		return;
	}
	T.CreatePreOrder(ifs);
	ifs.close( );
	
	//�жϴ�ʱ���Ƿ�Ϊ��
	if( !T.IsEmpty() )
	{
		cout << "��ʱ��������Ϊ��" << endl;
	}
	//������ڵ������
	cout << T.getRoot() ->data << endl;

	//������ڵ����Һ��ӵ�����
	cout << T.getRoot() ->leftChild ->data << endl;
	cout << T.getRoot() ->rightChild ->data << endl;

	//������һЩ����
	cout << "ǰ�����:";
	T.PreOrder();
	cout << endl;

	cout << "�������:";
	T.InOrder();
	cout << endl;

	cout << "�������:";
	T.PostOrder( );
	cout << endl;

	cout << "�ڵ���:";
    cout << T.Size() << endl;

	cout << "���ĸ�:";
    cout << T.Height() << endl;

	system("pause");
}