/**
  ******************************************************************************
  * @file           : list.h
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/16
  ******************************************************************************
  */

#ifndef STRUCTURE_LIST_H
#define STRUCTURE_LIST_H

struct list_node {
    int data;
    struct list_node *next;
};

struct list_node *list_insert(struct list_node *head, int data);
int list_is_empty(struct list_node *head);
void list_print(struct list_node* head);



#endif //STRUCTURE_LIST_H
