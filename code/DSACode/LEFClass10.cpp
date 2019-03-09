//
//  LEFClass10.cpp
//  DSACode
//
//  Created by Wang,Suyan on 2019/2/16.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

/**
 * 第10章 对象和类
 */

#include "LEFClass10.hpp"
#include <iostream>

// 默认构造函数
Stock::Stock()
{
    std::cout << "默认构造函数被调用\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

// 构造函数
Stock::Stock(const std::string & co, long n, double pr) {
    std::cout << "自定义构造函数被调用：" << co << "\n";
    company = co;
    if (n < 0) {
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

// 析构函数
Stock::~Stock() {
    std::cout << "析构函数 ~Stock 被调用\n";
}


/**
 成员函数的实现有两个特征：
 1.需要使用作用域解析运算符（::）来标识函数所属的类；
 2.方法可以访问私有成员；比如，在buy中可以访问shares变量。
 */
void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "num 不能为负数\n";
    } else {
        shares += num;
    }
    share_val = price;
    set_tot();
}

void Stock::sell(long num, double price) {
    using std::cout;
    if (num < 0) {
        std::cout << "num 不能小于 0\n";
    } else if (num > shares) {
        std::cout << "num 不能大于 shares\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show() {
    std::cout << "The comany is: " << company << ",total value is: " << total_val << "\n";
}

const Stock & Stock::topval(const Stock & s) const {
    if (s.total_val > total_val) {
        return s;
    } else {
        /**
         this：指向是调用对象
         */
        return *this;
    }
}
