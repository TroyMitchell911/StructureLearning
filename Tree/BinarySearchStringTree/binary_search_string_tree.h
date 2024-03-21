/**
  ******************************************************************************
  * @file           : binary_search_string_tree.h
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/21
  ******************************************************************************
  */

#ifndef STRUCTURE_BINARY_SEARCH_STRING_TREE_H
#define STRUCTURE_BINARY_SEARCH_STRING_TREE_H

struct bsst{
    char* str;
    void* user_data;
    struct bsst *left;
    struct bsst *right;
};

void bsst_insert(bsst **root, const char* str, void* user_data);
void bsst_delete(bsst **root, const char* str);
void bsst_inorder(bsst *root);

#endif //STRUCTURE_BINARY_SEARCH_STRING_TREE_H
