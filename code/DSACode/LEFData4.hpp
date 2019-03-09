//
//  LEFData4.hpp
//  DSACode
//
//  Created by wsy on 2019/2/26.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

#ifndef LEFData4_hpp
#define LEFData4_hpp

#include <stdio.h>
#include <iostream>

// 结构体定义
struct inflatable {
    char name[20];
    float volume;
    double price;
};

// 初始化一个结构体
inflatable pal = {
    "Lefe_x",
    10.0,
    40.9
};

// C++11的初始化方法
inflatable duck {"Lefe_x", 20.9, 10.0};


// 定义结构体 perks，并声明两个变量 mr_smith，ms_jones
struct perks {
    int key_number;
    char car[12];
} mr_smith, ms_jones;

// 定义一个匿名的结构体，并声明变量 position
struct {
    int x;
    int y;
} position;

// 结构体数组，gift[0], gift[1] 都是结构体 inflatable
inflatable gift[2] = {
    {"Lefe_x", 20.9, 10.0},
    {
        "Lefe_x",
        10.0,
        40.9
    }
};

typedef struct inflatable obj_class;

obj_class cls = {"Lefe_x", 20.9, 10.0};

struct widget {
    char brand[20];
    /**
     共用体，它一次只能表示一个值，如果设置了id_num，那么id_char设置的值将被
     清空，也就是它只能表示多种类型的一个值。
     */
    union id {
        long id_num;
        char id_char[20];
    } id_val;
    /**
     匿名共用体，由于无名字type_id和type_name将作为widget成员的两个成员
     */
    union {
        int type_id;
        char type_name[20];
    };
};

static inline void test_struct() {
    widget prize = {"Lefe_x", 100, 30};
    std::cout << prize.id_val.id_num << prize.type_id;
}

/**
 枚举：另一种创建符合常量的方式
 */
enum Color { red, orange, blue};
enum bits{ ont = 1, two = 2, four = 4, eight = 8};
enum { MaxNum = 10, MinNum = 1};

/**
 指针和自由存储空间：
 
 指针是一个变量，存储的不是值本身，而是值的地址
 double price = 100; &price 是 price 的内存地址
 
 运行阶段指程序正在运行，编译阶段指编译器将程序组合起来时；运行时可以对当时的情况进行合理安排，而编译时
 在编译阶段已经确定了。
 
 C++使用new关键字来申请内存空间，使用指针来记录所申请内存空间的地址；
 
 int update = 6; // 声明一个 int 类型的变量
 int * p_update; // 声明一个指向 int 类型的指针
 p_update = &update; // 指针 p_update 指向 update 变量的地址
 *p_update ; // 它的值为 6，对指针使用 * 取得是指针指向内存空间中的值。声明的时候使用 【类型 *】为一个指针，
 如果对指针变量前加 * ，取得就是指针对应的值。
 
 double price = 6;
 double * p_price = &price; // 声明一个指向double类型的指针，初始化为price变量的地址
 
 long * price;
 *price = 100; // 赋值
 */




#endif /* LEFData4_hpp */
