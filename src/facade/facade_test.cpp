//
//  facade_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-16.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "facade_test.h"

int main(int argv, char** argc)
{
    Compiler *compiler=new Compiler();
    compiler->Run();
    delete compiler;
    return 0;
}