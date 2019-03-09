//
//  LEFClass13.cpp
//  DSACode
//
//  Created by wsy on 2019/2/23.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

#include "LEFClass13.hpp"
#include <iostream>

TableTennisPlayer:: TableTennisPlayer (const string & fn, const string & ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht) {
}

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}

/**
 派生类构造函数应通过成员初始化列表将基类信息传递给基类构造函数
 派生类构造函数应初始化派生类新增的数据成员
 */
RatePlayer:: RatePlayer(unsigned int r, const string & fn, const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht){
    rating = r;
}

// 调用了基类的复制构造函数
RatePlayer::RatePlayer(unsigned int r,  const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r) {
    
}
