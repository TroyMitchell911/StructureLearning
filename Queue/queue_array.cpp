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

/**
 * @brief 判断队列是否为空
 * @param q 队列指针
 * @return 1为空 0为非空
 */
static int queue_is_empty(struct queue_array *q) {
   if((q->read == q->write) && (q->read == -1)) {
      return 1;
   }
   return 0;
}
/**
 * @brief 新建一个队列
 * @return 队列指针
 */
struct queue_array *queue_array_new(void) {
    struct queue_array *temp = (struct queue_array *)malloc(sizeof(struct queue_array));
    if(!temp) {
        return NULL;
    }
    /* 将读位置和写未知都设置为-1 */
    temp->read = temp->write = -1;
    return temp;
}
/**
 * @brief 队列push操作
 * @param q 队列指针
 * @param data 要入队的数据
 */
void enqueue_array(struct queue_array *q, int data) {
   if(queue_is_empty(q)) {
       /* 如果队列为空 则将读写都设置为0 要开始写入了 */
       q->read = q->write = 0;
   }else if((q->write + 1) % 3 == q->read) {
       /* 由于是数组构成的队列，所以这里可以使用循环数组的概念 %3中的3是数组大小 */
       std::cout << "队列已满,无法写入\n";
       return;
   }else {
       /* 循环数组概念 */
       q->write = (q->write + 1) % 3;
   }
   /* 入队赋值 */
   q->buf[q->write] = data;
}
/**
 * @brief 队列pop操作
 * @param q 队列指针
 * @return 返回出队的值
 */
int dequeue_array(struct queue_array *q) {
    if(queue_is_empty(q)){
        std::cout << "队列是空的，无法读取\n";
        return -1;
    } else if(q->read == q->write) {
        /* 如果两个值相等，则设置队列为初始状态 */
        q->read = q->write = -1;
    } else {
        /* 循环数组概念 */
        q->read = (q->read + 1) % 3;
    }
    return q->buf[q->read];
}
/**
 * @brief 删除队列
 * @param q 队列指针
 */
void queue_array_del(struct queue_array *q) {
   if(q) {
       free(q);
   }
}
/**
 * @brief 打印队列所有值
 * @param q 队列指针
 */
void queue_array_print(struct queue_array *q) {
    for(int i : q->buf) {
        printf("%d ", i);
    }
    printf("\n");
}
