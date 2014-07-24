//
//  proxy_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-22.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "proxy_test.h"

int main(int argv, char** argc)
{
    /**
     *  虚代理
     */
    std::string image_name="proxy.jpg";
    Image *image=new BigImageProxy(image_name);//代理
    image->Show();//需要时代理负责调用真实subject
    return 0;
}