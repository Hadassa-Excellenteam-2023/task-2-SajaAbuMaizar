#include "rook.h"

Rook::Rook(PieceColor color, int row, int col)
    : Piece(PieceType::Rook, color, row, col) {}

bool Rook::isValidMove(int row, int col) const {
    return row_ == row || col_ == col;
}