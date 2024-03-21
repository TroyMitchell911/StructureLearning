/**
  ******************************************************************************
  * @file           : stack_array.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/18
  ******************************************************************************
  */

#include <iostream>
#include "stack_array.h"
/**
 * @brief 创建一个栈
 * @return 返回栈指针
 */
stack_array *stack_array_new(void) {
    auto *s = new stack_array;
    s->top = -1;
    return s;
}
/**
 * @brief 压栈
 * @param s 栈指针
 * @param data 要入栈的数据
 */
void stack_array_push(stack_array *s, int data) {
    /* 由于top在new的时候设置为了-1 所以要先++ */
    s->buf[++s->top] = data;
}
/**
 * @brief 出栈
 * @param s 栈指针
 * @return 出栈的数据
 */
int stack_array_pop(stack_array *s) {
    /* top指的是当前数据所在的位置，所以后-- */
    return s->buf[s->top--];
}
/**
 * @brief 查看栈顶数据，不对栈结构进行操作
 * @param s 栈指针
 * @return 栈顶数据
 */
int stack_array_top(stack_array *s) {
    return s->buf[s->top];
}
/**
 * @brief 删除栈
 * @param s 栈指针
 */
void stack_array_del(stack_array *s) {
    delete s;
}
/**
 * @brief 打印栈中所有数据
 * @param s 栈指针
 */
void stack_array_print(stack_array *s) {
    for(int i = s->top; i >= 0; i--) {
        std::cout << s->buf[i] << " ";
    }
    std::cout << std::endl;
}
