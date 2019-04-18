#pragma once
/*
 *����ѣ����ѣ�
 *data�� 2019-04-14
 *author fallon
*/

#include <iostream>
#include <iomanip>

template <class T>
class MaxHeap {
private:
	T *mHeap;
	int mCapacity;
	int mSize;

private:
	//���ѵ����µ�����
	void filterdown(int start, int end);
	//���ѵ����ϵ�����
	void filterup(int start);

public:
	MaxHeap();
	MaxHeap(int capacity);
	~MaxHeap();

	//����data�ڶ�����е�����
	int getIndex(T data);
	//ɾ�����е�data
	int remove(T data);
	//��������
	int insert(T data);
	//��ӡ
	void print();

};

template<class T>
MaxHeap<T>::MaxHeap(){
	new (this)MaxHeap(30);
}

template <class T>
MaxHeap<T>::MaxHeap(int capacity) {
	mSize = 0;
	mCapacity = capacity;
	mHeap = new T(mCapacity);  //�����ʾ
}

template <class T>
MaxHeap<T>::~MaxHeap()
{
	mSize = 0;
	mCapacity = 0;
	delete[] mHeap;
}

/*
��ȡ������е�����
����ֵ��
	���ڣ�����data�������е�����
	�����ڣ�����-1
*/
template <class T>
int MaxHeap<T>::getIndex(T data) {
	for (int i = 0; i < mSize; i++)
		if (data == mHeap[i])
			return i;
	return -1;
}


/*
������µ�����
���±�0��ʼ�洢
����ʵ�ֵĶ��У���n���ڵ�����ӵ�����Ϊ 2n+1, �Һ��ӵ�����Ϊ2n+2
������
	start �� ���µ��ڵ�Ŀ�ʼλ�ã��±�0��ʾ��һ����ʼ
	end�� ������Χ��һ��Ϊ�������һ��Ԫ��
*/

template<class T>
void MaxHeap<T>::filterdown(int start, int end) {
	
	int c = start;
	int l = 2 * c + 1;
	T temp = mHeap[c];

	while (l <= end) {
		if (l < end && mHeap[l] < mHeap[l + 1])
			l++;
		if (temp >= mHeap[l])
			break;
		else {
			mHeap[c] == mHeap[l];
			c = l;
			l = 2 * l + 1;
		}

	}
	mHeap[c] = temp;

}

/*
ɾ������е�data
����ֵ;
	0 �ɹ�
	-1 ʧ��
*/
template<class T>
int MaxHeap<T>::remove(T data)
{
	int index;
	//�ж϶��Ƿ��
	if (mSize == 0)
		return -1;

	//��ȡҪɾ�����ݵ�����
	index = getIndex(data);
	if (index == -1)
		return -1;

	mHeap[index] = mHeap[--mSize];
	filterdown(index, mSize - 1);

	return 0;
}

/*
�������ϵ����㷨�� ����start ��ʼ����ֱ��0�� �����ѣ�
ע�� ����ʵ�ֵĶ��У���n���ڵ�����Ϊ2n+1�� �Һ���Ϊ2n+2,���ڵ�Ϊ ��i-1��/2
����˵����
	start�� ���ϵ��ڵ������
*/

template <class T>
void MaxHeap<T>::filterup(int start)
{
	int c = start; //��ǰ�ڵ�λ��
	int p = (c - 1) / 2; //���ڵ�λ��
	T temp = mHeap[c];

	while (c > 0) {
		if (temp > mHeap[p])
		{
			mHeap[c] = mHeap[p];
			c = p;
			p = (p - 1) / 2;

		}
		else
			break;
	}
	mHeap[c] = temp;

}

/*
��data���ݲ��뵽�������

����ֵ��
	0 ��ʾ�ɹ�
	-1 ��ʾʧ��
*/

template <class T>
int MaxHeap<T>::insert(T data)
{
	//�ж϶��Ƿ�����������
	if (mSize == mCapacity) {
		return -1;
	}

	mHeap[mSize] = data;
	filterup(mSize);
	mSize++;

	return 0;
}

/*
��ӡ�����
����ֵ��
	0 ��ʾ�ɹ�
	-1 ��ʾʧ��
*/
template<class T>
void MaxHeap<T>::print() {

	for (int i = 0; i < mSize; i++)
		std::cout << mHeap[i] << "\t";

}






