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

/**
 * @brief 创建一个队列
 * @return 队列指针
 */
struct queue_list *queue_list_new(void) {
   struct queue_list *temp = (struct queue_list*)malloc(sizeof(struct queue_list));
   temp->write = temp->read = NULL;
   return temp;
}
/**
 * @brief 队列push操作
 * @param q 队列指针
 * @param data 要入队的数据
 */
void enqueue_list(struct queue_list *q, int data) {
    /* 申请一个链表节点 */
    struct list_node *temp = (struct list_node*)malloc(sizeof(struct list_node));
    if(temp) {
        temp->data = data;
        temp->next = NULL;
        /* 判断队列是否为空 */
        if(q->read == NULL && q->write == NULL) {
            q->read = q->write = temp;
            return;
        }
        /* 链表连接，即入队操作 */
        q->write->next = temp;
        q->write = temp;
    }
}
/**
 * @brief 队列pop操作
 * @param q 队列指针
 */
void dequeue_list(struct queue_list *q) {
    struct list_node *temp = q->read;
    if(q->read == NULL) {
       std::cout << "读取失败，队列为空\n";
       return;
    } else if(q->read == q->write) {
        /* 如果读到头了，将队列设置为初始状态 */
       q->read = q->write = NULL;
       return;
    } else {
        q->read = q->read->next;
    }
    free(temp);
}
/**
 * @brief 打印队列中所有值
 * @param q 队列指针
 */
void queue_list_print(struct queue_list *q) {
    for(struct list_node *temp = q->read; temp != q->write->next; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}
/**
 * @brief 删除队列
 * @param q 队列指针
 */
void queue_list_del(struct queue_list *q) {
    if(q) {
        free(q);
    }
}

