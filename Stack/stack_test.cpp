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
#include "stack_calculate.h"

using namespace std;

/**
 * @brief 使用循环数组创建的栈的测试函数
 */
static void _stack_array_test(void) {
    stack_array *s_array = stack_array_new();
    stack_array_push(s_array, 1);
    stack_array_push(s_array, 2);
    stack_array_push(s_array, 3);
    stack_array_print(s_array);
    std::cout << "将要移除" << stack_array_top(s_array) << std::endl;
    std::cout << "移除" << stack_array_pop(s_array) << std::endl;
    stack_array_print(s_array);
    stack_array_del(s_array);
}
/**
 * @brief 使用链表创建的栈的测试函数
 */
static void _stack_list_test(void) {
    stack_list *s_list = stack_list_new();
    stack_list_push(s_list, 1);
    stack_list_push(s_list, 2);
    stack_list_push(s_list, 3);
    stack_list_print(s_list);
    std::cout << "将要移除" << stack_list_top(s_list) << std::endl;
    std::cout << "移除" << stack_list_pop(s_list) << std::endl;
    stack_list_print(s_list);
    stack_list_del(s_list);
}
/**
 * @brief 使用栈反转字符串
 */
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
/**
 * @brief 使用栈反转链表
 */
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
    /* 首先获取链表最后一个节点 */
    temp = s.top();
    s.pop();
    /* 将链表头设置为最后一个节点，因为经过反转之后
     * 之前的最后一个节点就是现在的第一个节点 */
    head = temp;
    while(!s.empty()) {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    /* 将之前的第一个节点的下一个指向null */
    temp->next = nullptr;
    list_print(head);
}
/**
 * @brief 使用栈检查括号匹配性
 * @param str 含括号的字符串
 */
static void _stack_check_bracket_balance(char* str) {
    stack<char> s;
    for(char *p = str; *p != '\0'; p++) {
        if(*p == '(' || *p == '[' || *p == '{') {
            s.push(*p);
        } else {
            switch(*p) {
                case ')' :
                    if(s.top() != '(') {
                        cout << "括号不匹配" << endl;
                        return;
                    }
                    s.pop();
                    break;
                case ']':
                    if(s.top() != '[') {
                        cout << "括号不匹配" << endl;
                        return;
                    }
                    s.pop();
                    break;
                case '}':
                    if(s.top() != '{') {
                        cout << "括号不匹配" << endl;
                        return;
                    }
                    s.pop();
                    break;
                default:
                    break;
            }
        }
    }
    cout << "括号匹配" << endl;
}

void stack_test() {
    _stack_array_test();
    _stack_list_test();
    _stack_reverse_string();
    _stack_reverse_list();
    _stack_check_bracket_balance("(){[]}");
    _stack_check_bracket_balance("({)[]}");
    /*
     * 3*5-2*3+3
     * (3,5*)-(2,3*)+3
     * 3,5*2,3*-3+
     * */
    string test = stack_calculate_infix2postfix("3*5-2*3+3");
    cout << test << endl;
    char *formula = (char*)test.c_str();
    stack_calculate(formula);

}