#include <cstdlib>
#include <cstdio>
#include "list.h"
/**
  ******************************************************************************
  * @file           : list.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/16
  ******************************************************************************
  */
struct list_node *list_insert(struct list_node *head, int data) {
    struct list_node *temp = (struct list_node *)malloc(sizeof(struct list_node));
    if(!temp) {
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    if(!head) {
        return temp;
    }
    struct list_node *i;
    for(i = head; i->next != NULL; i = i->next);
    i->next = temp;
    return head;
}

int list_is_empty(struct list_node *head) {
    if(!head) {
        return 1;
    }
    return 0;
}

void list_print(struct list_node* head) {
    if(head == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    list_print(head->next);
}