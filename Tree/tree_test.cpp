/**
  ******************************************************************************
  * @file           : tree_test.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/19
  ******************************************************************************
  */

#include <iostream>
#include "tree_test.h"

using namespace std;

static void _bst_test(void) {
    binary_search_tree *root = nullptr;
    /*
     *              15
     *          10      20
     *        8    12       25
     * */
    root = bst_insert(root, 15);
    root = bst_insert(root, 10);
    root = bst_insert(root, 20);
    root = bst_insert(root, 25);
    root = bst_insert(root, 8);
    root = bst_insert(root, 12);
    if(bst_search(root, 10)) cout << "Found\n";
    else cout << "Not Found\n";
    cout << "Min:" << bst_min(root) << " Max:" << bst_max(root) << endl;

    cout << "Height:" << bt_height(root) << endl;
    bt_level_order(root);
    bt_preorder(root);
    cout  << endl;
    bt_inorder(root);
    cout << endl;
    bt_postorder(root);
    cout << endl;

    cout << (bt_is_bst(root) ? "yes" : "no") << endl;
    cout << (bt_is_bst_find_number(root) ? "yes" : "no") << endl;
    root->data = 3;
    cout << (bt_is_bst(root) ? "yes" : "no") << endl;
    cout << (bt_is_bst_find_number(root) ? "yes" : "no") << endl;
}

void tree_test(void) {
    _bst_test();
}
