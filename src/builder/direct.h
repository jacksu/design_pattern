//
//  direct.h
//  design_pattern
//
//  Created by jack on 14-7-13.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_direct_h
#define design_pattern_direct_h
#include "builder.h"

/**
 *  根据各个部分，按照一定规则构造实体
 */
class Director
{
public:
    void Create(Builder *builder){
        builder->BuildHead();
        builder->BuildBody();
        builder->BuildLeftArm();
        builder->BuildRightArm();
        builder->BuildLeftLeg();
        builder->BuildRightLeg();
    }
};

#endif
