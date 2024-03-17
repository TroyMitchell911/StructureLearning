/**
  ******************************************************************************
  * @file           : queue_array.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/16
  ******************************************************************************
  */
#include <cstdlib>
#include <iostream>
#include "queue_array.h"

static int queue_is_empty(struct queue_array *q) {
   if((q->read == q->write) && (q->read == -1)) {
      return 1;
   }
   return 0;
}

struct queue_array *queue_array_new(void) {
    struct queue_array *temp = (struct queue_array *)malloc(sizeof(struct queue_array));
    if(!temp) {
        return NULL;
    }
    temp->read = temp->write = -1;
    return temp;
}
void enqueue_array(struct queue_array *q, int data) {
   if(queue_is_empty(q)) {
       q->read = q->write = 0;
   }else if((q->write + 1) % 3 == q->read) {
       std::cout << "队列已满,无法写入\n";
       return;
   }else {
       q->write = (q->write + 1) % 3;
   }
   q->buf[q->write] = data;
}
int dequeue_array(struct queue_array *q) {
    if(queue_is_empty(q)){
        std::cout << "队列是空的，无法读取\n";
        return -1;
    } else if(q->read == q->write) {
        q->read = q->write = -1;
    } else {
        q->read = (q->read + 1) % 3;
    }
    return q->buf[q->read];
}
void queue_array_del(struct queue_array *q) {
   if(q) {
       free(q);
   }
}
void queue_array_print(struct queue_array *q) {
    for(int i : q->buf) {
        printf("%d ", i);
    }
    printf("\n");
}
