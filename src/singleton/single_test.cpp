//
//  single_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-9.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "single_test.h"

int main(int argc, char **argv)
{
    //Singleton *singleton=new Singleton(); //error
    Singleton *singleton=Singleton::GetInstance();
    singleton->Show();
    return 0;
}