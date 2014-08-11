//
//  mediator.h
//  design_pattern
//
//  Created by jack on 14-8-5.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_mediator_h
#define design_pattern_mediator_h

class Mediator;

/**
 *  抽象人
 */
class Person
{
protected:
    Mediator *mediator_; //中介
public:
    virtual ~Person(){}
    virtual void SetMediator(Mediator *mediator){} //设置中介
    virtual void SendMessage(std::string message) {}    //向中介发送信息
    virtual void GetMessage(std::string message) {}     //从中介获取信息
};

/**
 *  抽象中介机构
 */
class Mediator
{
public:
    virtual ~Mediator(){}
    virtual void Send(std::string message, Person *person) {}
    virtual void SetA(Person *A) {}  //设置其中一方
    virtual void SetB(Person *B) {}
};

/**
 *  租房者
 */
class Renter: public Person
{
public:
    void SetMediator(Mediator *mediator) { mediator_ = mediator; }
    void SendMessage(std::string message) { mediator_->Send(message, this); }
    void GetMessage(std::string message) { std::cout<<"租房者收到信息"<<message; }
};

/**
 *  房东
 */
class Landlord: public Person
{
public:
    void SetMediator(Mediator *mediator) { mediator_ = mediator; }
    void SendMessage(std::string message) { mediator_->Send(message, this); }
    void GetMessage(std::string message) { std::cout<<"房东收到信息："<<message; }
};

/**
 *  房屋中介
 */
class HouseMediator : public Mediator
{
private:
    Person *renter_; //租房者
    Person *landlord_; //房东
public:
    HouseMediator(): renter_(0), landlord_(0) {}
    void SetA(Person *renter) { renter_ = renter; }
    void SetB(Person *landlord) { landlord_ = landlord; }
    void Send(std::string message, Person *person)
    {
        if(person == renter_) //租房者给房东发信息
            landlord_->GetMessage(message); //房东收到信息
        else
            renter_->GetMessage(message);
    }
};

#endif
