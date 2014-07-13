//
//  single_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-9.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "single_test.h"
#include "single_template.h"


class Test
{
public:
    void Show(){std::cout<<"in Test"<<std::endl;}
};


int main(int argc, char **argv)
{
    //Singleton *singleton=new Singleton(); //error
    Singleton *singleton=Singleton::GetInstance();
    singleton->Show();
    Test *test=singleton::Instance<Test>();
    test->Show();
    return 0;
}