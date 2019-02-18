//
//  ViewController.m
//  DSACode
//
//  Created by Wang,Suyan on 2018/4/10.
//  Copyright © 2018年 Wang,Suyan. All rights reserved.
//

#import "ViewController.h"
#include "LEFClass10.hpp"
#include "LEFClass11.hpp"
#import <iostream>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    [self testClass10];
    [self testClass11];
}

- (void)testClass11 {
    using std::cout;
    using std::endl;
    
    Time planning(1, 10);
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    
    cout << "planning time = ";
    planning.Show();
    cout << endl;
    
    cout << "coding time = ";
    coding.Show();
    cout << endl;
    
    cout << "fixing time = ";
    fixing.Show();
    cout << endl;
    
    total = coding.Sum(fixing);
    cout << "coding.Sum time = ";
    total.Show();
    cout << endl;
    
    Time sum = coding + fixing + planning;
//    sum = coding.operator+(fixing);
    cout << "coding.Sum + time = ";
    sum.Show();
    cout << endl;
    
    Time diff = fixing - coding;
    cout << "fixing - coding time = ";
    diff.Show();
    cout << endl;
    
    Time adjust = fixing * 1.2;
    // Error: 不使用友元函数定义
    // adjust = 1.2 * fixing;
    cout << "fixing * 1.2 time = ";
    adjust.Show();
    cout << endl;
    
    // Time 重载了 <<，可直接打印对象
    cout << adjust << ", the end";
}

- (void)testClass10 {
    Stock stock = Stock("Lefex");
    stock.show();
    
    // 隐式调用默认构造函数
    Stock stock2;
    // 显式调用默认构造函数
    Stock stock3 = Stock();
    stock2.show();
    
    Stock stock4 = Stock("Lefex4", 10, 20);
    stock4.show();
    
    // 需要使用 delete 释放
    Stock *stock5 = new Stock("Lefex5");
    stock5->show();
    delete stock5;
    
    // C++11 列表初始化方法
    Stock stock6 = {"Lefex6"};
    stock6.show();
    
    Stock ret = stock4.topval(stock6);
    ret.show();
    
    // 对象数组
    Stock stocks[4] = {
        Stock("Lefex1"),
        Stock("Lefex2"),
        Stock("Lefex3"),
        Stock("Lefex4"),
    };
    
}


@end
