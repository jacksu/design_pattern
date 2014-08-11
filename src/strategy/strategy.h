//
//  strategy.h
//  design_pattern
//
//  Created by jack on 14-8-10.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_strategy_h
#define design_pattern_strategy_h

class Strategy
{
public:
    virtual ~Strategy(){}
    virtual void Travel(){};
};

class Person
{
public:
    void SetStrategy(Strategy *strategy){strategy_=strategy;}
    void Travel(){strategy_->Travel();}
private:
    Strategy *strategy_;
};


class AirplaneStrategy: public Strategy
{
    void Travel(){std::cout<<"in airplane"<<std::endl;}
};

class TrainStrategy: public Strategy
{
    void Travel(){std::cout<<"in train"<<std::endl;}
};

class BicycleStrategy: public Strategy
{
    void Travel(){std::cout<<"in bicycle"<<std::endl;}
};
#endif
