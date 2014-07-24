//
//  builder.h
//  design_pattern
//
//  Created by jack on 14-7-13.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_builder_h
#define design_pattern_builder_h
#include <iostream>

using namespace std;

/**
 *  只是各个部分的实现
 */
class Builder
{
public:
    virtual void BuildHead() {}
    virtual void BuildBody() {}
    virtual void BuildLeftArm(){}
    virtual void BuildRightArm() {}
    virtual void BuildLeftLeg() {}
    virtual void BuildRightLeg() {}
};

/**
 *  构造瘦人
 */
class ThinBuilder : public Builder
{
public:
    void BuildHead() { cout<<"build thin body"<<endl; }
    void BuildBody() { cout<<"build thin head"<<endl; }
    void BuildLeftArm() { cout<<"build thin leftarm"<<endl; }
    void BuildRightArm() { cout<<"build thin rightarm"<<endl; }
    void BuildLeftLeg() { cout<<"build thin leftleg"<<endl; }
    void BuildRightLeg() { cout<<"build thin rightleg"<<endl; }
};

/**
 *  构造胖人
 */
class FatBuilder : public Builder
{
public:
    void BuildHead() { cout<<"build fat body"<<endl; }
    void BuildBody() { cout<<"build fat head"<<endl; }
    void BuildLeftArm() { cout<<"build fat leftarm"<<endl; }
    void BuildRightArm() { cout<<"build fat rightarm"<<endl; }
    void BuildLeftLeg() { cout<<"build fat leftleg"<<endl; }
    void BuildRightLeg() { cout<<"build fat rightleg"<<endl; }
};

#endif