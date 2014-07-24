//
//  adapter_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-16.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "adapter_test.h"

int main(int argv, char** argc)
{
    Sequence *stack=new Stack();
    Sequence *queue=new Queue();
    stack->push(1);
    stack->pop();
    queue->push(1);
    queue->pop();
    return 0;
}