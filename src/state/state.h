//
//  state.h
//  design_pattern
//
//  Created by jack on 14-8-10.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_state_h
#define design_pattern_state_h

class War;
class State
{
public:
    virtual ~State(){}
    virtual void Prophase(War *war) {}
    virtual void Metaphase(War *war) {}
    virtual void Anaphase(War *war) {}
    virtual void End(War *war) {}
    virtual void CurrentState(War *war) {}
};

//战争
class War
{
private:
    State *state_;  //目前状态
    int days_;      //战争持续时间
public:
    War(State *state): state_(state), days_(0) {}
    ~War() { delete state_; }
    int GetDays() { return days_; }
    void SetDays(int days) { days_ = days; }
    void SetState(State *state) { delete state_; state_ = state; }
    void GetState() { state_->CurrentState(this); }
};

//战争结束
class EndState: public State
{
public:
    void End(War *war) //结束阶段的具体行为
    {
        std::cout<<"战争结束"<<std::endl;
    }
    void CurrentState(War *war) { End(war); }
};
//后期
class AnaphaseState: public State
{
public:
    void Anaphase(War *war) //后期的具体行为
    {
        if(war->GetDays() < 30)
            std::cout<<"第"<<war->GetDays()<<"天：战争后期，双方拼死一搏"<<std::endl;
        else
        {
            war->SetState(new EndState());
            war->GetState();
        }
    }
    void CurrentState(War *war) { Anaphase(war); }
};
//中期
class MetaphaseState: public State
{
public:
    void Metaphase(War *war) //中期的具体行为
    {
        if(war->GetDays() < 20)
            std::cout<<"第"<<war->GetDays()<<"天：战争中期，进入相持阶段，双发各有损耗"<<std::endl;
        else
        {
            war->SetState(new AnaphaseState());
            war->GetState();
        }
    }
    void CurrentState(War *war) { Metaphase(war); }
};
//前期
class ProphaseState: public State
{
public:
    void Prophase(War *war)  //前期的具体行为
    {
        if(war->GetDays() < 10)
            std::cout<<"第"<<war->GetDays()<<"天：战争初期，双方你来我往，互相试探对方"<<std::endl;
        else
        {
            war->SetState(new MetaphaseState());
            war->GetState();
        }
    }
    void CurrentState(War *war) { Prophase(war); }
};

#endif
