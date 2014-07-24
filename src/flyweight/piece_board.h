//
//  piece_board.h
//  design_pattern
//
//  Created by jack on 14-7-17.
//  Copyright (c) 2014年 jack. All rights reserved.
//

#ifndef design_pattern_piece_board_h
#define design_pattern_piece_board_h
#include <vector>
#include <map>
#include "piece.h"

/**
 *  Flyweight factory
 */
class PieceBoard
{

public:
    PieceBoard(std::string &black, std::string &white)
    : black_name_(black), white_name_(white)
    {
    }
    ~PieceBoard()
    {
        std::map<PieceColor,Piece*>::iterator iter=pieces_.begin();
        for (; iter!=pieces_.end(); iter++)
        {
            delete iter->second;
        }
        pieces_.clear();
        black_pos_.clear();
        white_pos_.clear();
    }
    void SetPiece(PieceColor color, PiecePos pos);
    void Draw(std::string &name);
    private:
    std::vector<PiecePos> black_pos_; //存放黑棋子的位置
    std::vector<PiecePos> white_pos_; //存放白棋子的位置
    std::string black_name_;     //黑方队名称
    std::string white_name_;     //白方队名称
    std::map<PieceColor,Piece*> pieces_;
};

void PieceBoard::SetPiece(PieceColor color, PiecePos pos)
{
    std::map<PieceColor,Piece*>::iterator iter;
    iter=pieces_.find(color);
    if (iter==pieces_.end())
    {
        pieces_.insert(std::pair<PieceColor,Piece*>(color,new Piece(color)));
    }
    
    if (color==BLACK)
    {
        black_pos_.push_back(pos);
    }
    else
    {
        white_pos_.push_back(pos);
    }
}

void PieceBoard::Draw(std::string &name)
{
    std::vector<PiecePos>::iterator iter;

    if(name.compare(black_name_)==0)
    {
        for (iter=black_pos_.begin(); iter!=black_pos_.end(); iter++)
        {
            std::cout<<black_name_<<"在位置("<<(*iter).x<<','<<(*iter).y<<")";
            
            pieces_[BLACK]->Draw();
        }
    }
    else
    {
        for (iter=white_pos_.begin(); iter!=white_pos_.end(); iter++)
        {
            std::cout<<white_name_<<"在位置("<<(*iter).x<<','<<(*iter).y<<")";
            
            pieces_[WHITE]->Draw();
        }
    }
}


#endif
