//
//  piece.h
//  design_pattern
//
//  Created by jack on 14-7-17.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_piece_h
#define design_pattern_piece_h

//棋子颜色
enum PieceColor {BLACK, WHITE};

//棋子位置
struct PiecePos
{
    int x;
    int y;
    PiecePos(int a, int b): x(a), y(b) {}
};

/**
 *  Flyweight
 */
//棋子定义
class Piece
{
public:
    Piece(PieceColor color): color_(color) {}
    ~Piece() {}
    void Draw()
    {
        switch (color_)
        {
            case BLACK:
                std::cout<<"绘制一颗黑子"<<std::endl;
                break;
               
            case WHITE:
                std::cout<<"绘制一颗白子"<<std::endl;
                break;
                
            default:
                break;
        }
    }
    PieceColor GetColor(){return color_;}
private:
    PieceColor color_;
};


#endif
