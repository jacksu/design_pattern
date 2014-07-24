//
//  flyweight_test.cpp
//  design_pattern
//
//  Created by jack on 14-7-20.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#include "flyweight_test.h"

int main(int argv, char** argc)
{
    std::string black_name("中国");
    std::string white_name("美国");
    PieceBoard *board=new PieceBoard(black_name,white_name);
    board->SetPiece(BLACK,PiecePos(1,1));
    board->SetPiece(BLACK,PiecePos(1,2));
    board->SetPiece(WHITE,PiecePos(1,3));
    board->SetPiece(WHITE,PiecePos(1,4));
    board->Draw(black_name);
    board->Draw(white_name);
    delete board;
    return 0;
}
