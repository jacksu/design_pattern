//
//  chain_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-23.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "chain_test.h"

int main(int argc, char **argv)
{
    Manager *common=new CommonManager("A");
    Manager *major=new Majordomo("B");
    Manager *general=new GeneralManager("C");
    common->AddHandler(major);
    common->AddHandler(general);
    common->HandleRequest("request", 100);
    common->HandleRequest("request", 600);
    common->HandleRequest("request", 1000);
    common->HandleRequest("request", 10000);
    delete general;
    delete major;
    delete common;
    return 0;
}