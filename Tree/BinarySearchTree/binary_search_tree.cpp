/**
  ******************************************************************************
  * @file           : binary_search_tree.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/19
  ******************************************************************************
  */

#include <ntdef.h>
#include <climits>
#include "binary_search_tree.h"

/**
 * @brief 搜索二叉搜索树中是否存在数据data
 * @param root 二叉搜索树根节点
 * @param data 欲搜索的数据
 * @return 该数据是否存在
 */
bool bst_search(binary_search_tree *root, int data) {
    if(root == nullptr) {
        /* 如果节点为null说明该树为空或者通过递归已经触底，不管是那种情况data都不存在该树中 */
        return false;
    } else if(root->data > data) {
        /* 由于是二叉搜索树，所以如果当前数据大于要搜索的数据，就去左边搜索即可 */
        return bst_search(root->left, data);
    } else if(root->data < data) {
        /* 原理同上 */
        return bst_search(root->right, data);
    } else {
        return true;
    }
}

/**
 * @brief 搜索二叉搜索树中数据data的节点
 * @param root 二叉搜索树根节点
 * @param data 欲搜索的数据
 * @return 该数据的节点
 */
binary_search_tree *bst_search_node(binary_search_tree *root, int data) {
    if(root == nullptr) {
        /* 如果节点为null说明该树为空或者通过递归已经触底，不管是那种情况data都不存在该树中 */
        return nullptr;
    } else if(root->data > data) {
        /* 由于是二叉搜索树，所以如果当前数据大于要搜索的数据，就去左边搜索即可 */
        return bst_search_node(root->left, data);
    } else if(root->data < data) {
        /* 原理同上 */
        return bst_search_node(root->right, data);
    } else {
        return root;
    }
}

/**
 * @brief 向二叉搜索树中插入一个数据
 * @param root 二叉搜索树根节点
 * @param data 欲插入的数据
 * @return 二叉搜索树的新根节点
 * @note 如果root为null那么该函数会自动生成根节点并且将根节点指针返回
 *       如果root不为null则默认将root的指针直接返回
 */
binary_search_tree* bst_insert(binary_search_tree *root, int data) {
    if(root == nullptr) {
        /* 如果这是一个空树，则生成一个叶子节点 */
        auto *temp = new binary_search_tree;
        temp->left = temp->right = nullptr;
        temp->data = data;
        /* 将该叶子节点作为树的根返回 */
        return temp;
    }
    if(data <= root->data) {
        /*
         * 如果要插入的数据小于当前数据，那么就需要插入到左树中
         * 假设当前树只有一个根，根值为10，要插入为8，则会进入到根节点的左树插入
         * 左树此时为null，且我们递归填入的第一个参数就是左树，则会生成一个新叶子节点存放该数据
         * 并且返回该新节点指针，我们把这个指针赋值给根节点的左树指针
         * 后面的插入都是一样的
         * */
        root->left = bst_insert(root->left, data);
    } else {
        root->right = bst_insert(root->right, data);
    }
    /* 返回root地址，这点在note注释中有说明 */
    return root;
}
/**
 * @brief 在二叉搜索树中查找最小值
 * @param root 二叉搜索树根节点
 * @return 二叉搜索树种最小的值
 */
int bst_min(binary_search_tree *root) {
    if(root == nullptr) {
        return 0;
    } else if(root->left == nullptr) {
        /* 如果该节点已经是叶子节点，则可以直接返回值 */
        return root->data;
    } else {
        /* 递归一直到左子树为叶子节点 */
        return bst_min(root->left);
    }
}
/**
 * @brief 在二叉搜索树中查找最大值
 * @param root 二叉搜索树根节点
 * @return 二叉搜索树中最大的值
 */
int bst_max(binary_search_tree *root) {
    if(root == nullptr) {
        return 0;
    } else if(root->right == nullptr) {
        /* 如果该节点已经是叶子节点，则可以直接返回值 */
        return root->data;
    } else {
        /* 递归一直到右子树为叶子节点 */
        return bst_max(root->right);
    }
}

/**
 * @brief 在二叉搜索树中查找拥有最小值的节点
 * @param root 二叉搜索树根节点
 * @return 二叉搜索树种最小的值的节点
 */
binary_search_tree* bst_min_node(binary_search_tree *root) {
    if(root == nullptr) {
        return 0;
    } else if(root->left == nullptr) {
        /* 如果该节点已经是叶子节点，则可以直接返回值 */
        return root;
    } else {
        /* 递归一直到左子树为叶子节点 */
        return bst_min_node(root->left);
    }
}

/**
 * @brief 在二叉搜索树中查找拥有最大值的节点
 * @param root 二叉搜索树根节点
 * @return 二叉搜索树种最大的值的节点
 */
binary_search_tree* bst_max_node(binary_search_tree *root) {
    if(root == nullptr) {
        return 0;
    } else if(root->right == nullptr) {
        /* 如果该节点已经是叶子节点，则可以直接返回值 */
        return root;
    } else {
        /* 递归一直到右子树为叶子节点 */
        return bst_max_node(root->right);
    }
}
/**
 * @brief 删除二叉搜索树中的某个树，使二叉搜索树继续保持特性
 * @param root 二叉搜索树根节点
 * @param data 欲删除的数据
 * @return 返回修改后的节点指针
 */
binary_search_tree* bst_delete(binary_search_tree *root, int data) {
    binary_search_tree *temp;
    if(root == nullptr) {
        return root;
    }
    if(root->data < data) {
        root->right = bst_delete(root->right, data);
    } else if(root->data > data) {
        root->left = bst_delete(root->left, data);
    } else if(root->left == nullptr && root->right == nullptr) {
        /* 删除叶子节点 */
        delete root;
        root = nullptr;
    } else if(root->left == nullptr) {
        /* 删除只有一个子节点的节点 子节点是否成子树无需关心 */
        temp = root->right;
        delete root;
        root = temp;
    } else if(root->right == nullptr) {
        /* 删除只有一个子节点的节点 子节点是否成子树无需关心 */
        temp = root->left;
        delete root;
        root = temp;
    } else {
        /* 删除拥有两个子节点的节点 */
        temp = bst_min_node(root->right);
        root->data = temp->data;
        root->right = bst_delete(root->right, root->data);
    }
    return root;
}

int bst_get_successors(binary_search_tree *root, int data) {
    binary_search_tree *node = bst_search_node(root, data);
    if(node != nullptr) {
        if(node->right != nullptr) {
            return bst_min(node->right);
        } else {
            binary_search_tree *temp = root;
            binary_search_tree *ancestor = nullptr;
            while(temp != nullptr) {
                if(data < temp->data) {
                    ancestor = temp;
                    temp = temp->left;
                } else if(data > temp->data) {
                    temp = temp->right;
                } else {
                    return ancestor->data;
                }
            }
            return INT_MIN;
        }
    } else {
        return INT_MIN;
    }
}

