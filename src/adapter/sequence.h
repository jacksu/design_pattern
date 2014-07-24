//
//  sequence.h
//  design_pattern
//
//  Created by jack on 14-7-16.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_sequence_h
#define design_pattern_sequence_h

/**
 *  已经有一个双端队列，我们需要一个Sequence的接口，那么就需要一个adapter
 */

/**
 *  target
 */

class Sequence
{
public:
    virtual void push(int x)=0;
    virtual void pop()=0;
};

/**
 *  adaptee
 */
class Deque
{
public:
    void push_back(int x){std::cout<<"push_back"<<std::endl;}
    void pop_back(){std::cout<<"pop_back"<<std::endl;}
    void push_front(int x){std::cout<<"push_front"<<std::endl;}
    void pop_front(){std::cout<<"pop_front"<<std::endl;}
};

/**
 *  adapter
 */
class Stack:public Sequence
{
public:
    void push(int x){deque_.push_back(x);}
    void pop(){deque_.pop_back();}
private:
    Deque deque_;
};

/**
 *  adapter
 */
class Queue:public Sequence
{
public:
    void push(int x){deque_.push_back(x);}
    void pop(){deque_.pop_front();}
private:
    Deque deque_;
};

#endif
