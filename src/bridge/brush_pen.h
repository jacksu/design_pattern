//
//  brush_pen.h
//  design_pattern
//
//  Created by jack on 14-7-14.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_brush_pen_h
#define design_pattern_brush_pen_h
#include "color.h"

/**
 *  一共有两种毛笔，只需要实现2+3个类，就可以实现2*3个实例
 */
class BrushPen
{
public:
    virtual ~BrushPen(){}
    virtual void SetColor(Color *color){color_=color;}
    virtual void Draw()=0;
    
protected:
    Color *color_;
};

class BigBrushPen: public BrushPen
{
public:
    void Draw(){std::cout<<"Big Brush: ";color_->BePaint();}
};

class SmallBrushPen: public BrushPen
{
public:
    void Draw(){std::cout<<"Small Brush: ";color_->BePaint();}
};

#endif
