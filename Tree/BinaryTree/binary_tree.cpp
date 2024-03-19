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