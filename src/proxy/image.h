//
//  image.h
//  design_pattern
//
//  Created by jack on 14-7-22.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_image_h
#define design_pattern_image_h

/**
 *  虚代理
 */

class Image
{
public:
    Image(std::string &name): image_name_(name) {}
    virtual ~Image() {}
    virtual void Show() {}
protected:
    std::string image_name_;
};

/**
 *  real subject
 */
class BigImage: public Image
{
public:
    BigImage(std::string name):Image(name) {}
    ~BigImage() {}
    void Show() { std::cout<<"Show big image : "<<image_name_<<std::endl; }
};

/**
 *  proxy subject
 */
class BigImageProxy: public Image
{
private:
    BigImage *big_image_;
public:
    BigImageProxy(std::string name):Image(name),big_image_(0) {}
    ~BigImageProxy() { delete big_image_; }
    void Show()
    {
        if(big_image_ == NULL)
            big_image_ = new BigImage(image_name_);
        big_image_->Show();
    }
};

#endif
