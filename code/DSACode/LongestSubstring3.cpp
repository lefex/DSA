//
//  LongestSubstring3.cpp
//  DSACode
//
//  Created by wsy on 2019/3/9.
//  Copyright © 2019年 Wang,Suyan. All rights reserved.
//

#include "LongestSubstring3.hpp"
#include <unordered_map>

using std::unordered_map;

namespace LongestSubstring3 {
    /**
     for(auto& v : record)
     printf("%c-%d", v.first, v.second);
     printf("\nmax: %d \n", max);
     
     printf("\ni=%d\n", i);
     
     // 好娄的算法
     Runtime: 712 ms, faster than 9.61% of C++ online submissions for Longest Substring Without Repeating Characters.
     Memory Usage: 149 MB, less than 9.61% of C++ online submissions for Longest Substring Without Repeating Characters.
     
     Runtime: 684 ms, faster than 9.87% of C++ online submissions for Longest Substring Without Repeating Characters.
     Memory Usage: 148.9 MB, less than 10.32% of C++ online submissions for Longest Substring Without Repeating Characters.
     
     【思想】
     1.遍历字符串
     2.

     */
    int Solution::lengthOfLongestSubstring(string s) {
        //record用来记录遍历过的子字符串，通过它计算字符串的长度
        unordered_map<char, int> record;
        size_t len = s.size();
        int max = 0;
        for (int i = 0; i < len;) {
            char c = s[i];
//            printf("%c - %d\n", c, i);
            // "pwwkew"
            // 找到了重复的字符串，求得max
            if (record.find(c) != record.end()) {
                // 说明找到了重复的字符
                int f_index = record[c];
                int size = (int)record.size();
                max = max > size ? max : size;
                // 修改 i 的值重下一个元素开始遍历
                i = f_index+1;
                record.clear();
            } else {
                record[c] = i;
                i += 1;
            }
        }
        // 如果record中包含了字符串，需要计算它的长度
        int size = (int)record.size();
        max = max > size ? max : size;

        return max;
    }
    
    /**
     Runtime: 20 ms, faster than 97.41% of C++ online submissions for Longest Substring Without Repeating Characters.
     Memory Usage: 14.7 MB, less than 88.03% of C++ online submissions for Longest Substring Without Repeating Characters.
     
     Runtime: 20 ms, faster than 97.41% of C++ online submissions for Longest Substring Without Repeating Characters.
     Memory Usage: 14.7 MB, less than 87.06% of C++ online submissions for Longest Substring Without Repeating Characters.
     */
    int Solution::lengthOfLongestSubstring2(string s) {
        int freg[256] = {0};
        // 滑动窗口为 s[l...r]
        int l = 0, r = -1;
        int res = 0;
        while (l < s.size()) {
            if (r+1 < s.size() && freg[s[r+1]] == 0) {
                r++;
                freg[s[r]]++;
            } else {
                freg[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
    
    
}
