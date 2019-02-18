//
//  LEFClass11.cpp
//  DSACode
//
//  Created by Wang,Suyan on 2019/2/17.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//



#include "LEFClass11.hpp"
#include <iostream>

Time::Time() {
    hours = 0;
    minutes = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h) {
    hours += h;
}

void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time &t) const {
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double n) const {
    Time result;
    int totalMin = hours * n * 60 + minutes * n;
    result.hours = totalMin / 60;
    result.minutes = totalMin % 60;
    return result;
}

Time operator*(double m, const Time & t) {
    Time result;
    // 因为是友元函数，可以访问私有成员
    int totalMin = t.hours * m * 60 + t.minutes * m;
    result.hours = totalMin / 60;
    result.minutes = totalMin % 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t) {
    os << t.hours << " hours:," << t.minutes << " sminutes";
    // 返回 os 是为了可以使用 cout << adjust << ", the end";
    return os;
}

void Time::Show() const {
    std::cout << hours << " hours:," << minutes << " minutes";
}

#include <cmath>
using std:: sqrt;
using std:: sin;
using std:: cos;
using std:: atan;
using std:: atan2;
using std:: cout;

namespace VECTOR {
    const double Rad_to_deg = 45.0 / atan(1.0);
    
    void Vector::set_mag() {
        mag = sqrt(x * x + y * y);
    }
    
    void Vector::set_ang() {
        if (x == 0.0 && y == 0.0) {
            ang = 0.0;
        } else {
            ang = atan2(y, x);
        }
    }
    
    void Vector::set_x() {
        x = mag * cos(ang);
    }
    
    void Vector::set_y() {
        y = mag * sin(ang);
    }
    
    Vector::Vector() {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
    
    Vector::Vector(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if (form == POL) {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else {
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    
    void Vector::reset(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if (form == POL) {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else {
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    
    Vector::~Vector() {
        
    }
    
    void Vector::polar_mode() {
        mode = POL;
    }
    
    void Vector::rect_mode() {
        mode = RECT;
    }
    
    Vector Vector::operator+(const Vector &b) const {
        return Vector(x + b.x, y + b.y);
    }
    
    Vector Vector::operator-(const Vector &b) const {
        return Vector(x - b.x, y - b.y);
    }
    
    Vector Vector::operator-() const {
        return Vector(-x, -y);
    }
    
    Vector Vector::operator*(double n) const {
        // 仅支持 vector * 1.2 这样的形式，不支持 1.2 * vector 这样的形式
        return Vector(n * x, n * y);
    }
    
    Vector operator*(double n, const Vector & a) {
        // 直接调用已经重载的函数，operator*
        return a * n;
    }
    
    std::ostream & operator<<(std::ostream & os, const Vector & v) {
        if (v.mode == Vector::RECT) {
            os << "RECT";
        } else if (v.mode == Vector::POL) {
            os << "POL";
        } else {
            os << "Mode is error";
        }
        return os;
    }
}
