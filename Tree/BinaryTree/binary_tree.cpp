/**
  ******************************************************************************
  * @file           : binary_tree.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/19
  ******************************************************************************
  */

#include <ntdef.h>
#include "binary_tree.h"

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