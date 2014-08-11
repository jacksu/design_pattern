//
//  template_method.h
//  design_pattern
//
//  Created by jack on 14-8-10.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_template_method_h
#define design_pattern_template_method_h

class AbstractBank
{
public:
    virtual ~AbstractBank(){}
    void TakeNumber(){std::cout<<"取号"<<std::endl;}
    virtual void Doit()=0;
    void Remark(){std::cout<<"评分"<<std::endl;}
    void Excute()
    {
        TakeNumber();
        Doit();
        Remark();
    }
};

class Deposit:public AbstractBank
{
public:
    void Doit(){std::cout<<"存款"<<std::endl;}
};
        
class Withdraw:public AbstractBank
{
public:
    void Doit(){std::cout<<"取钱"<<std::endl;}
};

#endif
