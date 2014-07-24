//
//  bridge_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-14.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "bridge_test.h"

int main(int argc, char** argv)
{
    Color *red=new RedColor();
    Color *green=new GreenColor();
    Color *blue=new BlueColor();
    BrushPen *big=new BigBrushPen();
    BrushPen *small=new SmallBrushPen();
    big->SetColor(red);
    small->SetColor(green);
    big->Draw();
    small->Draw();
    big->SetColor(blue);
    big->Draw();
    delete red;
    delete green;
    delete blue;
    delete big;
    delete small;
    return 0;
}