//
//  company.h
//  design_pattern
//
//  Created by jack on 14-7-16.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_company_h
#define design_pattern_company_h
#include <list>

/**
 *  component
 */
class Company
{
public:
    Company(std::string name):name_(name){}
    virtual ~Company(){}
    virtual void Add(Company *company){}
    virtual void Show(int dep)=0;
protected:
    std::string name_;
};

/**
 *  Leaf
 */
class FinanceDepartment:public Company
{
public:
    FinanceDepartment(std::string name):Company(name){}
    void Show(int dep)
    {
        for(int i=0;i<dep;i++)
            std::cout<<"-";
        std::cout<<name_<<std::endl;
    }

};

/**
 *  Leaf
 */
class HRDepartment:public Company
{
public:
    HRDepartment(std::string name):Company(name){}
    void Show(int dep)
    {
        for(int i=0;i<dep;i++)
            std::cout<<"-";
        std::cout<<name_<<std::endl;
    }
};

/**
 *  Composite
 */
class ConcreteCompany : public Company
{
public:
    ConcreteCompany(std::string name): Company(name) {}
    virtual ~ConcreteCompany()
    {
        std::list<Company *>::iterator it=company_list_.begin();
        for (; it!=company_list_.end(); it++)
        {
            delete *it;
        }
        company_list_.clear();
    }
    void Add(Company *company) { company_list_.push_back(company); } //位于树的中间，可以增加子树
    void Show(int depth)
    {
        for(int i = 0;i < depth; i++)
            std::cout<<"-";
        std::cout<<name_<<std::endl;
        std::list<Company *>::iterator iter=company_list_.begin();
        for(; iter != company_list_.end(); iter++) //显示下层结点
            (*iter)->Show(depth + 2);
    }
private:
    std::list<Company *> company_list_;
};
#endif
