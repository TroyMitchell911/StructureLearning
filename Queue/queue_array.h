/**
  ******************************************************************************
  * @file           : queue_array.h
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/16
  ******************************************************************************
  */

#ifndef STRUCTURE_QUEUE_ARRAY_H
#define STRUCTURE_QUEUE_ARRAY_H

struct queue_array {
    int buf[3];
    int write;
    int read;
};

struct queue_array *queue_array_new(void);
void enqueue_array(struct queue_array *q, int data);
int dequeue_array(struct queue_array *q);
void queue_array_del(struct queue_array *q);
void queue_array_print(struct queue_array *q);

#endif //STRUCTURE_QUEUE_ARRAY_H
