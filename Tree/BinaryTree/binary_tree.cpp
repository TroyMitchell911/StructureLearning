/**
  ******************************************************************************
  * @file           : binary_tree.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/19
  ******************************************************************************
  */

#include <iostream>
#include <ntdef.h>
#include <queue>
#include "binary_tree.h"

using namespace std;

/**
 * @brief 求二叉树高度
 * @param root 二叉树根节点
 * @return 二叉树高度
 */
int bt_height(binary_tree *root) {
    if(root == nullptr) {
        /* 叶子节点的高度是0 但是由于下面的max语句还会+1 所以这里设置为-1 */
        return -1;
    }
    /*
     * 不断递归每个节点的左右子节点高度。触底回归。
     * */
    return max(bt_height(root->left), bt_height(root->right)) + 1;
}
/**
 * @brief 广度优先遍历二叉树，及按照层次顺序遍历
 * @param root 二叉树根节点指针
 */
void bt_level_order(binary_tree *root) {
    if(root == nullptr) {
        cout << "This is a empty tree";
        return;
    }
    queue<binary_tree*> q;
    /* 先将根节点入队 */
    q.push(root);
    /* 终止条件就是队列为空 在while中如果有左或者右 我们都会入队 */
    while(!q.empty()) {
        /* 获取队列头元素 */
        binary_tree *temp = q.front();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        q.pop();
    }
    cout << endl;
}
/**
 * @brief 二叉树前序遍历 深度优先中的一种
 * @param root 二叉树根节点指针
 */
void bt_preorder(binary_tree *root) {
    if(root == nullptr) {
        /* 触底回归 递归线终止条件 */
        return;
    }
    /* 前序遍历的顺序为 <root->data><left><right> */
    cout << root->data << " ";
    bt_preorder(root->left);
    bt_preorder(root->right);
}
/**
 * @brief 二叉树中序遍历 深度优先中的一种
 * @param root 二叉树根节点指针
 * @note 经过该算法遍历的二叉搜索树应该是升序的
 */
void bt_inorder(binary_tree *root) {
    if(root == nullptr) {
        /* 触底回归 递归线终止条件 */
        return;
    }
    /* 中序遍历的顺序为 <left><root->data><right> */
    bt_inorder(root->left);
    cout << root->data << " ";
    bt_inorder(root->right);
}
/**
 * @brief 二叉树后序遍历 深度优先中的一种
 * @param root 二叉树根节点指针
 */
void bt_postorder(binary_tree *root) {
    if(root == nullptr) {
        /* 触底回归 递归线终止条件 */
        return;
    }
    /* 后序遍历的顺序为 <left><right><root->data> */
    bt_postorder(root->left);
    bt_postorder(root->right);
    cout << root->data << " ";
}
/**
 * @brief 二叉树是否是二叉搜索树的工具函数
 * @param root 二叉树根节点
 * @param min 该二叉树节点最小值
 * @param max 该二叉树节点最大值
 * @return true是二叉搜索树 false不是二叉搜索树
 * @note 该函数将由bt_is_bst进行封装 是内部工具函数
 */
static bool _bt_is_bst_util(binary_tree *root, int min, int max) {
    if(root == nullptr) {
        return true;
    }
    /* 以下代码均根据二叉搜索树的定义编写 */
    if(
        /* 通过限定最大最小值来判断该节点的值是否符合二叉搜索树要求 */
        root->data > min &&
        root->data <= max &&
        /* 递归查找左节点是否满足要求，最大值限定为当前节点的值 */
        _bt_is_bst_util(root->left, min, root->data) &&
        /* 递归查找右节点是否满足要求，最小值限定为当前节点的值 */
        _bt_is_bst_util(root->right, root->data, max)) {
        return true;
    }
    return false;
}
/**
 * @brief 二叉树是否是二叉搜索树
 * @param root 二叉树根节点
 * @return true是二叉搜索树 false不是二叉搜索树
 */
bool bt_is_bst(binary_tree* root) {
    /* 最大最小值都限定为int的极限值 */
    return _bt_is_bst_util(root, INT_MIN, INT_MAX);
}
/**
 * @brief 二叉树是否是二叉搜索树的工具函数
 * @param root 二叉树根节点
 * @param buf 存储升序数组的缓冲区
 * @param count 该二叉树节点数量
 * @return 内部递归使用，调用者无需关心
 * @note 该函数将由bt_is_bst_find_number进行封装 是内部工具函数
 */
int* bt_is_bst_find_number_util(binary_tree *root, int *buf, int *count) {
    if(root == nullptr) {
        return buf;
    }
    buf = bt_is_bst_find_number_util(root->left, buf, count);
    *(buf ++) = root->data;
    *count = *count + 1;
    buf = bt_is_bst_find_number_util(root->right, buf, count);
    return buf;
}
/**
 * @brief 二叉树是否是二叉搜索树
 * @param root 二叉树根节点
 * @return true是二叉搜索树 false不是二叉搜索树
 * @note 该函数利用中序遍历结果为升序的特性
 */
bool bt_is_bst_find_number(binary_tree* root) {
    int buf[1024];
    int count = 0;
    /* 将二叉树中的数据升序存放到buf中，将二叉树中的数据个数存放到count种、中 */
    bt_is_bst_find_number_util(root, buf, &count);
    for(int i = 1; i < count; i++) {
        /* 数组是升序排列的，如果后面的小于前面的，说明不是二叉搜索树 */
        if(buf[i] < buf[i-1]) {
            return false;
        }
    }
    return true;
}


