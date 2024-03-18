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

stack_list *stack_list_new(void) {
    auto *s = new stack_list;
    s->top = nullptr;
    return s;
}
void stack_list_push(stack_list *s, int data){
    auto *l = new list_node;
    l->data = data;
    l->next = s->top;
    s->top = l;
}
int stack_list_pop(stack_list *s) {
    auto *l = s->top;
    s->top = s->top->next;
    int ret = l->data;
    delete l;
    return ret;
}
int stack_list_top(stack_list *s) {
    return s->top->data;
}
void stack_list_del(stack_list *s) {
    delete s;
}
void stack_list_print(stack_list *s) {
    for(list_node *i = s->top; i != nullptr; i = i->next) {
        std::cout << i->data << " ";
    }
    std::cout << std::endl;
}
