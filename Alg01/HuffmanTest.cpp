/**
* Huffman树测试程序
*
* @author skywang
* @date 2014/03/25
*/

#include <iostream>
#include "HuffmanTree.h"


int main()
{
	int a[] = { 5,6,8,7,15 };
	int i, ilen = sizeof(a) / (sizeof(a[0]));
	Huffman<int>* tree = new Huffman<int>();

	std::cout << "== 添加数组: ";
	for (i = 0; i<ilen; i++)
		std::cout << a[i] << " ";

	tree->create(a, ilen);

	std::cout << "\n== 前序遍历: ";
	tree->preOrder();

	std::cout << "\n== 中序遍历: ";
	tree->inOrder();

	std::cout << "\n== 后序遍历: ";
	tree->postOrder();
	std::cout << std::endl;

	std::cout << "== 树的详细信息: " << std::endl;
	tree->print();

	// 销毁二叉树
	tree->destroy();

	system("pause");

	return 0;
}