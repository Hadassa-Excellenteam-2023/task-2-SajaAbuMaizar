#include "Bishop.h"
#include <stdlib.h>

Bishop::Bishop(PieceColor color, int row, int col)
    : Piece(PieceType::Bishop, color, row, col) {}

bool Bishop::isValidMove(int row, int col) const {
    int rowDiff = abs(row - row_);
    int colDiff = abs(col - col_);
    return rowDiff == colDiff;
}