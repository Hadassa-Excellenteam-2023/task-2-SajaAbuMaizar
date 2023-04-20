#pragma once
#include "Piece.h"

class Knight : public Piece {
public:
    Knight(PieceColor color, int row, int col);
    bool isValidMove(int row, int col) const override;
};

