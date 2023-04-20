#pragma once
#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(PieceColor color, int row, int col);

    bool isValidMove(int row, int col) const override;
};

#endif // ROOK_H
