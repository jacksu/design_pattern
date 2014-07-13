//
//  prototype.h
//  design_pattern
//
//  Created by jack on 14-7-13.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_prototype_h
#define design_pattern_prototype_h

using namespace std;

/**
 *  简历我们可能只需要修改一下名字就好了
 */
class ResumeProto
{
public:
    ResumeProto(){}
    virtual ~ResumeProto(){}
    virtual ResumeProto * Clone()=0;
    virtual void SetName(char *name)=0;
    virtual void Show()=0;
protected:
    char *name_;
    int name_len_;
};

class Resume: public ResumeProto
{
public:
    Resume(const char *name);
    ~Resume();
    /**
     *  采用的深拷贝
     */
    Resume(const Resume &r);
    Resume * Clone();
    /**
     *  改变名字
     *
     *  @param name 名字
     */
    void SetName(char *name);
    void Show();
};


Resume::Resume(const char *name):ResumeProto()
{
    if(name == NULL) {
        name_ = new char[1];
        name_[0] = '\0';
        name_len_=1;
    }
    else {
        name_ = new char[strlen(name)+1];
        name_len_=strlen(name)+1;
        strcpy(name_, name);
    }
}

Resume::~Resume() { delete [] name_;}

Resume::Resume(const Resume &r) {
    name_ = new char[strlen(r.name_)+1];
    strcpy(name_, r.name_);
}

Resume* Resume::Clone() {
    return new Resume(*this);
}

void Resume::SetName(char *name)
{
    if (strlen(name)>=name_len_) {
        name_len_=strlen(name)+1;
        name_=(char *)realloc(name_,name_len_);
        strcpy(name_,name);
    }else{
        strcpy(name_,name);
    }
}

void Resume::Show() {
    cout<<"Resume name : "<<name_<<endl;
}
#endif
