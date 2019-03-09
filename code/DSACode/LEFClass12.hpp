//
//  LEFClass12.hpp
//  DSACode
//
//  Created by Wang,Suyan on 2019/2/18.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

/**
 第12章 类和动态内存分配
 对类成员使用动态内存分配
 隐式和显式复制构造函数
 隐式和显式重载赋值预算符
 在构造函数中使用new所必须完成的工作
 使用静态类成员
 将定位new运算符用于对象
 使用指向对象的指针
 实现队列抽象数据类型（ADT）
 */

/**
 C++为类自动提供了下面这些成员函数：
 默认构造函数，如果没有定义构造函数
 默认析构函数，如果没有定义
 复制构造函数，如果没有定义
 赋值运算符，如果没有定义
 地址运算符，如果没有定义
 */

#ifndef LEFClass12_hpp
#define LEFClass12_hpp

#include <stdio.h>
#include <iostream>

// nullptr C++11 提供的空指针关键字

/**
 使用new关键字需要注意的地方：
 1、若在构造函数中使用new来初始化指针成员，则应在析构函数中使用delete
 2、new和delete必须兼容，new对应与delete，new[] 对于与 delete[]
 3、如果有多个构造函数，则必须以相同的方式使用 new，要么代中括号，要么不带
 4、应定义一个复制构造函数，通过深度复制将一个对象复制到另一个对象；
 5、应定义一个赋值运算符，通过深度复制将一个对象复制到另一个对象；
 */

/**
 有关返回对象的说明：
 返回对象可以是对象的引用、指向对象的const引用、const对象；
 返回指向const的引用：const Vector &
 返回指向非const的引用：Vector &
 返回对象：Vector
 返回const对象：const Vector

 */

class StringBad {
private:
    // str 是一个指针，因此构造函数必须提供内存用来存储
    char * str;
    int len;
    /**
     num_strings 定义为 static，意思是说所有的的StringBad对象共享一个内存空间，
     不管创建多少个StringBad对象，num_strings始终只有一个。
     */
    static int num_strings;
public:
    StringBad(const char * s);
    StringBad(const StringBad & s);
    StringBad & operator=(const StringBad & st);
    StringBad();
    ~StringBad();
    // 静态成员函数，只能调用静态变量，比如 num_strings，它与类本身无关
    static int HowManay();
    friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
    // 重置赋值运算符 []，比如：str[0]，可修改，比如可以调用 str[0] = 'l'
    char & operator[](int i);
    // 重置赋值运算符 []，比如：str[0]，只读的，不可以调用 str[0] = 'l'
    const char & operator[](int i) const;
};

/**
 StringBad 是一个反例，String 是它的纠正版，从中可以了解到标准C++库是如何
 定义一个String类的。
 */

using std::ostream;
using std::istream;

class String {
private:
    char * str;
    int len;
    static int num_strings2;
    static const int CINLIM = 80;
public:
    String(const char * s);
    String();
    // 复制构造函数，两个字符串的复制将会调用这个构造函数
    String(const String &);
    ~String();
    int length() const { return len; };
    
    String & operator=(const String & st);
    String & operator=(const char *);
    // 重置赋值运算符 []，比如：str[0]，可修改，比如可以调用 str[0] = 'l'
    char & operator[](int i);
    // 重置赋值运算符 []，比如：str[0]，只读的，不可以调用 str[0] = 'l'
    const char & operator[](int i) const;
    
    // 重写比较运算符
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    // 重写输出运算符
    friend ostream & operator<<(ostream & os, const String *st);
    // 重写输入运算符
    friend istream & operator>>(istream & is, const String *st);
    
    
};


/**
 模拟ATM机，表示顾客
 */
class Customer {
private:
    // 顾客到店时间
    long arrive;
    // 顾客在ATM机上的处理时间，它是一个随机数
    int processtime;
public:
    Customer() { arrive = processtime = 0; };
    void set(long when);
    long when() const { return arrive; };
    int ptime() const { return processtime; }
};

// 定义队列中的对象
typedef Customer Item;

/**
 模拟队列，使用单链表数据结构，队列中保存的是 Customer 对象
 
 -----------------------------------------------------------
 <- customer0  | customer1 | customer2 | customer3 | customer4 <--
 -----|------------------------------------------------|------
    front                                             rear
 */
class Queue {
private:
    /**
     定义一个结构体，表示链表的节点，每一个节点保存了节点的数据和下一个节点的指针
     它在类声明中定义，所以Node的作用域为整个类，由于声明为私有部分，只能在本类中
     使用，外部不可以使用。如果声明为公有部分则外部可以使用 Queue::Node 调用
     */
    struct Node { Item item; struct Node *next; };
    enum { Q_SIZE = 10};
    // 要跟踪链表，必须知道第一个节点的地址
    Node * front;
    // 由于队列是先进后出的，保存最后一个节点的地址对入队非常方便
    Node * rear;
    // 队列中当前的大小
    int items;
    // 队列的最大限制，它是常量，只能初始化，但不能给它赋值
    const int qsize;
    /**
     定义复制函数，防止队列进行复制操作，因为是私有函数，外部无法调用
     定义赋值函数，防止队列进行赋值（=）操作，因为是私有函数，外部无法调用
     */
    Queue(const Queue & q) : qsize(0) {};
    Queue & operator=(const Queue & q) { return *this; };
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
    
};



#endif /* LEFClass12_hpp */
