//
//  visitor_test.cpp
//  design_pattern
//
//  Created by jack on 14-8-11.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "visitor_test.h"

int main()
{
    Color *set[] =
    {
        new Red, new Blu, new Blu, new Red, new Red, 0
    };
    //Client creates "visitor" objects
    CountVisitor count_operation;
    CallVisitor call_operation;
    //passes each to accept() calls
    for (int i = 0; set[i]; i++)
    {
        set[i]->accept(&count_operation);
        set[i]->accept(&call_operation);
    }
    count_operation.report_num();
}