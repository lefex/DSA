//
//  LEFClass13.hpp
//  DSACode
//
//  Created by wsy on 2019/2/23.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

/**
 is-a 关系的继承
 如何以公有方式从一个类派生出另一个类
 保护访问
 构造函数成员初始化列表
 向上向下强制转换
 虚成员函数
 早期（静态）联编与晚期（动态）联编
 抽象基类
 纯虚函数
 何时及如何使用公有继承
 */

#ifndef LEFClass13_hpp
#define LEFClass13_hpp

#include <stdio.h>
#include <string>

using std::string;



class TableTennisPlayer {
private:
    /**
     派生类无法访问这些私有数据成员
     */
    string firstname;
    string lastname;
    bool hasTable;
public:
    /**
     这些公有的成员函数都被继承，且做为派生类的方法
     */
    TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; };
    void ResetTable(bool v) { hasTable = v; };
};

// 继承自 TableTennisPlayer
class RatePlayer : public TableTennisPlayer {
private:
    unsigned int rating;
public:
    /**
     派生类需要自己的构造函数，不能访问积累的私有成员，故只能通过构造函数初始化基类的私有
     数据成员。可以添加自己的数据成员，这里添加了 rating，并在析构函数中进行初始化d
     */
    RatePlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
    RatePlayer(unsigned int r,  const TableTennisPlayer & tp);
    unsigned int Rating() const { return rating; };
    void ResetRating (unsigned int r) { rating = r;};
};
















#endif /* LEFClass13_hpp */
