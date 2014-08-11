//
//  state_test.cpp
//  design_pattern
//
//  Created by jack on 14-8-10.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "state_test.h"
//测试案例
int main()
{
    War *war = new War(new ProphaseState());
    for(int i = 1; i < 40;i += 5)
    {
        war->SetDays(i);
        war->GetState();
    }
    delete war;
    return 0;
}