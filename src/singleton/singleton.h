//
//  singleton.h
//  design_pattern
//
//  Created by jack on 14-7-8.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_singleton_h
#define design_pattern_singleton_h

//单例基本实现，但线程不安全
class Singleton
{
public:
    static Singleton* GetInstance();
    void Show(){std::cout<<"in singleton"<<std::endl;}
protected:
    //设置为protected，防止误用调用构造函数生成singleton对象
    Singleton() {}
private:
    //禁止用户使用拷贝构造函数和赋值操作符
    Singleton(Singleton &singleton){}
    const Singleton& operator=(const Singleton &singleton);
    
    static Singleton *singleton;
};


Singleton* Singleton::singleton = NULL;
Singleton* Singleton::GetInstance()
{
    if(singleton == NULL)
        singleton = new Singleton();
    return singleton;
}

#endif
