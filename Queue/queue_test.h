/**
  ******************************************************************************
  * @file           : queue_test.h
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/17
  ******************************************************************************
  */

#ifndef STRUCTURE_QUEUE_TEST_H
#define STRUCTURE_QUEUE_TEST_H

#include "queue_array.h"
#include "queue_list.h"

static inline void queue_test(void) {
    struct queue_array *q_array = queue_array_new();
    if(q_array) {
        enqueue_array(q_array, 3);
        enqueue_array(q_array, 5);
        enqueue_array(q_array, 7);
        enqueue_array(q_array, 7);
        dequeue_array(q_array);
        enqueue_array(q_array, 8);
        queue_array_print(q_array);
        queue_array_del(q_array);
    }
    struct queue_list *q_list = queue_list_new();
    if(q_list) {
        enqueue_list(q_list, 3);
        enqueue_list(q_list, 5);
        enqueue_list(q_list, 7);
        enqueue_list(q_list, 7);
        dequeue_list(q_list);
        enqueue_list(q_list, 8);
        queue_list_print(q_list);
        queue_list_del(q_list);
    }
}

#endif //STRUCTURE_QUEUE_TEST_H
