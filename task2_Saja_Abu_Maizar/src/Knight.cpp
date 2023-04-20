#include "Knight.h"
#include <stdlib.h>

Knight::Knight(PieceColor color, int row, int col)
    : Piece(PieceType::Knight, color, row, col)
{}

bool Knight::isValidMove(int row, int col) const {
    int rowDiff = abs(getRow() - row);
    int colDiff = abs(getCol() - col);

    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}
