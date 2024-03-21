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
/**
 * @brief 从公式中获取一个数字，遇到非数字停止
 * @param formula 公式字符串，注意这里是二级指针，目的是读取完数字直接在该函数内修改指针
 * @param num_str 保存数字字符串的缓冲区指针，需要用数字字符串的地方用，不用写null
 * @return 获取到的数字
 */
static int _get_num(char** formula, string* num_str) {
    char buf[1024] = {0};
    char *p = *formula, *q = buf;
    /* 遍历字符串 */
    while(*p != '\0') {
        if((*p >= '0' && *p <= '9')) {
            *(q++) = *(p++);
        } else {
            break;
        }
    }
    /* 由于char数组中是以\0作为结尾的 stoi也会根据这个判断字符串结束，所以加上\0 */
    *q = '\0';
    /* 将数字字符串转换成数字 */
    int num = stoi(buf);
    /* 如果保存数字字符串的缓冲区指针不为null，则添加进去 */
    if(num_str != nullptr) {
        num_str->append(*formula, p - *formula);
    }
    /* 在原字符串中跳过我们读取的数字部分 */
    /* 在我们实现中，中缀表达式转后缀表达式中的逗号是用来作为分割，所以需要跳过 */
    *formula = *p == ',' ? p + 1 : p;
    return num;
}
/**
 * @brief 计算函数
 * @param num1 数1
 * @param num2 数2
 * @param symbol 计算符号
 * @return 结果
 */
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
/**
 * @brief 判断符号优先级
 * @param symbol1
 * @param symbol2
 * @return symbol1比symbol2大返回1 否则返回0
 */
static int higher_symbol(char symbol1, char symbol2) {
    /* 符号优先级表，这里优先级采用0为最高，
     * 这样有个好处，就是symbol2如果是未知符号，那么一定比已知符号小
     * 为什么symbol1不会是未知符号呢 具体看到该函数的调用就知道  */
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
/**
 * @brief 借助栈计算后缀表达式
 * @param formula 后缀表达式
 * @return 计算结果
 */
int stack_calculate(char* formula) {
    int num1, num2;
    stack<int> s;
    /* 遍历后缀表达式 */
    while(*formula != '\0') {
        /* 如果当前字符串指针第一个字符是数字 */
        if(isdigit(*formula)) {
            /* 将读取到的数字入栈 */
            s.push(_get_num(&formula, nullptr));
        } else {
            /* 如果不是数字了，那么一定是计算符号了，后缀表达式的性质就是如此 */
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            /* 计算值并且放入num1中且入栈，注意这里将formula指针++是为了跳过计算符号 */
            num1 = _calculate(num2, num1, *(formula++));
            /* 将计算结果入栈，因为这时候可能只是中间结果，还不是最终结果 */
            s.push(num1);
        }
    }
    /* 这里把num1换成s.top()效果也是一样的 */
    cout << num1 << endl;
    return 0;
}
/**
 * @brief 中缀表达式转后缀表达式
 * @param formula 中缀表达式字符串
 * @return 后缀表达式字符串
 */
string stack_calculate_infix2postfix(char* formula) {
    string postfix;
    stack<char> s;
    /* 清空字符串 */
    postfix = "";
    /* 遍历中缀表达式 */
    while(*formula != '\0') {
        /* 判断是否为数字 */
        if(isdigit(*formula)) {
            /* 从中缀表达式中获取一个数字字符串 */
            string buf;
            _get_num(&formula, &buf);
            /* 添加到后缀表达式字符串中并且加入逗号作为数字分割符 */
            postfix.append(buf);
            postfix.append(",");
        } else if(*formula == '(') {
            /* 如果是左括号的话，入栈后跳过该符号 */
            s.push(*(formula++));
        } else if(*formula == ')') {
            /* 如果遇到右括号了，我们把计算符号一直出栈直到遇到栈中的左括号 */
            while(!s.empty() && s.top() != '(') {
                char buf[2] = {0};
                buf[0] = s.top();
                s.pop();
                postfix.append(buf);
            }
            /* 跳过右括号 */
            formula++;
            /* 出栈左括号 */
            s.pop();
        } else {
            /* 如果是计算符号了，
             * 我们会检查栈中的符号是否比当前符号优先级高，
             * 如果高就出栈 */
            while(!s.empty() && s.top() != '(' && higher_symbol(s.top(), *formula)) {
                char buf[2] = {0};
                buf[0] = s.top();
                s.pop();
                postfix.append(buf);
            }
            /* 不管有没有出栈我们都要将当前符号入栈，因为我们的符号都是从栈拿的 */
            s.push(*(formula++));
        }
    }
    /* 可能遇到字符串结果但栈里还有符号的情况 */
    while(!s.empty()) {
        char buf[2] = {0};
        buf[0] = s.top();
        s.pop();
        postfix.append(buf);
    }
    return postfix;
}
