#pragma once
/**
* �����(��С��)
*
* @author skywang
* @date 2014/03/07
*
* @modify fallon
* @data 2019-04-14
*/
#include <iostream>
#include <iomanip>

template <class T>
class MinHeap {
private:
	T *mHeap;        // ����
	int mCapacity;    // �ܵ�����
	int mSize;        // ʵ������

private:
	// ��С�ѵ����µ����㷨
	void filterdown(int start, int end);
	// ��С�ѵ����ϵ����㷨(��start��ʼ����ֱ��0��������)
	void filterup(int start);
public:
	MinHeap();
	MinHeap(int capacity);
	~MinHeap();

	// ����data�ڶ�����е�����
	int getIndex(T data);
	// ɾ����С���е�data
	int remove(T data);
	// ��data���뵽�������
	int insert(T data);
	//������
	void create(T a[], int size);
	// ��ӡ�����
	void print();
};

/*
* ���캯��
*/
template <class T>
MinHeap<T>::MinHeap()
{
	new (this)MinHeap(30);
}

template <class T>
MinHeap<T>::MinHeap(int capacity)
{
	mSize = 0;
	mCapacity = capacity;
	mHeap = new T[mCapacity];
}
/*
* ��������
*/
template <class T>
MinHeap<T>::~MinHeap()
{
	mSize = 0;
	mCapacity = 0;
	delete[] mHeap;
}

/*
* ����data�ڶ�����е�����
*
* ����ֵ��
*     ���� -- ����data�������е�����
*     ������ -- -1
*/
template <class T>
int MinHeap<T>::getIndex(T data)
{
	for (int i = 0; i<mSize; i++)
		if (data == mHeap[i])
			return i;

	return -1;
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
void MinHeap<T>::filterdown(int start, int end)
{
	int c = start;          // ��ǰ(current)�ڵ��λ��
	int l = 2 * c + 1;     // ��(left)���ӵ�λ��
	T tmp = mHeap[c];    // ��ǰ(current)�ڵ�Ĵ�С

	while (l <= end)
	{
		// "l"�����ӣ�"l+1"���Һ���
		if (l < end && mHeap[l] > mHeap[l + 1])
			l++;        // ������������ѡ���С�ߣ���mHeap[l+1]
		if (tmp <= mHeap[l])
			break;        //��������
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
* ɾ����С���е�data
*
* ����ֵ��
*      0���ɹ�
*     -1��ʧ��
*/
template <class T>
int MinHeap<T>::remove(T data)
{
	int index;
	// ���"��"�ѿգ��򷵻�-1
	if (mSize == 0)
		return -1;

	// ��ȡdata�������е�����
	index = getIndex(data);
	if (index == -1)
		return -1;

	mHeap[index] = mHeap[--mSize];        // �����Ԫ���
	filterdown(index, mSize - 1);    // ��index��λ�ÿ�ʼ�������µ���Ϊ��С��

	return 0;
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
void MinHeap<T>::filterup(int start)
{
	int c = start;            // ��ǰ�ڵ�(current)��λ��
	int p = (c - 1) / 2;        // ��(parent)����λ�� 
	T tmp = mHeap[c];        // ��ǰ�ڵ�(current)�Ĵ�С

	while (c > 0)
	{
		if (mHeap[p] <= tmp)
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
* ��data���뵽�������
*
* ����ֵ��
*     0����ʾ�ɹ�
*    -1����ʾʧ��
*/
template <class T>
int MinHeap<T>::insert(T data)
{
	// ���"��"�������򷵻�
	if (mSize == mCapacity)
		return -1;

	mHeap[mSize] = data;        // ��"����"���ڱ�β
	filterup(mSize);            // ���ϵ�����
	mSize++;                    // �ѵ�ʵ������+1

	return 0;
}

/*
* ��ӡ�����
*
* ����ֵ��
*     0����ʾ�ɹ�
*    -1����ʾʧ��
*/
template <class T>
void MinHeap<T>::print()
{
	for (int i = 0; i<mSize; i++)
		std::cout << mHeap[i] << " ";
}

template <class T>
void MinHeap<T>::create(T a[], int size) {

}
