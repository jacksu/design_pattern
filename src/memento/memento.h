//
//  memento.h
//  design_pattern
//
//  Created by jack on 14-8-6.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_memento_h
#define design_pattern_memento_h

class Number;

class Memento
{
public:
    Memento(int val)
    {
        state_ = val;
    }
private:
    friend class Number; // not essential
    int state_;
};


/**
 *  originator
 */
class Number
{
public:
    Number(int value)
    {
        value_ = value;
    }
    void dubble()
    {
        value_ = 2 * value_;
    }
    void half()
    {
        value_ = value_ / 2;
    }
    int getValue()
    {
        return value_;
    }
    Memento *createMemento()
    {
        return new Memento(value_);
    }
    void reinstateMemento(Memento *mem)
    {
        value_ = mem->state_;
    }
private:
    int value_;
};

/**
 *  caretaker
 */
class Command
{
public:
    typedef void(Number:: *Action)();
    Command(Number *receiver, Action action)
    {
        receiver_ = receiver;
        action_ = action;
    }
    virtual void execute()
    {
        mementoList_[numCommands_] = receiver_->createMemento();
        commandList_[numCommands_] = this;
        if (numCommands_ > highWater_)
            highWater_ = numCommands_;
        numCommands_++;
        (receiver_->*action_)();
    }
    static void undo()
    {
        if (numCommands_ == 0)
        {
            std::cout << "*** Attempt to run off the end!! ***" << std::endl;
            return ;
        }
        numCommands_--;
        commandList_[numCommands_]->receiver_->reinstateMemento
        (mementoList_[numCommands_]);
    }
    void static redo()
    {
        if (numCommands_ > highWater_)
        {
            std::cout << "*** Attempt to run off the end!! ***" << std::endl;
            return ;
        }
        
        (commandList_[numCommands_]->receiver_->*(commandList_[numCommands_]
                                                  ->action_))();
        numCommands_++;
    }
protected:
    Number *receiver_;
    Action action_;
    static Command *commandList_[20];
    static Memento *mementoList_[20];
    static int numCommands_;
    static int highWater_;
};

Command *Command::commandList_[];
Memento *Command::mementoList_[];
int Command::numCommands_ = 0;
int Command::highWater_ = 0;

#endif
