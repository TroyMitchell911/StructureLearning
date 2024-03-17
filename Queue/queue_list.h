/**
  ******************************************************************************
  * @file           : queue_list.h
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/16
  ******************************************************************************
  */

#ifndef STRUCTURE_QUEUE_LIST_H
#define STRUCTURE_QUEUE_LIST_H

#include "list.h"

struct queue_list {
    struct list_node *read;
    struct list_node *write;
};


struct queue_list *queue_list_new(void);
void enqueue_list(struct queue_list *q, int data);
void dequeue_list(struct queue_list *q);
void queue_list_print(struct queue_list *q);
void queue_list_del(struct queue_list *q);

#endif //STRUCTURE_QUEUE_LIST_H
