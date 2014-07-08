//
//  factory.h
//  design_pattern
//
//  Created by jack on 14-7-7.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_factory_h
#define design_pattern_factory_h
#include "single_core.h"

//唯一的工厂，可以生产两种型号的处理器核，在内部判断
class Factory
{
public:
    static SingleCore* CreateSingleCore(enum CTYPE ctype)
    {
        if(ctype == COREA) //工厂内部判断
            return new SingleCoreA(); //生产核A
        else if(ctype == COREB)
            return new SingleCoreB(); //生产核B
        else
            return NULL;
    }
};

#endif
