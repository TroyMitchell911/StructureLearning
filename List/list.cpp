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

/**
 * @brief 向链表插入一个值
 * @param head 链表头
 * @param data 欲插入的数据
 * @return 链表头的指针
 * @note 如果head为null那么该函数会自动生成连标头并且将链表头指针返回
 *       如果head不为null则默认将head的指针直接返回
 */
struct list_node *list_insert(struct list_node *head, int data) {
    struct list_node *temp = (struct list_node *)malloc(sizeof(struct list_node));
    if(!temp) {
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    if(!head) {
        /* 如果链表头为空，则将此temp作为链表头返回 */
        return temp;
    }
    /* 查找最后一个节点的地址 */
    struct list_node *i;
    for(i = head; i->next != NULL; i = i->next);
    /* 将新建的节点加入到链表当中 */
    i->next = temp;
    return head;
}

/**
 * @brief 判断链表是否为空
 * @param head 链表头
 * @return 0为非空 1为空
 */
int list_is_empty(struct list_node *head) {
    if(!head) {
        return 1;
    }
    return 0;
}
/**
 * @brief 打印链表中的所有元素
 * @param head 链表头
 */
void list_print(struct list_node *head) {
    if(head == NULL) {
        /* 递归终止条件 */
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    list_print(head->next);
}
/**
 * @brief 迭代的方式将链表反转
 * @param head 链表头
 * @return 反转后的链表头地址
 */
struct list_node* list_reverse_iteration(struct list_node *head) {
    struct list_node *prev = NULL, *cur = head, *next;
    /*
     * 每一次迭代的过程如下：
     * 保存当前节点指向的下一个节点到next中
     * 将当前节点指向的下一个节点更改为prev（第一次迭代prev默认为null）
     * 将当前节点的地址放入prev
     * 将当前节点更改为next
     * */
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    /* 最终prev指向的就是原顺序的最后一个节点 现顺序的第一个节点 也就是链表头 */
    return prev;
}
/**
 * @brief 递归的方式将链表反转
 * @param head 链表头
 * @param prev 上一个节点的地址，调用时写null即可，函数内部递归需要
 * @return 反转后的链表头地址
 */
struct list_node* list_reverse_recursion(struct list_node *head, struct list_node *prev) {
    /* 递归终止条件 */
    if(head == NULL) {
        /* 最终prev指向的就是原顺序的最后一个节点 现顺序的第一个节点 也就是链表头 */
        return prev;
    }
    /*
     * 每一次递归的过程如下：
     * 保存当前节点指向的下一个节点到temp中
     * 将当前节点指向的下一个节点更改为prev（第一次迭代prev默认为null）
     * 将当前节点的地址放入prev
     * 将当前节点更改为temp
     * */
    struct list_node *temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;
    return list_reverse_recursion(head, prev);
}