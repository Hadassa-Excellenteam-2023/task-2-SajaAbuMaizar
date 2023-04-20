#include "King.h"
#include <stdlib.h>

King::King(PieceColor color, int row, int col)
    : Piece(PieceType::King, color, row, col) {}

bool King::isValidMove(int row, int col) const {
    int rowDiff = abs(row - row_);
    int colDiff = abs(col - col_);
    return (rowDiff == 1 && colDiff == 0) || (rowDiff == 0 && colDiff == 1) ||
        (rowDiff == 1 && colDiff == 1);
}