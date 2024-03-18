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

stack_array *stack_array_new(void) {
    auto *s = new stack_array;
    s->top = -1;
    return s;
}
void stack_array_push(stack_array *s, int data) {
    s->buf[++s->top] = data;
}
int stack_array_pop(stack_array *s) {
    return s->buf[s->top--];
}
int stack_array_top(stack_array *s) {
    return s->buf[s->top];
}
void stack_array_del(stack_array *s) {
    delete s;
}
void stack_array_print(stack_array *s) {
    for(int i = s->top; i >= 0; i--) {
        std::cout << s->buf[i] << " ";
    }
    std::cout << std::endl;
}
