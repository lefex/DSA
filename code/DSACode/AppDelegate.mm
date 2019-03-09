//
//  AppDelegate.m
//  DSACode
//
//  Created by Wang,Suyan on 2018/4/10.
//  Copyright © 2018年 Wang,Suyan. All rights reserved.
//

#import "AppDelegate.h"
#include "TwoSum.hpp"
#include "AddTwoNum.hpp"
#include "LongestSubstring3.hpp"

/**
 C++ API
 http://www.cplusplus.com/reference/unordered_map/unordered_map/
 http://c.biancheng.net/view/530.html
 */

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [self testLonestSubstring3];
    return YES;
}

- (void)testLonestSubstring3 {
    LongestSubstring3::Solution ret = LongestSubstring3::Solution();
    int max = ret.lengthOfLongestSubstring2("aab");
    NSLog(@"max: %@", @(max));
}

- (void)testAddTwoNum {
    /*
     Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
     Output: 7 -> 0 -> 8
     Explanation: 342 + 465 = 807.
     */
    AddTwoNum::Solution sum = AddTwoNum::Solution();
    AddTwoNum::ListNode l1_0 = AddTwoNum::ListNode(2);
    AddTwoNum::ListNode l1_1 = AddTwoNum::ListNode(4);
    l1_0.next = &l1_1;
    AddTwoNum::ListNode l1_2 = AddTwoNum::ListNode(3);
    l1_1.next = &l1_2;
    
    AddTwoNum::ListNode l2_0 = AddTwoNum::ListNode(5);
    AddTwoNum::ListNode l2_1 = AddTwoNum::ListNode(6);
    l2_0.next = &l2_1;
    AddTwoNum::ListNode l2_2 = AddTwoNum::ListNode(4);
    l2_1.next = &l2_2;
    
    AddTwoNum::ListNode *ret = sum.addTwoNumbers2(&l1_0, &l2_0);
    while (ret != nullptr) {
        printf("ret value: %d", ret->val);
        ret = ret->next;
    }

}

- (void)testTwoSum {
    Solution sum = Solution();
    vector<int> nums = {1, 2, 4, 6, 9};
    int target = 8;
    vector<int> rets = sum.twoSum(nums, target);
    if (rets.size() > 0) {
        printf("%d , %d \n", rets[0], rets[1]);
    } else {
        printf("not found 1 \n");
    }
    
    vector<int> rets2 = sum.twoSum2(nums, target);
    if (rets.size() > 0) {
        printf("%d , %d \n", rets2[0], rets2[1]);
    } else {
        printf("not found 2 \n");
    }
}


@end
