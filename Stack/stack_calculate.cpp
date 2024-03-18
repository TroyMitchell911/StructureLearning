/**
  ******************************************************************************
  * @file           : stack_calculate.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/18
  ******************************************************************************
  */

#include <cstring>
#include <stack>
#include <string>
#include <iostream>
#include "stack_calculate.h"

using namespace std;

static int _get_num(char** formula, string* num_str) {
    char buf[1024] = {0};
    char *p = *formula, *q = buf;
    while(*p != '\0') {
        if((*p >= '0' && *p <= '9')) {
            *(q++) = *(p++);
        } else {
            break;
        }
    }
    *q = '\0';
    int num = stoi(buf);
    if(num_str != nullptr) {
        num_str->append(*formula, p - *formula);
    }
    *formula = *p == ',' ? p + 1 : p;
    return num;
}

static int _calculate(int num1, int num2, char symbol) {
    if(symbol == '+') {
        return num1 + num2;
    } else if(symbol == '-') {
        return num1 - num2;
    } else if(symbol == '*') {
        return num1 * num2;
    } else if(symbol == '/') {
        return num1 / num2;
    }
    return 0;
}

static int higher_symbol(char symbol1, char symbol2) {
    char symbols[][2] = {
            {'*', '/'},
            {'+','-'}
    };
    int symbol1_prio, symbol2_prio;
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < 2; j++) {
            if(symbols[i][j] == symbol1) {
                symbol1_prio = i;
            }
        }
    }

    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < 2; j++) {
            if(symbols[i][j] == symbol2) {
                symbol2_prio = i;
            }
        }
    }
    return symbol1_prio <= symbol2_prio ? 1 : 0;
}

int stack_calculate(char* formula) {
    int num1, num2;
    stack<int> s;
    while(*formula != '\0') {
        if(isdigit(*formula)) {
            s.push(_get_num(&formula, nullptr));
        } else {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            num1 = _calculate(num2, num1, *(formula++));
            s.push(num1);
        }
    }
    cout << num1 << endl;
    return 0;
}
string stack_calculate_infix2postfix(char* formula) {
    static string postfix;
    stack<char> s;
    postfix = "";
    while(*formula != '\0') {
        if(isdigit(*formula)) {
            string buf;
            _get_num(&formula, &buf);
            postfix.append(buf);
            postfix.append(",");
        } else if(*formula == '(') {
            s.push(*(formula++));
        } else if(*formula == ')') {
            while(!s.empty() && s.top() != '(') {
                char buf[2] = {0};
                buf[0] = s.top();
                s.pop();
                postfix.append(buf);
            }
            formula++;
            s.pop();
        } else {
            while(!s.empty() && s.top() != '(' && higher_symbol(s.top(), *formula)) {
                char buf[2] = {0};
                buf[0] = s.top();
                s.pop();
                postfix.append(buf);
            }
            s.push(*(formula++));
        }
    }
    while(!s.empty()) {
        char buf[2] = {0};
        buf[0] = s.top();
        s.pop();
        postfix.append(buf);
    }
    return postfix;
}
