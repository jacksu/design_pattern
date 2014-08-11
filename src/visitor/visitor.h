//
//  visitor.h
//  design_pattern
//
//  Created by jack on 14-8-11.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_visitor_h
#define design_pattern_visitor_h

/**
 *  1. Add an accept(Visitor) method to the "element" hierarchy
 */

class Color
{
public:
    virtual void accept(class Visitor*) = 0;
};

class Red: public Color
{
public:
    void accept(Visitor* v);
    void eye()
    {
        std::cout << "Red::eye\n";
    }
};
class Blu: public Color
{
public:
    void accept(Visitor* v);
    void sky()
    {
        std::cout << "Blu::sky\n";
    }
};

/**
 *  2. Create a "visitor" base class w/ a visit() method for every "element" type
 */
class Visitor
{
public:
    virtual void visit(Red*) = 0;
    virtual void visit(Blu*) = 0;
};

class CountVisitor: public Visitor
{
public:
    CountVisitor()
    {
        red_num_ = blue_num_ = 0;
    }
    /*virtual*/void visit(Red*)
    {
        ++red_num_;
    }
    /*virtual*/void visit(Blu*)
    {
        ++blue_num_;
    }
    void report_num()
    {
        std::cout << "Reds " << red_num_ << ", Blus " << blue_num_ << '\n';
    }
private:
    int red_num_, blue_num_;
};

/**
 *  3. Create a "visitor" derived class for each "operation" to do on "elements"
 */
class CallVisitor: public Visitor
{
public:
    /*virtual*/void visit(Red *r)
    {
        r->eye();
    }
    /*virtual*/void visit(Blu *b)
    {
        b->sky();
    }
};

void Red::accept(Visitor *v)
{
    v->visit(this);
}

void Blu::accept(Visitor *v)
{
    v->visit(this);
}

#endif
