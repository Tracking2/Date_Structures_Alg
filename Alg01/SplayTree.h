
#ifndef _SPLAY_TREE_HPP_
#define _SPLAY_TREE_HPP_

#include <iostream>

namespace SPLAY
{
    
/*
 *    SplayTreeNode是伸展树节点对应的类。它包括的几个组成元素:
 *    (01) key -- 是关键字，是用来对伸展树的节点进行排序的。
 *    (02) left -- 是左孩子。
 *    (03) right -- 是右孩子。
 */
template <class T>
class SplayTreeNode{
    public:
        T key;                // 关键字(键值)
        SplayTreeNode *left;    // 左孩子
        SplayTreeNode *right;    // 右孩子

        SplayTreeNode():left(NULL),right(NULL) {}

        SplayTreeNode(T value, SplayTreeNode *l, SplayTreeNode *r):
            key(value), left(l),right(r) {}
};

template <class T>
class SplayTree{
    private:
        SplayTreeNode<T> *mRoot;
        
    public:
        
        SplayTree();
        ~SplayTree();
        
        //遍历树
        void preOrder();
        void inOrder();
        void postOrder();
        
        //查找 递归和非递归 返回查找的结点
        SplayTree
        
        
    
}



} //namespace SPLAY