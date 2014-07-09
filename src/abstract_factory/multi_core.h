//
//  multi_core.h
//  design_pattern
//
//  Created by jack on 14-7-8.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_multi_core_h
#define design_pattern_multi_core_h

class MultiCore
{
public:
    virtual void Show() = 0;
};

//多核A
class MultiCoreA: public MultiCore
{
public:
    void Show() { std::cout<<"MultiCore A"<<std::endl; }
};

//多核B
class MultiCoreB: public MultiCore
{
public:
    void Show() { std::cout<<"MultiCore B"<<std::endl; }
};

#endif
