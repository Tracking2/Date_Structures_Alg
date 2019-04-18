#pragma once
/*
 *二叉堆（最大堆）
 *data： 2019-04-14
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
	//最大堆的向下调整法
	void filterdown(int start, int end);
	//最大堆的向上调整法
	void filterup(int start);

public:
	MaxHeap();
	MaxHeap(int capacity);
	~MaxHeap();

	//返回data在二叉堆中的索引
	int getIndex(T data);
	//删除堆中的data
	int remove(T data);
	//插入数据
	int insert(T data);
	//打印
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
	mHeap = new T(mCapacity);  //数组表示
}

template <class T>
MaxHeap<T>::~MaxHeap()
{
	mSize = 0;
	mCapacity = 0;
	delete[] mHeap;
}

/*
获取二叉堆中的索引
返回值：
	存在，返回data在数组中的索引
	不存在，返回-1
*/
template <class T>
int MaxHeap<T>::getIndex(T data) {
	for (int i = 0; i < mSize; i++)
		if (data == mHeap[i])
			return i;
	return -1;
}


/*
大堆向下调整法
从下表0开始存储
数组实现的堆中，第n个节点的左孩子的索引为 2n+1, 右孩子的索引为2n+2
参数：
	start ： 被下调节点的开始位置，下表，0表示第一个开始
	end： 截至范围，一般为数组最后一个元素
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
删除大堆中的data
返回值;
	0 成功
	-1 失败
*/
template<class T>
int MaxHeap<T>::remove(T data)
{
	int index;
	//判断堆是否空
	if (mSize == 0)
		return -1;

	//获取要删除数据的索引
	index = getIndex(data);
	if (index == -1)
		return -1;

	mHeap[index] = mHeap[--mSize];
	filterdown(index, mSize - 1);

	return 0;
}

/*
最大堆向上调整算法， （从start 开始向上直到0， 调整堆）
注： 数组实现的堆中，第n个节点左孩子为2n+1， 右孩子为2n+2,父节点为 （i-1）/2
参数说明：
	start： 被上调节点的索引
*/

template <class T>
void MaxHeap<T>::filterup(int start)
{
	int c = start; //当前节点位置
	int p = (c - 1) / 2; //父节点位置
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
将data数据插入到二叉堆中

返回值：
	0 表示成功
	-1 表示失败
*/

template <class T>
int MaxHeap<T>::insert(T data)
{
	//判断堆是否已满，返回
	if (mSize == mCapacity) {
		return -1;
	}

	mHeap[mSize] = data;
	filterup(mSize);
	mSize++;

	return 0;
}

/*
打印二叉堆
返回值：
	0 表示成功
	-1 表示失败
*/
template<class T>
void MaxHeap<T>::print() {

	for (int i = 0; i < mSize; i++)
		std::cout << mHeap[i] << "\t";

}






