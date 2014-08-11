//
//  observer_test.cpp
//  design_pattern
//
//  Created by jack on 14-8-7.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "observer_test.h"
int main()
{
    Blog *blog = new BlogCSDN("jacksu");
    Observer *observer1 = new ObserverBlog("observer1", blog);
    Observer *observer2 = new ObserverBlog("observer2", blog);
    blog->Attach(observer1);
    blog->Attach(observer2);
    blog->SetStatus("发表设计模式observer");
    delete blog;
    return 0;
}