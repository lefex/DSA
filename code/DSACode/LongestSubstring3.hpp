//
//  LongestSubstring3.hpp
//  DSACode
//
//  Created by wsy on 2019/3/9.
//  Copyright © 2019年 Wang,Suyan. All rights reserved.
//

#ifndef LongestSubstring3_hpp
#define LongestSubstring3_hpp

#include <stdio.h>
#include <string>

using namespace std;

/**
 【题目】
 从字符串中找到最长不重复的子字符串。
 
 【审题】
 题中要求：
 1.给的一个字符串 s
 2.找出最长不重复的子字符串，也就是说从字符串中查找没有重复的子字符串，必须连续
 
 【举例】
 Input: "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.
 
 Input: "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.
 
 Input: "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
 */


namespace LongestSubstring3 {
    class Solution {
    public:
        int lengthOfLongestSubstring(string s);
        int lengthOfLongestSubstring2(string s);
    };
}






#endif /* LongestSubstring3_hpp */
