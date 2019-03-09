//
//  AddTwoNum.cpp
//  DSACode
//
//  Created by wsy on 2019/3/6.
//  Copyright © 2019年 Wang,Suyan. All rights reserved.
//

#include "AddTwoNum.hpp"
#include <vector>
#include "iostream"
#include "stdlib.h"

using namespace std;

/**
 1.遍历节点 l1, 和 l2, 得到两个整数 i1 和 i2
 2.sum = i1 + i2
 3.创建节点
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 342 + 465 = 807
 */
namespace AddTwoNum {
    /**
     这种方法不可取，因为数据结构定义的为 int 类型，当数字太大的时候会发生栈溢出
     所有这种方法虽然实现了功能，但是程序上无法满足特殊情况。
     Line 34: Char 31: runtime error: signed integer overflow: 1000000000 * 9 cannot be represented in type 'int' (solution.cpp)
     
     [9]
     [1,9,9,9,9,9,9,9,9,9]
     */
    ListNode * Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
        int index = 0;
        int num1 = 0;
        int num2 = 0;
        
        // 求出 l1 代表的整数 sum1
        while (l1 != nullptr) {
            if (index == 0) {
                num1 = l1->val;
                index = 10;
            } else {
                num1 += index * l1->val;
                index = index * 10;
            }
            l1 = l1->next;
        }
        
        // 求出 l2 代表的整数 sum2
        index = 0;
        while (l2 != nullptr) {
            if (index == 0) {
                num2 = l2->val;
                index = 10;
            } else {
                num2 += index * l2->val;
                index = index * 10;
            }
            l2 = l2->next;
        }
        
        // 求出 sum1 和 sum2 的和
        int sum = num1 + num2;
        printf("sum = %d, sum1 = %d, sum2 = %d \n", sum, num1, num2);
        // 求整数有几位数
        int temp_sum = sum;
        ListNode *front = nullptr;
        ListNode *rear = nullptr;
        // 7 -> 0 - > 8
        /**
         7
         ret-next = null
         ret-val = 7
         
         0
         last-next = null
         ret-val = 0
         */
        // 相当于一个队列，不断的入队列
        // 根据求出的 sum 来创建一个单链表
        while (temp_sum != 0) {
            int value = temp_sum % 10;
            temp_sum /= 10;
            printf("value: %d, temp_sum:%d \n", value, temp_sum);
            // ListNode node = ListNode(value); 这种方式不可以，用指针
            ListNode *node = new ListNode(value);
            if (front == nullptr) {
                front = node;
            } else {
                rear->next = node;
            }
            rear = node;
        }
        return front;
    }
    
    ListNode * Solution::addTwoNumbers2(ListNode *l1, ListNode *l2) {
        /**
         其实这道题，开始就掉入一个陷阱了，因为链表中的数字是按照一个整数的逆序存储的，完全可以
         按照链表逐个相加，最后得出结果；这个加法正好匹配！！！
         
         2 -> 4 -> 3 -> null
         5 -> 6 -> 4 -> null
         7 -> 0 -> 7+1 -> null
         
         Runtime: 44 ms, faster than 66.16% of C++ online submissions for Add Two Numbers.
         Memory Usage: 19.2 MB, less than 44.18% of C++ online submissions for Add Two Numbers.
         
         Runtime: 40 ms, faster than 96.78% of C++ online submissions for Add Two Numbers.
         Memory Usage: 19 MB, less than 82.09% of C++ online submissions for Add Two Numbers.
         */
        ListNode *front = nullptr;
        ListNode *rear = nullptr;
        
        ListNode *tempL1 = l1;
        ListNode *tempL2 = l2;
        // 用来标记进位的值，如果大于等于10，则进位为1
        int num = 0;
        
        while (tempL1 != nullptr || tempL2 != nullptr) {
            int l1Value = 0;
            if (tempL1 != nullptr) {
                l1Value = tempL1->val;
                tempL1 = tempL1->next;
            }
            int l2Value = 0;
            if (tempL2 != nullptr) {
                l2Value = tempL2->val;
                tempL2 = tempL2->next;
            }
            int sum = l1Value + l2Value + num;
            int value = sum;
            if (sum >= 10) {
                num = 1;
                value = sum % 10;
            } else {
                num = 0;
            }
            
            // 创建一个单链表
            ListNode *node = new ListNode(value);
            if (front == nullptr) {
                front = node;
            } else {
                rear->next = node;
            }
            rear = node;
        }
        /**
         如果链表都为空了，但是进位为1，那么需要把进位单独创建一个节点
         */
        if (num > 0) {
            rear->next = new ListNode(num);
        }
        
        return front;
    }
}

