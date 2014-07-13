//
//  prototype_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-13.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "prototype_test.h"
int main(int argc, char **argv)
{
    ResumeProto *resume=new Resume("test");
    ResumeProto *clone=resume->Clone();
    clone->SetName("B");
    resume->Show();
    clone->Show();
    delete resume;
    resume=NULL;
    clone->Show();
    return 0;
}