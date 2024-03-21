/**
  ******************************************************************************
  * @file           : binary_search_string_tree.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/21
  ******************************************************************************
  */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "binary_search_string_tree.h"

/**
 * @brief 在二叉搜索树中查找拥有最小字符串的节点
 * @param root 二叉搜索树根节点
 * @return 二叉搜索树种最小字符串的节点
 */
struct bsst* bsst_min_node(struct bsst *root) {
    if(root == NULL) {
        return NULL;
    } else if(root->left == NULL) {
        /* 如果该节点已经是叶子节点，则可以直接返回值 */
        return root;
    } else {
        /* 递归一直到左子树为叶子节点 */
        return bsst_min_node(root->left);
    }
}
/**
 * @brief 二叉搜索字符串树插入函数
 * @param root 根节点指针的地址
 * @param str 要插入的字符串
 * @param user_data 要插入的用户数据
 */
void bsst_insert(bsst **root, const char* str, void* user_data) {
    if(*root == NULL) {
        struct bsst *temp = (struct bsst*)malloc(sizeof(struct bsst));
        if(!temp) {
            return;
        }
        temp->str = (char*)malloc(strlen(str) + 1);
        if(!temp->str) {
            free(temp);
            return;
        }
        strcpy(temp->str, str);
        temp->user_data = user_data;
        temp->left = temp->right = NULL;
        *root = temp;
    }
    else if(strcmp(str, (*root)->str) <= 0) {
        /* 如果要插入的字符串比当前节点的小就去左树 */
        bsst_insert(&((*root)->left), str, user_data);
    } else {
        bsst_insert(&((*root)->right), str, user_data);
    }
}
/**
 * @brief 二叉搜索字符串树删除节点且保持二叉搜索树特性
 * @param root 根节点的地址
 * @param str 要删除的字符串
 */
void bsst_delete(bsst **root, const char* str) {
    struct bsst *root_ptr = *root;
    struct bsst *temp;
    int str_cmp_result;
    if(root_ptr == NULL) {
        return;
    }
    str_cmp_result = strcmp(str, root_ptr->str);
    if(str_cmp_result < 0) {
        bsst_delete(&root_ptr->left, str);
    } else if(str_cmp_result > 0) {
        bsst_delete(&root_ptr->right, str);
    } else {
        free(root_ptr->str);
        root_ptr->str = NULL;
        if(root_ptr->left == NULL && root_ptr->right == NULL) {
            free(root_ptr);
            *root = NULL;
        } else if(root_ptr->left == NULL) {
            temp = root_ptr->right;
            free(root_ptr);
            *root = temp;
        } else if(root_ptr->right == NULL) {
            temp = root_ptr->left;
            free(root_ptr);
            *root = temp;
        } else {
            temp = bsst_min_node(root_ptr->right);
            root_ptr->user_data = temp->user_data;
            root_ptr->str = (char*)malloc(strlen(temp->str) + 1);
            strcpy(root_ptr->str, temp->str);
            bsst_delete(&root_ptr->right, temp->str);
        }
    }
}

/**
 * @brief 二叉搜索字符串树中序遍历 深度优先中的一种
 * @param root 二叉树根节点指针
 * @note 经过该算法遍历的二叉搜索树应该是升序的
 */
void bsst_inorder(bsst *root) {
    if(root == NULL) {
        /* 触底回归 递归线终止条件 */
        return;
    }
    /* 中序遍历的顺序为 <left><root->data><right> */
    bsst_inorder(root->left);
    printf("%s\n", root->str);
    bsst_inorder(root->right);
}