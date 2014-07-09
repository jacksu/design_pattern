//
//  abstract_factory_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-8.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "abstract_factory_test.h"

int main(int argc, char **argv)
{
    Factory *factoryA=new FactoryA();
    Factory *factoryB=new FactoryB();
    SingleCore *singleA=factoryA->CreateSingleCore();
    MultiCore *multiA=factoryA->CreateMultiCore();
    SingleCore *singleB=factoryB->CreateSingleCore();
    MultiCore *multiB=factoryB->CreateMultiCore();
    singleA->Show();
    singleB->Show();
    multiA->Show();
    multiB->Show();
    return 0;
}