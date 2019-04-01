//
//  polinom.cpp
//  lab1
//
//  Created by MacBook Pro on 2/22/19.
//  Copyright © 2019 MacBook Pro. All rights reserved.
//

#include "polinom.h"
#include "cmath"
TPolinom::TPolinom(number x,number y,number z)
{
    a = x;
    b = y;
    c = z;
}

number TPolinom::value(number x)
{
    return (a*x*x+b*x+c);
}

int TPolinom::roots(number* x)
{
    int ret = 0;
    number determ = b*b-4*a*c;
    if(a==0)
    {
        x[0] = -c/b;
        ret = 1;
    }
    
    else if (determ == 0)
    {
        x[0] = (-b)/(2*a);
        ret = 1;
    }
    else if (determ > 0)
    {
        x[0] = (-b+sqrt(determ))/(2*a);
        x[1] = (-b-sqrt(determ))/(2*a);
        ret = 2;
    }
    else ret = 0;
    
    return ret;
}

std::ostream& operator<<(std::ostream& os, TPolinom& p)
{

    os<<std::endl << "p(x) = " << p.a << "x^2";
    
    if (p.b<0) os<<p.b<<"x";
    else os<<"+"<<p.b<<"x";
    
    if (p.c<0) os<<p.c;
    else os<<"+"<<p.c;
    //...
    return os;
}
