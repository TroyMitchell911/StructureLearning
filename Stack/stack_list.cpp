/**
  ******************************************************************************
  * @file           : stack_list.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/18
  ******************************************************************************
  */
#include <iostream>
#include "stack_list.h"

/**
 * @brief 创建栈
 * @return 栈指针
 */
stack_list *stack_list_new(void) {
    auto *s = new stack_list;
    s->top = nullptr;
    return s;
}
/**
 * @brief 入栈
 * @param s 栈指针
 * @param data 要入栈的数据
 */
void stack_list_push(stack_list *s, int data){
    auto *l = new list_node;
    /* 将入栈的数据赋值给新建的链表节点 */
    l->data = data;
    /* 由于栈是反过来的，所以每次入栈将新建的链表作为栈的top */
    l->next = s->top;
    s->top = l;
}
/**
 * @brief 出栈
 * @param s 栈指针
 * @return 出栈的数据
 */
int stack_list_pop(stack_list *s) {
    auto *l = s->top;
    s->top = s->top->next;
    int ret = l->data;
    delete l;
    return ret;
}
/**
 * @brief 获取栈顶数据，不对栈结构破坏
 * @param s 栈指针
 * @return 栈顶数据
 */
int stack_list_top(stack_list *s) {
    return s->top->data;
}
/**
 * @brief 删除栈
 * @param s 栈指针
 */
void stack_list_del(stack_list *s) {
    delete s;
}
/**
 * @brief 打印栈中全部数据
 * @param s 栈指针
 */
void stack_list_print(stack_list *s) {
    /* 简单的遍历链表 */
    for(list_node *i = s->top; i != nullptr; i = i->next) {
        std::cout << i->data << " ";
    }
    std::cout << std::endl;
}
