#pragma once
#include "Piece.h"

class King : public Piece {
public:
    King(PieceColor color, int row, int col);

    bool isValidMove(int row, int col) const override;
};