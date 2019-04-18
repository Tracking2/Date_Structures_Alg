#pragma once
#include <iostream>
#include <iomanip>

template<class T>
class HuffmanNode {
public:
	T key; //Ȩֵ
	HuffmanNode *left;
	HuffmanNode *right;
	HuffmanNode *parent;

	HuffmanNode() {}
	HuffmanNode(T k, HuffmanNode *l, HuffmanNode *r, HuffmanNode *p)
		:key(k), left(l), right(r), parent(p) {}
};


template <class T>
class MinHeap {
private:
	HuffmanNode<T> *mHeap;	// ��С�ѵ�����
	int mCapacity;			// �ܵ�����
	int mSize;				// ��ǰ��Ч���ݵ�����
private:
	// �ϵ��㷨
	void filterUp(int start);
	// �µ��㷨
	void filterDown(int start, int end);
	// ��������HuffmanNode�ڵ��ȫ�����ݣ�i��j�ǽڵ�������
	void swapNode(int i, int j);
public:
	MinHeap();
	~MinHeap();

	// ��node��ȫ�����ݿ�����"��С�ѵ�ָ���ڵ�"
	int copyOf(HuffmanNode<T> *node);
	// ��ȡ��С�ڵ�
	HuffmanNode<T>* dumpFromMinimum();
	// ������С��
	void create(T a[], int size);
	// ������С��
	void destroy();
};


template <class T>
MinHeap<T>::MinHeap()
{
}

template <class T>
MinHeap<T>::~MinHeap()
{
	destroy();
}

/*
* ��С�ѵ����µ����㷨
*
* ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
*
* ����˵����
*     start -- ���µ��ڵ����ʼλ��(һ��Ϊ0����ʾ�ӵ�1����ʼ)
*     end   -- ������Χ(һ��Ϊ���������һ��Ԫ�ص�����)
*/
template <class T>
void MinHeap<T>::filterDown(int start, int end)
{
	int c = start; 	 	// ��ǰ(current)�ڵ��λ��
	int l = 2 * c + 1; 	// ��(left)���ӵ�λ��
	HuffmanNode<T> tmp = mHeap[c];	// ��ǰ(current)�ڵ�

	while (l <= end)
	{
		// "l"�����ӣ�"l+1"���Һ���
		if (l < end && mHeap[l].key > mHeap[l + 1].key)
			l++;		// ������������ѡ���С�ߣ���mHeap[l+1]
		if (tmp.key <= mHeap[l].key)
			break;		//��������
		else
		{
			mHeap[c] = mHeap[l];
			c = l;
			l = 2 * l + 1;
		}
	}
	mHeap[c] = tmp;
}

/*
* ��С�ѵ����ϵ����㷨(��start��ʼ����ֱ��0��������)
*
* ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
*
* ����˵����
*     start -- ���ϵ��ڵ����ʼλ��(һ��Ϊ���������һ��Ԫ�ص�����)
*/
template <class T>
void MinHeap<T>::filterUp(int start)
{
	int c = start;			// ��ǰ�ڵ�(current)��λ��
	int p = (c - 1) / 2;		// ��(parent)����λ�� 
	HuffmanNode<T> tmp = mHeap[c];		// ��ǰ�ڵ�(current)

	while (c > 0)
	{
		if (mHeap[p].key <= tmp.key)
			break;
		else
		{
			mHeap[c] = mHeap[p];
			c = p;
			p = (p - 1) / 2;
		}
	}
	mHeap[c] = tmp;
}

/*
* ��node��ȫ�����ݿ�����"��С�ѵ�ָ���ڵ�"
*
* ����ֵ��
*     0����ʾ�ɹ�
*    -1����ʾʧ��
*/
template <class T>
int MinHeap<T>::copyOf(HuffmanNode<T> *node)
{
	// ���"��"�������򷵻�
	if (mSize == mCapacity)
		return -1;

	mHeap[mSize] = *node;   // ��"node������"ȫ�����Ƶ�"����ĩβ"
	filterUp(mSize);		// ���ϵ�����
	mSize++;				// �ѵ�ʵ������+1

	return 0;
}

/*
* ��������HuffmanNode�ڵ��ȫ������
*/
template <class T>
void MinHeap<T>::swapNode(int i, int j)
{
	HuffmanNode<T> tmp = mHeap[i];
	mHeap[i] = mHeap[j];
	mHeap[j] = tmp;
}

/*
* �½�һ���ڵ㣬������С������С�ڵ�����ݸ��Ƹ��ýڵ㡣
* Ȼ�����С�ڵ�֮����������¹������С�ѡ�
*
* ����ֵ��
*     ʧ�ܷ���NULL��
*/
template <class T>
HuffmanNode<T>* MinHeap<T>::dumpFromMinimum()
{
	// ���"��"�ѿգ��򷵻�
	if (mSize == 0)
		return NULL;

	HuffmanNode<T> *node;
	if ((node = new HuffmanNode<T>()) == NULL)
		return NULL;

	// ��"��С�ڵ��ȫ������"���Ƹ�node
	*node = mHeap[0];

	swapNode(0, mSize - 1);				// ����"��С�ڵ�"��"���һ���ڵ�"
	filterDown(0, mSize - 2);	// ��mHeap[0...mSize-2]�����һ����С��
	mSize--;

	return node;
}

/*
* ������С��
*
* ����˵����
*     a -- �������ڵ�����
*     size -- �����С
*/
template <class T>
void MinHeap<T>::create(T a[], int size)
{
	int i;

	// ������С������Ӧ������
	mSize = size;
	mCapacity = size;
	mHeap = new HuffmanNode<T>[size];

	// ��ʼ������
	for (i = 0; i<size; i++)
	{
		mHeap[i].key = a[i];
		mHeap[i].parent = mHeap[i].left = mHeap[i].right = NULL;
	}

	// ��(size/2-1) --> 0��α���������֮�󣬵õ�������ʵ������һ����С�ѡ�
	for (i = size / 2 - 1; i >= 0; i--)
		filterDown(i, size - 1);
}

// ������С��
template <class T>
void MinHeap<T>::destroy()
{
	mSize = 0;
	mCapacity = 0;
	delete[] mHeap;
	mHeap = NULL;
}




template <class T>
class Huffman {
private:
	HuffmanNode < T> *mRoot;

public:
	Huffman();
	~Huffman();

	// ǰ�����"Huffman��"
	void preOrder();
	// �������"Huffman��"
	void inOrder();
	// �������"Huffman��"
	void postOrder();

	// ����Huffman��
	void create(T a[], int size);
	// ����Huffman��
	void destroy();

	// ��ӡHuffman��
	void print();
private:
	// ǰ�����"Huffman��"
	void preOrder(HuffmanNode<T>* tree) const;
	// �������"Huffman��"
	void inOrder(HuffmanNode<T>* tree) const;
	// �������"Huffman��"
	void postOrder(HuffmanNode<T>* tree) const;

	// ����Huffman��
	void destroy(HuffmanNode<T>* &tree);

	// ��ӡHuffman��
	void print(HuffmanNode<T>* tree, T key, int direction);



};

/*
* ���캯��
*/
template <class T>
Huffman<T>::Huffman() :mRoot(NULL)
{
}

/*
* ��������
*/
template <class T>
Huffman<T>::~Huffman()
{
	destroy();
}

/*
* ǰ�����"Huffman��"
*/
template <class T>
void Huffman<T>::preOrder(HuffmanNode<T>* tree) const
{
	if (tree != NULL)
	{
		std::cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template <class T>
void Huffman<T>::preOrder()
{
	preOrder(mRoot);
}

/*
* �������"Huffman��"
*/
template <class T>
void Huffman<T>::inOrder(HuffmanNode<T>* tree) const
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		std::cout << tree->key << " ";
		inOrder(tree->right);
	}
}

template <class T>
void Huffman<T>::inOrder()
{
	inOrder(mRoot);
}

/*
* �������"Huffman��"
*/
template <class T>
void Huffman<T>::postOrder(HuffmanNode<T>* tree) const
{
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		std::cout << tree->key << " ";
	}
}

template <class T>
void Huffman<T>::postOrder()
{
	postOrder(mRoot);
}


/*
* ����Huffman��
*/
template <class T>
void Huffman<T>::destroy(HuffmanNode<T>* &tree)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->right);

	delete tree;
	tree = NULL;
}

template <class T>
void Huffman<T>::destroy()
{
	destroy(mRoot);
}

/*
* ��ӡ"Huffman��"
*
* key        -- �ڵ�ļ�ֵ
* direction  --  0����ʾ�ýڵ��Ǹ��ڵ�;
*               -1����ʾ�ýڵ������ĸ���������;
*                1����ʾ�ýڵ������ĸ������Һ��ӡ�
*/
template <class T>
void Huffman<T>::print(HuffmanNode<T>* tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)	// tree�Ǹ��ڵ�
			std::cout << std::setw(2) << tree->key << " is root" << std::endl;
		else				// tree�Ƿ�֧�ڵ�
			std::cout << std::setw(2) << tree->key << " is " << std::setw(2) << key << "'s " << std::setw(12) << (direction == 1 ? "right child" : "left child") << std::endl;

		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template <class T>
void Huffman<T>::print()
{
	if (mRoot != NULL)
		print(mRoot, mRoot->key, 0);
}



/*
* ����Huffman��
*
* ����˵����
*     a Ȩֵ����
*     size �����С
*
* ����ֵ��
*     Huffman���ĸ��ڵ�
*/

template <class T>
void Huffman<T>::create(T a[], int size)
{
	int i;
	HuffmanNode<T> *left, *right, *parent = NULL;
	MinHeap<T> *heap = new MinHeap<T>();

	// ��������a��Ӧ����С��
	heap->create(a, size);

	for (i = 0; i<size - 1; i++)
	{
		left = heap->dumpFromMinimum();  // ��С�ڵ�������
		right = heap->dumpFromMinimum(); // ��β����Һ���

										 // �½�parent�ڵ㣬���Һ��ӷֱ���left/right��
										 // parent�Ĵ�С�����Һ���֮��
		parent = new HuffmanNode<T>(left->key + right->key, left, right, NULL);
		left->parent = parent;
		right->parent = parent;


		// ��parent�ڵ����ݿ�����"��С��"��
		if (heap->copyOf(parent) != 0)
		{
			std::cout << "����ʧ��!" << std::endl << "��������" <<std::endl;
			destroy(parent);
			parent = NULL;
			break;
		}
	}

	mRoot = parent;

	// ������С��
	heap->destroy();
	delete heap;
}