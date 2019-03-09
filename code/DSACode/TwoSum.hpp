//
//  TwoSum.hpp
//  DSACode
//
//  Created by wsy on 2019/3/5.
//  Copyright © 2019年 Wang,Suyan. All rights reserved.
//

#ifndef TwoSum_hpp
#define TwoSum_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;
using std::unordered_map;

/**
 【题目】
 给出一个整形数组和一个目标值，找出数组中，两个成员的和是目标值所在数组中的下标。
 你可以假定每次输入只对应一种答案，且不能使用数组中同样的元素。
 
 【审题】
 题中要求：
 1.给定一个数组和一个目标值，假如数组为 nums = [2, 7, 11, 15], 目标值为：target = 9
 2.找出目标值 9 是数组 nums 中哪两个元素的和
 3.返回找到元素的下标，比如 return [0, 1].
 
 【举例】
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 
 【方法】
 1. 两次遍历找到和为 target 的两个元素
 2. a.使用一个unordered_map用来保存 nums 中元素和它的下标
    b.每次查找找到 target - nums[i] 的差值，查找就是下一个要找的元素
 */

/**
 【C++向量 Vector】
 向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。
 跟任意其它类型容器一样，它能够存放各种类型的对象。可以简单的认为，向量是一个能够存放任意类型的动态数组
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
    vector<int> twoSum2(vector<int>& nums, int target);
};

#endif /* TwoSum_hpp */
