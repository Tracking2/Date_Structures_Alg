/**
 * C++ 语言: 二叉查找树
 *
 * @author Fallon
 * @date 2019-04-06
 */

#include <iostream>
#include "BSTree.h"


static int arr[]= {1,5,4,3,2,6};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main(int argc, char* argv[])
{
    int i, ilen;
    Tree::BSTree<int>* tree=new Tree::BSTree<int>();

    std::cout << "== 依次添加: ";
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++) 
    {
        std::cout << arr[i] <<" ";
        tree->insert(arr[i]);
    }

    std::cout << "\n== 前序遍历: ";
    tree->preOrder();

    std::cout << "\n== 中序遍历: ";
    tree->inOrder();

    std::cout << "\n== 后序遍历: ";
    tree->postOrder();
    std::cout << std::endl;

    std::cout << "== 最小值: " << tree->minimum() << std::endl;
    std::cout << "== 最大值: " << tree->maximum() << std::endl;
    std::cout << "== 树的详细信息: " << std::endl;
    tree->print();

    std::cout << "\n== 删除根节点: " << arr[3];
    tree->remove(arr[3]);

    std::cout << "\n== 中序遍历: ";
    tree->inOrder();
    std::cout << std::endl;

    // 销毁二叉树
    tree->destroy();

    return 0;
}