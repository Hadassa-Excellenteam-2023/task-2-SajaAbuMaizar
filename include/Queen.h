#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
    Queen(PieceColor color, int row, int col);

    bool isValidMove(int row, int col) const override;
};