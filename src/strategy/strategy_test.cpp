//
//  strategy_test.cpp
//  design_pattern
//
//  Created by jack on 14-8-10.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "strategy_test.h"

int main()
{
    Strategy *strategy=new TrainStrategy();
    Person *person=new Person();
    person->SetStrategy(strategy);
    person->Travel();
    delete person;
    delete strategy;
    return 0;
}