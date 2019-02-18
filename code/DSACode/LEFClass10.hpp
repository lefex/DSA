//
//  LEFClass10.hpp
//  DSACode
//
//  Created by Wang,Suyan on 2019/2/16.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

#ifndef LEFClass10_hpp
#define LEFClass10_hpp

#include <stdio.h>
#include <string>

/**
 第10章 对象和类
 过程性编程和面向对象编程
 类概念
 如何定义和实现类
 公有访问和私有访问
 类方法（类成员函数）
 创建和使用对象
 类的构造函数和析构函数
 const成员函数；
 this指针；
 创建对象数组；
 类作用域；
 抽象数据类型；
 */

/**
 * 定义一个股票类，通常C++中回把接口（类定义）放到头文件中，
 * 并将实现放到源文件中。
 */
// 类定义使用关键字 class
class Stock
{
/**
 控制对成员的访问，private为私有的，company，shares等都是Stock的私有
 数据成员，如果使用非成员函数访问这些私有成员将报错。
 */
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    /**
     默认函数，当为一个类提供了构造函数，必须提供一个默认构造函数
     隐式调用默认构造函数
     Stock stock;
     显式调用默认构造函数
     Stock stock = Stock();
     */
    Stock();
    /**
     构造函数，带有默认参数 n（shares）为0，pr（share_val）为 0.0
     1.默认参数可以省略
     Stock stock = Stock("Lefex");
     2.传递默认参数
     Stock stock4 = Stock("Lefex4", 10, 20);
     3.使用 new 关键字创建的对象需要使用 delete 移除，否则不会自动释放
     Stock *stock5 = new Stock();
     delete stock5;
     */
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    /**
     析构函数，对象被销毁后将自动被调用，它主要用来做清理工作，比如通过new来
     分配内存，需要使用delete来释放内存。通常会在析构函数中使用delete来释放
     对像中的内存空间。
     */
    ~Stock();
    /**
     成员函数
     */
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
    
    /**
     这个函数用来找出最大的Stock，改函数隐式地访问一个对象，
     而显式地访问另一个对象，并返回一个对象的引用。const说明：
     1、括号中的 const 表明该函数不会修改被显式访问的对象
     2、括号后的 const 表明该函数不会修改被隐式访问的对象
     3、由于返回的是两个 const 对象之一的引用，因此返回类型也为 const 类型
     */
    const Stock & topval(const Stock & s) const;
};

#endif /* LEFClass10_hpp */
