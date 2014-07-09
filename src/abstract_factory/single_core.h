//
//  single_core.h
//  design_pattern
//
//  Created by jack on 14-7-8.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_single_core_h
#define design_pattern_single_core_h
#include <iostream>

class SingleCore
{
public:
    virtual void Show() = 0;
};

//单核A
class SingleCoreA: public SingleCore
{
public:
    void Show() { std::cout<<"SingleCore A"<<std::endl; }
};

//单核B
class SingleCoreB: public SingleCore
{
public:
    void Show() { std::cout<<"SingleCore B"<<std::endl; }
};

#endif
