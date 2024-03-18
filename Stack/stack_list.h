/**
  ******************************************************************************
  * @file           : stack_list.h
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/18
  ******************************************************************************
  */

#ifndef STRUCTURE_STACK_LIST_H
#define STRUCTURE_STACK_LIST_H

#include "list.h"

struct stack_list {
    struct list_node *top;
};

stack_list *stack_list_new(void);
void stack_list_push(stack_list *s, int data);
int stack_list_pop(stack_list *s);
int stack_list_top(stack_list *s);
void stack_list_del(stack_list *s);
void stack_list_print(stack_list *s);

#endif //STRUCTURE_STACK_LIST_H
