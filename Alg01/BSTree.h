/*
 *c++ 实现二叉查找树
 *@data: 2019-04-06
 *@author: Fallon
 */
#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_

#include <iomanip>
#include <iostream>

//二叉查找树结点
namespace Tree{
    
template <class T>
class BSTNode{

    public:
        T key; //键值
        BSTNode *left;
        BSTNode *right;
        BSTNode *parent;
            
        BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r)
            :key(value), parent(p), left(l), right(r) {
                    
            }
};

template <class T>
class BSTree {
    public:
        //创建一颗树
        BSTree();
        ~BSTree();
        
        //遍历查找 前,中,后
        void preOrder();
        void inOrder();
        void postOrder();
        
        //查找二叉树中键值为K的结点 递归和非递归
        BSTNode<T>* search(T key);
        BSTNode<T>* iterativeSearch(T key);
        
        //查找最小,最大结点,返回键值
        T minimum();
        T maximum();
        
        //查找结点(x)的后继<前驱>结点,即,查找"二叉树中数据值大于<小于>该结点"的"最小<大>结点"
        BSTNode<T>* successor(BSTNode<T> *x);
        BSTNode<T>* predecessor(BSTNode<T> *x);
        
        //插入结点
        void insert(T key);
        
        //删除结点
        void remove(T key);
        
        //销毁二叉树
        void destroy();
        
        //打印二叉树
        void print();
    private:
        BSTNode<T> *m_root; //根结点
        //遍历二叉树
        void preOrder(BSTNode<T> *tree) const;
        void inOrder(BSTNode<T> *tree) const;
        void postOrder(BSTNode<T> *tree) const;
        
        //查找二叉树x 键值为key的结点
        BSTNode<T>* search(BSTNode<T> *x, T key) const; //递归
        BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const; //非递归
        
        //查找最小最大结点,返回tree为根结点的二叉树的最小结点
        BSTNode<T>* minimum(BSTNode<T> *tree);
        BSTNode<T>* maximum(BSTNode<T> *tree);
        
        //插入结点Z到二叉树tree中
        void insert(BSTNode<T>* &tree, BSTNode<T> *z);
        
        //删除二叉树tree中的结点z并返回被删除结点
        BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T> *z);
        
        //销毁二叉树
        void destroy(BSTNode<T>* &tree);
        
        //打印二叉树
        void print(BSTNode<T>* &tree, T key, int direction);
        
};

template <class T>
BSTree<T>::BSTree():m_root(NULL){
    
}

template <class T>
BSTree<T>::~BSTree(){
    destroy();
}
/*
 *遍历树
 */
template <class T>
void BSTree<T>::preOrder(BSTNode<T>* tree) const {
    if(tree != NULL) {
        std::cout << tree->key << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void BSTree<T>::preOrder() {
    preOrder(m_root);
}

template <class T>
void BSTree<T>::inOrder(BSTNode<T> *tree) const {
    if(tree != NULL) {
        inOrder(tree->left);
        std::cout << tree->key << " ";
        inOrder(tree->right);
    }
}
template <class T>
void BSTree<T>::inOrder() {
    inOrder(m_root);
}

template <class T>
void BSTree<T>::postOrder(BSTNode<T> *tree) const {
    if(tree != NULL) {
        postOrder(tree->left);
        postOrder(tree->right);
        std::cout << tree->key << " ";
    }
}
template <class T>
void BSTree<T>::postOrder() {
    postOrder(m_root);
}

/*
 *递归查找
 */
template <class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T> *x, T key) const{
    if(x == NULL || x->key == key)
        return x;
    if(key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}
template <class T>
BSTNode<T>* BSTree<T>::search(T key)
{
    search(m_root, key);
}

/*
 *非递归查找
 */
template <class T>
BSTNode<T>* BSTree<T>::iterativeSearch(BSTNode<T> *x, T key) const {
    while((x != NULL) && (x->key != key))
    {
        if(key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}
template <class T>
BSTNode<T>* BSTree<T>::iterativeSearch(T key)
{
    iterativeSearch(m_root, key);
}

/*
 *查找树中最大值
 */
template <class T>
BSTNode<T>* BSTree<T>::maximum(BSTNode<T>* tree) {
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}
template <class T>
T BSTree<T>::maximum() {
    BSTNode<T> *p = maximum(m_root);
    if(p != NULL)
        return p->key;
    return (T)NULL;
}
/*
 *查找树中最小值
 */
template <class T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

template <class T>
T BSTree<T>::minimum()
{
    BSTNode<T> *p = minimum(m_root);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

/* 
 * 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
 */
template <class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *x)
{
    // 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
    if (x->left != NULL)
        return maximum(x->left);

    // 如果x没有左孩子。则x有以下两种可能：
    // (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
    // (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
    BSTNode<T>* y = x->parent;
    while ((y!=NULL) && (x==y->left))
    {
        x = y;
        y = y->parent;
    }

    return y;
}
/* 
 * 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
 */
template <class T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T> *x) {
    // 如果x存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"。
    if(x->right != NULL)
        return minimum(x->right);
    // 如果x没有右孩子。则x有以下两种可能：
    // (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
    // (02) x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
    BSTNode<T> *y = x->parent;
    while((y != NULL) && (x == y->right))
    {
        x = y;
        y = y->parent;
    }
    return y;
}

/*
 *插入结点
 *参数说明
 *      tree 二叉树的根结点
 *      z 插入的结点
 */
template <class T>
void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T> *z)
{
    BSTNode<T> *y = NULL;
    BSTNode<T> *x = tree;
    
    //查找z的插入位置
    while(x != NULL)
    {
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    
    z->parent = y;
    if(y == NULL)
        tree = z;
    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;
}
/*
 *将结点(key为键值)插入到二叉树中
 *参数说明
 *  tree 二叉树根结点
 *  key 插入结点键值
 */
template <class T>
void BSTree<T>::insert(T key)
{
    BSTNode<T> *z = NULL;
    //如果结点创建失败, 则返回
    if((z = new BSTNode<T>(key, NULL, NULL, NULL)) == NULL)
        return ;
    insert(m_root, z);
}


/*
 *
 *删除结点,并返回被删除结点
 *1）需要删除的节点下并没有其他子节点。
 *2）需要删除的节点下有一个子节点（左或右）。
 *3）需要删除的节点下有两个子节点（既左右节点都存在）。
 *参数说明
 *  tree 二叉树的根结点
 *  z 删除的结点
 */
template <class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T>* &tree, BSTNode<T> *z) {
    BSTNode<T> *x = NULL;
    BSTNode<T> *y = NULL;
    
    if((z->left == NULL)|| (z->right == NULL))
        y = z;
    else
        y = successor(z);
        
    if(y -> left != NULL)
        x = y->left;
    else
        x = y->right;
        
    if(x != NULL)
        x->parent = y->parent;
        
    if(y->parent == NULL)
        tree = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    
    if(y != z)
        z->key = y->key;
    
    return y;    
}
/* 
 * 删除结点(z)，并返回被删除的结点
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     z 删除的结点
 */
template <class T>
void BSTree<T>::remove(T key)
{
    BSTNode<T> *z, *node; 

    if ((z = search(m_root, key)) != NULL)
        if ( (node = remove(m_root, z)) != NULL)
            delete node;
}

/*
 * 打印"二叉查找树"
 *
 * key        -- 节点的键值 
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
template <class T>
void BSTree<T>::print(BSTNode<T>* &tree, T key, int direction) {
    if(tree != NULL)
    {
        if(direction == 0)
            std::cout << tree->key << "is root" <<std::endl;
        else 
            std::cout << tree->key << "  is  " << key << "'s ";
            std::cout << (direction==1?"right child" : "left child") << std::endl;
            
        print(tree->left, tree->key,-1);
        print(tree->right, tree->key, 1);
        
    }
    
}

template <class T>
void BSTree<T>::print()
{
    if (m_root != NULL)
        print(m_root, m_root->key, 0);
}

/*
 *销毁二叉树
 */
template <class T>
void BSTree<T>::destroy(BSTNode<T>* &tree)
{
    if(tree == NULL)
        return ;
    if(tree->left != NULL)
        return destroy(tree->left);
    if(tree->right != NULL)
        return destroy(tree->right);
    
    delete tree;
    tree = NULL;
}

template <class T>
void BSTree<T>:: destroy()
{
    destroy(m_root);
}

}//namespace Tree

#endif
/*__BSTree_H__*/
