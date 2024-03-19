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
binary_search_tree* bst_insert(binary_search_tree *root, int data);
int bst_min(binary_search_tree *root);
int bst_max(binary_search_tree *root);



#endif //STRUCTURE_BINARY_SEARCH_TREE_H
