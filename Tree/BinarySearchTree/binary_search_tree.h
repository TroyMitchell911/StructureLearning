/**
  ******************************************************************************
  * @file           : binary_search_tree.h
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/19
  ******************************************************************************
  */

#ifndef STRUCTURE_BINARY_SEARCH_TREE_H
#define STRUCTURE_BINARY_SEARCH_TREE_H

#include "binary_tree.h"


bool bst_search(binary_search_tree *root, int data) ;
binary_search_tree *bst_search_node(binary_search_tree *root, int data);
binary_search_tree* bst_insert(binary_search_tree *root, int data);
int bst_min(binary_search_tree *root);
int bst_max(binary_search_tree *root);
binary_search_tree* bst_min_node(binary_search_tree *root);
binary_search_tree* bst_max_node(binary_search_tree *root);
binary_search_tree* bst_delete(binary_search_tree *root, int data);
int bst_get_successors(binary_search_tree *root, int data);



#endif //STRUCTURE_BINARY_SEARCH_TREE_H
