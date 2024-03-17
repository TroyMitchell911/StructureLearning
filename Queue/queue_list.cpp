/**
  ******************************************************************************
  * @file           : queue_list.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/16
  ******************************************************************************
  */
#include <cstdlib>
#include <iostream>
#include "queue_list.h"


struct queue_list *queue_list_new(void) {
   struct queue_list *temp = (struct queue_list*)malloc(sizeof(struct queue_list));
   temp->write = temp->read = NULL;
   return temp;
}
void enqueue_list(struct queue_list *q, int data) {
    struct list_node *temp = (struct list_node*)malloc(sizeof(struct list_node));
    if(temp) {
        temp->data = data;
        temp->next = NULL;
        if(q->read == NULL && q->write == NULL) {
            q->read = q->write = temp;
            return;
        }
        q->write->next = temp;
        q->write = temp;
    }
}
void dequeue_list(struct queue_list *q) {
    struct list_node *temp = q->read;
    int i;
    if(q->read == NULL) {
       std::cout << "读取失败，队列为空\n";
       return;
    } else if(q->read == q->write) {
       q->read = q->write = NULL;
       return;
    } else {
        q->read = q->read->next;
    }
    free(temp);
}

void queue_list_print(struct queue_list *q) {
    for(struct list_node *temp = q->read; temp != q->write->next; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}

void queue_list_del(struct queue_list *q) {
    if(q) {
        free(q);
    }
}

