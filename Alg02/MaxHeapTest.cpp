#if 0
#include "MaxHeap.h"
#include "MinHeap.h"

int main()
{
	int a[] = { 10, 40, 30, 60, 90, 70, 20, 50, 80 };
	int i, len = (sizeof(a)) / (sizeof(a[0]));

	//MaxHeap<int> *tree = new MaxHeap<int>();
	MinHeap<int> *tree = new MinHeap<int>();

	std::cout << "create MaxHeap:\n";
	for (i = 0; i < len; i++) {
		std:: cout << a[i] << " ";
		tree->insert(a[i]);
	}

	std::cout << "\nMaxHeap: \n";
	tree->print();

	i = 85;
	tree->insert(i);
	std::cout << "\ninsert element:   " << i;
	std::cout << "\nMax Heap:";
	tree->print();

	i = 90;
	tree->remove(i);
	std::cout << "\nremove element:   " << std::setw(4) << i;
	std::cout << "\nMaxHeap:\n ";
	tree->print();

	std::cout << std::endl;
	system("pause");

	return 0;
	


}
#endif
