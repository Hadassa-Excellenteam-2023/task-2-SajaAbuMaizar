#include "Pawn.h"
#include <stdlib.h>

Pawn::Pawn(PieceColor color, int row, int col)
    : Piece(PieceType::Pawn, color, row, col)
{}

bool Pawn::isValidMove(int row, int col) const {
    int rowDiff = abs(getRow() - row);
    int colDiff = abs(getCol() - col);

    // Pawn can move one or two squares forward on first move
    if (getRow() == 1 && row == 3 && colDiff == 0) {
        return true;
    }
    if (getRow() == 6 && row == 4 && colDiff == 0) {
        return true;
    }

    // Pawn can move one square forward
    if (getRow() + 1 == row && colDiff == 0) {
        return true;
    }

    return false;
}
