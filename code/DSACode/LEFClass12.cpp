//
//  LEFClass12.cpp
//  DSACode
//
//  Created by Wang,Suyan on 2019/2/18.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

#include "LEFClass12.hpp"
#include <cstring>

using std::cout;

/**
 初始化静态成员，不能再声明处初始化，声明描述了如何分配内存，但并不分配内存。可以在
 类的单独之外进行初始化是因为，静态成员不是类的组成部分，它是单独存储的。如果静态成员是
 const枚举或整数类型则可以在类声明中初始化。
 */
int StringBad::num_strings = 0;

StringBad::StringBad(const char * s) {
    len = (int)std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings;
    cout << std::endl;
}

// 复制函数
StringBad::StringBad(const StringBad & s) {
    num_strings++;
    len = s.len;
    str = new char [len+1];
    std::strcpy(str, s.str);
}

// 提供赋值运算符
StringBad & StringBad::operator=(const StringBad & st) {
    if (this == &st) {
        return *this;
    }
    // 释放掉旧的内存，分配新的内存
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

StringBad::StringBad(){
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings;
    cout << std::endl;
}

StringBad::~StringBad() {
    cout << str << " object deleted!\n";
    --num_strings;
    cout << num_strings << " left \n";
    // str 指向了 new 创建的内存空间，当对象销毁后，这块内存也需要销毁
    /**
     在构造函数中使用new来分配内存时，必须在析构函数中使用delete来释放内存，如果
     分配内存使用的时new [] ,则在析构函数中必须使用 delete []。
     */
    delete [] str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & st) {
    os << st.str;
    return os;
}

// 静态成员函数只能访问静态变量，因此不能访问 len 和 str 属性
int StringBad::HowManay() {
    return num_strings;
}


/////////////////////////////////
int String::num_strings2 = 0;


String::String(const char * s) {
    len = (int)std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    num_strings2++;
    cout << num_strings2;
    cout << std::endl;
}

String::String(){
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings2++;
    cout << num_strings2;
    cout << std::endl;
}

String::String(const String & st) {
    num_strings2++;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str, st.str);
}

String::~String() {
    --num_strings2;
    delete [] str;
}

String & String::operator=(const String & st) {
    if (this == &st) {
        return *this;
    }
    delete [] str;
    len = st.len;
    str = new char [len+1];
    std::strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char *s) {
    delete [] str;
    len = (int)std::strlen(s);
    str = new char [len+1];
    std::strcpy(str, s);
    return *this;
}

char & String::operator[](int i) {
    return str[i];
}

const char & String::operator[](int i) const {
    return str[i];
}

bool operator<(const String &st1, const String &st2) {
    return std::strcmp(st1.str, st2.str) < 0;
}

bool operator>(const String &st1, const String &st2) {
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2) {
    return std::strcmp(st1.str, st2.str) == 0;
}

//ostream & operator<<(ostream & os, const String &st) {
//    os << st.str;
//    return os;
//}

//istream & operator>>(istream & is, String & st) {
////    char temp[String::CINLIM];
//}

/**
 顾客
 */
void Customer::set(long when) {
    // 处理时间为一个随机数
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

/**
 队列
 
 初始化列表：
 只能用于构造函数；
 对于const类成员，必须使用这种语法
 对于声明为引用的类成员，也必须使用这种语法
 Class::Classy(int n, int m) : mem1(n), mem2(0), mem3(n*m + 2) { }
 */
Queue::Queue(int qs) : qsize(qs) {
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue() {
    // 队列销毁时，删除所有的节点
    Node *temp;
    while (front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const {
    return items == 0;
}

bool Queue::isfull() const {
    return items == qsize;
}

int Queue::queuecount() const {
    return items;
}

bool Queue::enqueue(const Item &item) {
    // 队列已满，不能入队
    if (isfull()) {
        std::cout << "Enqueue Queue isfull: " << items << std::endl;
        return false;
    }
    // 创建一个新的节点
    Node *add = new Node;
    // Item 为节点的数据部分
    add->item = item;
    // 由于它是对尾的节点，所以它的下一个节点为空
    add->next = nullptr;
    
    items++;
    // 空队列时，第一次加入，那么队头和队尾都是 add
    if (front == nullptr) {
        front = add;
    } else {
        // 队列中已经有节点了, 直接把队尾的指针指向 add
        /**
         模拟队列，使用单链表数据结构，队列中保存的是 Customer 对象
         
         -----------------------------------------------------------
         <- customer0  | customer1 | customer2 | customer3 | customer4 <--
         -----|------------------------------------------------|------
            front                                             rear
         */
        rear->next = add;
    }
    // 修改队尾的节点
    rear = add;
    
    std::cout << "Enqueue Queue count: " << items << std::endl;
    return true;
}

bool Queue::dequeue(Item &item) {
    // 队列中没有成员，如何删除？
    if (front == nullptr) {
        std::cout << "Dequeue Queue isEmpty: " << items << std::endl;

        return false;
    }
    /**
     -----------------------------------------------------------
     <- customer0  | customer1 | customer2 | customer3 | customer4 <--
     -----|------------------------------------------------|------
        front                                             rear
     出队列，从头开始
     */
    // 将第一个节点给调用者，通过引用传递
    item = front->item;
    items--;
    // 保存头节点，以便删除
    Node *temp = front;
    // 头结点指向下一个节点
    front = front->next;
    // 删除头结点
    delete temp;
    // 如果是最后一个节点，
    if (items == 0) {
        rear = nullptr;
    }
    std::cout << "Dequeue Queue count: " << items << std::endl;
    return true;
}







