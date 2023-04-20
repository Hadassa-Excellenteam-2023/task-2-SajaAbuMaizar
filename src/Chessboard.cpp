#include "Chessboard.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"

Chessboard::Chessboard() {
    initializeBoard();
    currentPlayer_ = PieceColor::White;
}


Chessboard::~Chessboard() {
    clearBoard();
}

void Chessboard::initializeBoard() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            board_[row][col] = nullptr;
        }
    }

    // initialize white pieces
    board_[0][0] = new Rook(PieceColor::White, 0, 0);
    board_[0][1] = new Knight(PieceColor::White, 0, 1);
    board_[0][2] = new Bishop(PieceColor::White, 0, 2);
    board_[0][3] = new Queen(PieceColor::White, 0, 3);
    board_[0][4] = new King(PieceColor::White, 0, 4);
    board_[0][5] = new Bishop(PieceColor::White, 0, 5);
    board_[0][6] = new Knight(PieceColor::White, 0, 6);
    board_[0][7] = new Rook(PieceColor::White, 0, 7);

    for (int i = 0; i < 8; i++) {
        board_[1][i] = new Pawn(PieceColor::White, 1, i);
    }

    // initialize black pieces
    board_[7][0] = new Rook(PieceColor::Black, 7, 0);
    board_[7][1] = new Knight(PieceColor::Black, 7, 1);
    board_[7][2] = new Bishop(PieceColor::Black, 7, 2);
    board_[7][3] = new Queen(PieceColor::Black, 7, 3);
    board_[7][4] = new King(PieceColor::Black, 7, 4);
    board_[7][5] = new Bishop(PieceColor::Black, 7, 5);
    board_[7][6] = new Knight(PieceColor::Black, 7, 6);
    board_[7][7] = new Rook(PieceColor::Black, 7, 7);

    for (int i = 0; i < 8; i++) {
        board_[6][i] = new Pawn(PieceColor::Black, 6, i);
    }
}


void Chessboard::clearBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board_[i][j] != nullptr) {
                delete board_[i][j];
            }
        }
    }
}

int Chessboard::movePiece(int startRow, int startCol, int endRow, int endCol) {
    Piece* startPiece = board_[startRow][startCol];
    Piece* endPiece = board_[endRow][endCol];

    if (startPiece == nullptr) {
        return 11; // no piece to move
    }

    if (startPiece->getColor() != currentPlayer_) {
        return 12; // can't move opponent's piece
    }

    if (endPiece != nullptr && endPiece->getColor() == currentPlayer_) {
        return 13; // can't capture own piece
    }

    if (!startPiece->isValidMove(endRow, endCol)) {
        return 21; // invalid move
    }

    Chessboard copy = *this;
    copy.board_[endRow][endCol] = startPiece;
    copy.board_[startRow][startCol] = nullptr;
    startPiece->setRow(endRow);
    startPiece->setCol(endCol);

    if (copy.isCheck(currentPlayer_)) {
        return 31; // moving will cause checkmate
    }

    board_[endRow][endCol] = startPiece;
    board_[startRow][startCol] = nullptr;
    startPiece->setRow(endRow);
    startPiece->setCol(endCol);
    if (isCheck(currentPlayer_)) {
        return 31; // moving will cause checkmate
    }

    board_[endRow][endCol] = startPiece;
    board_[startRow][startCol] = nullptr;
    startPiece->setRow(endRow);
    startPiece->setCol(endCol);

    if (isCheck(currentPlayer_)) {
        return 41; // legal move and caused check
    }
    else {
        currentPlayer_ = (currentPlayer_ == PieceColor::White) ? PieceColor::Black : PieceColor::White;
        return 42; // legal move and next turn
    }
}

    
bool Chessboard::isCheck(PieceColor color) {
// find the king
    int kingRow = -1, kingCol = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece* piece = board_[i][j];
            if (piece != nullptr && piece->getType() == PieceType::King && piece->getColor() == color) {
                kingRow = i;
                kingCol = j;
                break;
            }
        }
        if (kingRow != -1 && kingCol != -1) {
            break;
        }
    }

    // check for rooks and queens attacking from the left or right
    for (int i = kingCol + 1; i < 8; i++) {
        Piece* piece = board_[kingRow][i];
        if (piece != nullptr) {
            if (piece->getColor() == color) {
                break;
            }
            else if (piece->getType() == PieceType::Rook || piece->getType() == PieceType::Queen) {
                return true;
            }
            else {
                break;
            }
        }
    }
    for (int i = kingCol - 1; i >= 0; i--) {
        Piece* piece = board_[kingRow][i];
        if (piece != nullptr) {
            if (piece->getColor() == color) {
                break;
            }
            else if (piece->getType() == PieceType::Rook || piece->getType() == PieceType::Queen) {
                return true;
            }
            else {
                break;
            }
        }
    }

    // check for rooks and queens attacking from above or below
    for (int i = kingRow + 1; i < 8; i++) {
        Piece* piece = board_[i][kingCol];
        if (piece != nullptr) {
            if (piece->getColor() == color) {
                break;
            }
            else if (piece->getType() == PieceType::Rook || piece->getType() == PieceType::Queen) {
                return true;
            }
            else {
                break;
            }
        }
    }
    for (int i = kingRow - 1; i >= 0; i--) {
        Piece* piece = board_[i][kingCol];
        if (piece != nullptr) {
            if (piece->getColor() == color) {
                break;
            }
            else if (piece->getType() == PieceType::Rook || piece->getType() == PieceType::Queen) {
                return true;
            }
            else {
                break;
            }
        }
    }

    // check for bishops and queens attacking diagonally
    int i = kingRow + 1, j = kingCol + 1;
    while (i < 8 && j < 8) {
        Piece* piece = board_[i][j];
        if (piece != nullptr) {
            if (piece->getColor() == color) {
                break;
            }
            else if (piece->getType() == PieceType::Bishop || piece->getType() == PieceType::Queen) {
                return true;
            }
            else {
                break;
            }
        }
        i++;
        j++;
    }
    i = kingRow - 1, j = kingCol - 1;
    while (i >= 0 && j >= 0) {
        Piece* piece = board_[i][j];
        if (piece != nullptr) {
            if (piece->getColor() == color) {
                break;
            }
            else if (piece->getType() == PieceType::Bishop || piece->getType() == PieceType::Queen) {
                return true;
            }
            else {
                break;
            }
        }
        i--;
        j--;
    }
    i = kingRow + 1, j = kingCol - 1;
    while (i < 8 && j >= 0) {
        Piece* piece = board_[i][j];
        if (piece != nullptr) {
            if (piece->getColor() == color) {
                break;
            }
            else if (piece->getType() == PieceType::Bishop || piece->getType() == PieceType::Queen) {
                return true;
            }
            else {
                break;
            }
        }
        i++;
        j--;
    }
    i = kingRow - 1, j = kingCol + 1;
    while (i >= 0 && j < 8) {
        Piece* piece = board_[i][j];
        if (piece != nullptr) {
            if (piece->getColor() == color) {
                break;
            }
            else if (piece->getType() == PieceType::Bishop || piece->getType() == PieceType::Queen) {
                return true;
            }
            else {
                break;
            }
        }
        i--;
        j++;
    }

    // check for knights attacking
    int knightMoves[8][2] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };
    for (int k = 0; k < 8; k++) {
        int row = kingRow + knightMoves[k][0];
        int col = kingCol + knightMoves[k][1];
        if (row >= 0 && row < 8 && col >= 0 && col < 8) {
            Piece* piece = board_[row][col];
            if (piece != nullptr && piece->getType() == PieceType::Knight && piece->getColor() != color) {
                return true;
            }
        }
    }

    // check for pawns attacking
    int pawnDir = (color == PieceColor::White) ? -1 : 1;
    if (kingRow + pawnDir >= 0 && kingRow + pawnDir < 8) {
        if (kingCol > 0) {
            Piece* piece = board_[kingRow + pawnDir][kingCol - 1];
            if (piece != nullptr && piece->getType() == PieceType::Pawn && piece->getColor() != color) {
                return true;
            }
        }
        if (kingCol < 7) {
            Piece* piece = board_[kingRow + pawnDir][kingCol + 1];
            if (piece != nullptr && piece->getType() == PieceType::Pawn && piece->getColor() != color) {
                return true;
            }
        }
    }

    // check for knights attacking
    for (int i1 = -2; i1 <= 2; i1++) {
        for (int j1 = -2; j1 <= 2; j1++) {
            if (abs(i1) + abs(j1) == 3) {
                int row = kingRow + i1;
                int col = kingCol + j1;
                if (row >= 0 && row < 8 && col >= 0 && col < 8) {
                    Piece* piece = board_[row][col];
                    if (piece != nullptr && piece->getType() == PieceType::Knight && piece->getColor() != color) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
