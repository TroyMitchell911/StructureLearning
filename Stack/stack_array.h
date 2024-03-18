/**
  ******************************************************************************
  * @file           : stack_array.h
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/18
  ******************************************************************************
  */

#ifndef STRUCTURE_STACK_ARRAY_H
#define STRUCTURE_STACK_ARRAY_H

struct stack_array {
    int buf[1024];
    int top;
};

stack_array *stack_array_new(void);
void stack_array_push(stack_array *s, int data);
int stack_array_pop(stack_array *s);
int stack_array_top(stack_array *s);
void stack_array_del(stack_array *s);
void stack_array_print(stack_array *s);

#endif //STRUCTURE_STACK_ARRAY_H
