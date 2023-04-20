#pragma once
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <vector>
#include "Piece.h"

class Chessboard {
public:
    Chessboard();
    ~Chessboard();
    int movePiece(int startRow, int startCol, int endRow, int endCol);
    void printBoard() const;
    std::string toString() const;
    bool isCheck(PieceColor color);

private:
    Piece* board_[8][8];
    PieceColor currentPlayer_;
    void initializeBoard();
    void clearBoard();
    //bool isCheck(PieceColor color);
};

#endif /* CHESSBOARD_H */
