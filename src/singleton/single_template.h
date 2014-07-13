//
//  single_template.h
//  design_pattern
//
//  Created by jack on 14-7-10.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_single_template_h
#define design_pattern_single_template_h

/**
 *  模版函数实现单例
 */
namespace singleton{
    
    template <class T> T* Instance()
    {
        static T instance;
        return &instance;
    }
}


#endif
