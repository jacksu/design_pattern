//
//  color.h
//  design_pattern
//
//  Created by jack on 14-7-14.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_color_h
#define design_pattern_color_h

class Color
{
public:
    virtual ~Color(){}
    virtual void BePaint()=0;
};

class RedColor:public Color
{
public:
    void BePaint(){std::cout<<"red color"<<std::endl;}
};

class GreenColor:public Color
{
public:
    void BePaint(){std::cout<<"green color"<<std::endl;}
};

class BlueColor:public Color
{
public:
    void BePaint(){std::cout<<"blue color"<<std::endl;}
};


#endif
