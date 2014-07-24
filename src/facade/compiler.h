//
//  compiler.h
//  design_pattern
//
//  Created by jack on 14-7-16.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_compiler_h
#define design_pattern_compiler_h


class Scanner
{
public:
    void Scan() { std::cout<<"词法分析"<<std::endl; }
};
class Parser
{
public:
    void Parse() { std::cout<<"语法分析"<<std::endl; }
};
class GenMidCode
{
public:
    void GenCode() { std::cout<<"产生中间代码"<<std::endl; }
};
class GenMachineCode
{
public:
    void GenCode() { std::cout<<"产生机器码"<<std::endl;}
};

/**
 *  Facade
 */
class Compiler
{
public:
    void Run()
    {
        Scanner scanner;
        Parser parser;
        GenMidCode genMidCode;
        GenMachineCode genMacCode;
        scanner.Scan();
        parser.Parse();
        genMidCode.GenCode();
        genMacCode.GenCode();
    }
};
#endif
