/**
  ******************************************************************************
  * @file           : binary_tree.h
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/19
  ******************************************************************************
  */

#ifndef STRUCTURE_BINARY_TREE_H
#define STRUCTURE_BINARY_TREE_H

struct binary_tree {
    int data;
    binary_tree* left;
    binary_tree* right;
};

typedef struct binary_tree binary_search_tree;

int bt_height(binary_search_tree *root);
void bt_level_order(binary_tree *root);
void bt_preorder(binary_tree* root);
void bt_inorder(binary_tree* root);
void bt_postorder(binary_tree* root);

#endif //STRUCTURE_BINARY_TREE_H
