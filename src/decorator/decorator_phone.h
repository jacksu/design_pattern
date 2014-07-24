//
//  decorator_phone.h
//  design_pattern
//
//  Created by jack on 14-7-16.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_decorator_phone_h
#define design_pattern_decorator_phone_h
#include "phone.h"

/**
 *  Decorator
 */
class DecoratorPhone:public Phone
{
public:
    DecoratorPhone(Phone *phone):phone_(phone){}
    virtual ~DecoratorPhone(){}
    virtual void ShowDecorator(){phone_->ShowDecorator();}
private:
    Phone *phone_;
};

/**
 *  Concrete Decorator
 */
class DecoratorPhoneA:public DecoratorPhone
{
public:
    DecoratorPhoneA(Phone *phone):DecoratorPhone(phone){}
    void ShowDecorator(){DecoratorPhone::ShowDecorator();AddDecorator();}
private:
    void AddDecorator(){std::cout<<"添加装饰"<<std::endl;}
};


/**
 *  Concrete Decorator
 */
class DecoratorPhoneB:public DecoratorPhone
{
public:
    DecoratorPhoneB(Phone *phone):DecoratorPhone(phone){}
    void ShowDecorator(){DecoratorPhone::ShowDecorator();AddDecorator();}
private:
    void AddDecorator(){std::cout<<"添加屏幕保护膜"<<std::endl;}
};

#endif
