#include "Queen.h"
#include <stdlib.h>

Queen::Queen(PieceColor color, int row, int col)
    : Piece(PieceType::Queen, color, row, col) {}

bool Queen::isValidMove(int row, int col) const {
    int rowDiff = abs(row - row_);
    int colDiff = abs(col - col_);
    return row_ == row || col_ == col || rowDiff == colDiff;
}