//
//  manager_chain.h
//  design_pattern
//
//  Created by jack on 14-7-23.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_manager_chain_h
#define design_pattern_manager_chain_h

/**
 *  是一个请求加薪的实例，通过经理、总监、总经理处理，也有可能不处理
 */

/**
 * 抽象管理者，基类
 */
class Manager
{
protected:
    /**
     *  "next" pointer in the base class
     */
    Manager *next_;
    std::string name_;
public:
    Manager(std::string name):next_(NULL), name_(name){}
    virtual ~Manager(){}
    void SetNext(Manager *n)
    {
        next_ = n;
    }
    void AddHandler(Manager *n)
    {
        if (next_)
            next_->AddHandler(n);
        else
            next_ = n;
    }
    /**
     *  基类中的处理方法总是委托给next_对象来处理
     *
     *  @param name 请求人的姓名
     *  @param num  加薪数
     */
    virtual void HandleRequest(std::string name, int num)
    {
        next_->HandleRequest(name, num);
    }
};

/**
 *  handler one 经理
 */
class CommonManager: public Manager
{
public:
    CommonManager(std::string name):Manager(name) {}
    void HandleRequest(std::string name, int num)
    {
        if(num < 500) //经理职权之内
        {
            std::cout<<"经理"<<name_<<"批准"<<name<<"加薪"<<num<<"元"<<std::endl<<std::endl;
        }
        else
        {
            /**
             *  委托给基类处理
             */
            std::cout<<"经理"<<name_<<"无法处理，交由总监处理"<<std::endl;
            Manager::HandleRequest(name, num);
        }
    }
};

/**
 *  handle two 总监
 */
class Majordomo: public Manager
{
public:
    Majordomo(std::string name):Manager(name) {}
    void HandleRequest(std::string name, int num)
    {
        if(num < 1000) //总监职权之内
        {
            std::cout<<"总监"<<name_<<"批准"<<name<<"加薪"<<num<<"元"<<std::endl<<std::endl;
        }
        else
        {
            std::cout<<"总监"<<name_<<"无法处理，交由总经理处理"<<std::endl;
            /**
             *  委托基类处理
             */
            Manager::HandleRequest(name, num);
        }
    }
};

/**
 *  handle three 总经理
 */
class GeneralManager: public Manager
{
public:
    GeneralManager(std::string name):Manager(name) {}
    void HandleRequest(std::string name, int num)
    {
        if (num < 10000)
        {
            
            std::cout<<"总经理"<<name_<<"批准"<<name<<"加薪"<<num<<"元"<<std::endl<<std::endl;
        }
        else
        {
            std::cout<<"不批准"<<name<<"加薪"<<num<<"元的请求"<<std::endl;
        }
    }
};

#endif
