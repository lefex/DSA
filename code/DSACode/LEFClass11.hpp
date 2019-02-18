//
//  LEFClass11.hpp
//  DSACode
//
//  Created by Wang,Suyan on 2019/2/17.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

/**
 第11章 使用类
 运算符重载
 友元函数
 重载<<运算符，以便于输出
 
 ========================
 状态成员
 使用rand()生成随机值；
 类的自动转换和强制转换；主要介绍了对象直接的类型转换，比如可以把一个double类型的变量转换成对象；
 类转换函数；
 */


#ifndef LEFClass11_hpp
#define LEFClass11_hpp

#include <stdio.h>
#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    // 参数是引用，但是返回值不是引用
    Time Sum(const Time & t) const;
    /**
     重载运算符，语法为：
     operator op(参数列表)
     只能重载已经存在的运算符，比如+、-、*，而不能重载@
     Time coding(2, 40);
     Time fixing(5, 55);
     Time sum;
     也可以通过 sum = coding.operator+(fixing); 这样的方式调用；
     【规则】：
     1、必须由一个操作数是自定义类型；
     2、使用运算符时不能违反运算符原来的句法规则，也不能修改运算符的优先级，比如不能 %x；
     3、不能创建新的运算符；
     4、不能重载特点的运算符，比如：sizeof
     */
    Time operator+(const Time & t) const;
    /**
     使用非成员函数重载运算符需要两个参数，而使用成员函数重载需要一个参数，因为
     其中一个参数可以通过 this 访问。
     【使用友元函数进行重载】
     friend Time operator+(const Time & t1, const Time & t2);
     */

    Time operator-(const Time & t) const;
    // time * 1.2
    Time operator*(double n) const;
    
    /**
     友元：
     提供了一种访问私有成员的方法，我们都知道访问私有成员只能通过成员函数访问。典型的是
     非成员函数无法访问私有变量。有一种特殊的非成员函数可以访问私有变量，它们就是【友元函数】。
     1.2 * time
     */
    friend Time operator*(double m, const Time & t);
    /**
     重载符号 <<:
     cout << adjust << ", the end";
     */
    friend std::ostream & operator<<(std::ostream & os, const Time & t);

    void Show() const;
};

/**
 定义一个向量
 */
namespace VECTOR {
    class Vector {
    public:
        // 定义枚举值，在类中可以作为常量定义
        enum Mode {RECT, POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        /**
         下面4个函数由于在类声明中定义的，所以自动成为了内联函数
         */
        double xval() { return x;};
        double yval() { return y;};
        double magval() { return mag;};
        double angval() { return ang;};
        
        void polar_mode();
        void rect_mode();
        
        /**
         重载运算符
         */
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
}

#endif /* LEFClass11_hpp */
