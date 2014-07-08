//
//  factory_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-8.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "factory_test.h"

int main(int argc, char **argv)
{
    SingleCore *singleA=Factory::CreateSingleCore(COREA);
    SingleCore *singleB=Factory::CreateSingleCore(COREB);
    singleA->Show();
    singleB->Show();
    return 0;
}