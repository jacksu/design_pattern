//
//  decorator_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-16.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "decorator_test.h"

int main(int argv, char** argc)
{
    Phone *nokie=new NokiePhone("jack");
    Phone *iphone=new IPhone("jacksu");
    DecoratorPhone *da=new DecoratorPhoneA(nokie);
    DecoratorPhone *db=new DecoratorPhoneB(iphone);
    da->ShowDecorator();
    db->ShowDecorator();
    delete nokie;
    delete iphone;
    delete da;
    delete db;
    return 0;
}