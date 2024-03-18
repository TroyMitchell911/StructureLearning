/**
  ******************************************************************************
  * @file           : stack_test.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/18
  ******************************************************************************
  */

#include <iostream>
#include <stack>
#include "stack_test.h"

using namespace std;

static void _stack_array_test(void) {
    stack_array *s_array = stack_array_new();
    stack_array_push(s_array, 1);
    stack_array_push(s_array, 2);
    stack_array_push(s_array, 3);
    stack_array_print(s_array);
    std::cout << "½«ÒªÒÆ³ı" << stack_array_top(s_array) << std::endl;
    std::cout << "ÒÆ³ı" << stack_array_pop(s_array) << std::endl;
    stack_array_print(s_array);
    stack_array_del(s_array);
}

static void _stack_list_test(void) {
    stack_list *s_list = stack_list_new();
    stack_list_push(s_list, 1);
    stack_list_push(s_list, 2);
    stack_list_push(s_list, 3);
    stack_list_print(s_list);
    std::cout << "½«ÒªÒÆ³ı" << stack_list_top(s_list) << std::endl;
    std::cout << "ÒÆ³ı" << stack_list_pop(s_list) << std::endl;
    stack_list_print(s_list);
    stack_list_del(s_list);
}

static void _stack_reverse_string(void) {
    char buf[1024] = "Hello,Stack";
    char *p = buf;
    stack<char> s;
    while(*p != '\0') {
        s.push(*p);
        p++;
    }
    p = buf;
    while(!s.empty()) {
        *p = s.top();
        s.pop();
        p++;
    }
    cout << buf << endl;
}

static void _stack_reverse_list(void) {
    stack<list_node*> s;
    list_node *head = nullptr;
    list_node *temp = nullptr;
    head = list_insert(head, 1);
    head = list_insert(head, 2);
    head = list_insert(head, 3);
    for(list_node *i = head; i != nullptr; i = i->next) {
        s.push(i);
    }
    temp = s.top();
    s.pop();
    head = temp;
    while(!s.empty()) {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = nullptr;
    list_print(head);
}

void stack_test() {
    _stack_array_test();
    _stack_list_test();
    _stack_reverse_string();
    _stack_reverse_list();
}