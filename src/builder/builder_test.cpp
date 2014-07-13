//
//  builder_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-13.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "builder_test.h"

int main(int argc, char **argv)
{
    ThinBuilder thin;
    Director *director=new Director();
    director->Create(&thin);
    return 0;
}