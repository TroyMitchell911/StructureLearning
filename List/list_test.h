/**
  ******************************************************************************
  * @file           : list_test.h
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/17
  ******************************************************************************
  */

#ifndef STRUCTURE_LIST_TEST_H
#define STRUCTURE_LIST_TEST_H

#include <stdio.h>
#include "list.h"

static inline void list_test(void) {
    struct list_node *head = NULL;
    head = list_insert(head, 1);
    head = list_insert(head, 2);
    head = list_insert(head, 3);
    list_print(head);
    head = list_reverse_iteration(head);
    list_print(head);
    head = list_reverse_recursion(head, NULL);
    list_print(head);

    for(;head != nullptr; head = head->next)
        free(head);
}

#endif //STRUCTURE_LIST_TEST_H
