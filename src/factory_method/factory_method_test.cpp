//
//  factory_method_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-8.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "factory_method_test.h"
int main(int argc, char **argv)
{
    Factory *factoryA=new FactoryA();
    Factory *factoryB=new FactoryB();
    SingleCore *singleA=factoryA->CreateSingleCore();
    SingleCore *singleB=factoryB->CreateSingleCore();
    singleA->Show();
    singleB->Show();
    return 0;
}