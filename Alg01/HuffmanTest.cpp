/**
* Huffman�����Գ���
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

	std::cout << "== �������: ";
	for (i = 0; i<ilen; i++)
		std::cout << a[i] << " ";

	tree->create(a, ilen);

	std::cout << "\n== ǰ�����: ";
	tree->preOrder();

	std::cout << "\n== �������: ";
	tree->inOrder();

	std::cout << "\n== �������: ";
	tree->postOrder();
	std::cout << std::endl;

	std::cout << "== ������ϸ��Ϣ: " << std::endl;
	tree->print();

	// ���ٶ�����
	tree->destroy();

	system("pause");

	return 0;
}