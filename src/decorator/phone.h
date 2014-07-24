//
//  phone.h
//  design_pattern
//
//  Created by jack on 14-7-16.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_phone_h
#define design_pattern_phone_h

/**
 *  Component
 */
class Phone
{
public:
    Phone(){}
    virtual ~Phone(){}
    virtual void ShowDecorator()=0;
};

/**
 *  ConcreteComponent
 */
class NokiePhone:public Phone
{
public:
    NokiePhone(std::string name):name_(name){}
    void ShowDecorator(){std::cout<<name_<<"的nokie"<<std::endl;}
private:
    std::string name_;
};

/**
 *  ConcreteComponent
 */
class IPhone:public Phone
{
public:
    IPhone(std::string name):name_(name){}
    void ShowDecorator(){std::cout<<name_<<"的iphone"<<std::endl;}
private:
    std::string name_;
};



#endif
