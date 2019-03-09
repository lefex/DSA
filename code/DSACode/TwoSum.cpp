//
//  TwoSum.cpp
//  DSACode
//
//  Created by wsy on 2019/3/5.
//  Copyright © 2019年 Wang,Suyan. All rights reserved.
//

#include "TwoSum.hpp"

/**
 nums = [2, 7, 11, 15], target = 9
 两次遍历找到和为 target 的两个元素
 时间复杂度为：O(n*n)
 空间复杂度为：
 
 Runtime: 124 ms, faster than 37.43% of C++ online submissions for Two Sum.
 Memory Usage: 9.6 MB, less than 62.01% of C++ online submissions for Two Sum.
 */
vector<int>  Solution::twoSum(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        int fnum = nums[i];
        for (int j = i+1; j < nums.size(); j++) {
            int snum = nums[j];
            if (fnum + snum == target) {
                return {i, j};
            }
        }
    }
    return vector<int>();
};

/**
 1.使用一个unordered_map用来保存 nums 中元素和它的下标
 2.每次查找找到 target - nums[i] 的差值，查找就是下一个要找的元素
 
 Runtime: 12 ms, faster than 97.81% of C++ online submissions for Two Sum.
 Memory Usage: 10.4 MB, less than 33.11% of C++ online submissions for Two Sum.
 */
vector<int> Solution::twoSum2(vector<int> &nums, int target) {
    unordered_map<int, int> record;
    for (int i = 0; i < nums.size(); i++) {
        int sub = target - nums[i];
        if (record.find(sub) != record.end()) {
            // 找到了
            return {record[sub], i};
        } else {
            record[nums[i]] = i;
        }
    }
    return vector<int>();
};



