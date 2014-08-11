//
//  template_method_test.cpp
//  design_pattern
//
//  Created by jack on 14-8-10.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "template_method_test.h"

int main()
{
    AbstractBank *bank=new Deposit();
    bank->Excute();
    delete bank;
    bank=new Withdraw();
    bank->Excute();
    delete bank;
    return 0;
}