//
//  observer.h
//  design_pattern
//
//  Created by jack on 14-8-7.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_observer_h
#define design_pattern_observer_h
#include <list>

/**
 *  观察者
 */
class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void Update() {}
};

/**
 *  subject
 */
class Blog
{
public:
    Blog() {}
    virtual ~Blog()
    {
        std::list<Observer*>::iterator iter = observers_.begin();
        for(; iter != observers_.end(); iter++)
            delete (*iter);
        observers_.clear();
    }
    void Attach(Observer *observer) { observers_.push_back(observer); }     //添加观察者
    void Remove(Observer *observer) { observers_.remove(observer); }        //移除观察者
    void Notify() //通知观察者
    {
        std::list<Observer*>::iterator iter = observers_.begin();
        for(; iter != observers_.end(); iter++)
            (*iter)->Update();
    }
    virtual void SetStatus(std::string s) { status_ = s; } //设置状态
    virtual std::string GetStatus() { return status_; }    //获得状态
private:
    std::list<Observer* > observers_; //观察者链表
protected:
    std::string status_; //状态
};

//具体博客类
class BlogCSDN : public Blog
{
private:
    std::string name_; //博主名称
public:
    BlogCSDN(std::string name): name_(name) {}
    ~BlogCSDN() {}
    void SetStatus(std::string s) { status_ = "CSDN通知 : " + name_ + s; Notify();} //具体设置状态信息
    std::string GetStatus() { return status_; }
};
//具体观察者
class ObserverBlog : public Observer
{
private:
    std::string name_;  //观察者名称
    Blog *blog_;   //观察的博客，当然以链表形式更好，就可以观察多个博客
public:
    ObserverBlog(std::string name,Blog *blog): name_(name), blog_(blog) {}
    ~ObserverBlog() {}
    void Update()  //获得更新状态
    {
        std::string status = blog_->GetStatus();
        std::cout<<name_<<"-------"<<status<<std::endl;
    }
};
#endif
