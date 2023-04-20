#pragma once
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(PieceColor color, int row, int col);

    bool isValidMove(int row, int col) const override;
};