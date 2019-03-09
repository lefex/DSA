//
//  AddTwoNum.hpp
//  DSACode
//
//  Created by wsy on 2019/3/6.
//  Copyright © 2019年 Wang,Suyan. All rights reserved.
//

#ifndef AddTwoNum_hpp
#define AddTwoNum_hpp

#include <stdio.h>

/**
 【题目】
 有两个非空的单链表，链表中的元素为正整数，数组是按逆序存储的，且每个
 节点只有一个数字。求出两个两边的和并以链表的形式返回。
 
 【审题】
 题中要求：
 1.给定两个单链表，假如：l1: 2->4->3 , l2: 5->6->4
 2.把 l1 和 l2 进行相加，结果为：7->0->8，也就是342+465=708
 3.假设节点的值均为正整数，且只有一个数字
 
 【举例】
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 Explanation: 342 + 465 = 807.
 
 */

namespace AddTwoNum {
    // 定义一个单链表
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
        ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2);
    };
}



#endif /* AddTwoNum_hpp */
