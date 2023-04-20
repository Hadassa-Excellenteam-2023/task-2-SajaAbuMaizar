#pragma once

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(PieceColor color, int row, int col);
    bool isValidMove(int row, int col) const override;
};