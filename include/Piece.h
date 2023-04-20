#ifndef PIECE_H
#define PIECE_H

enum class PieceType {
    King,
    Queen,
    Rook,
    Bishop,
    Knight,
    Pawn
};

enum class PieceColor {
    White,
    Black
};

class Piece {
public:
    Piece(PieceType type, PieceColor color, int row, int col)
        : type_(type), color_(color), row_(row), col_(col) {}
    virtual ~Piece(); // virtual destructor added

    PieceType getType() const {
        return type_;
    }

    PieceColor getColor() const {
        return color_;
    }

    int getRow() const {
        return row_;
    }

    int getCol() const {
        return col_;
    }

    void setRow(int row) {
        row_ = row;
    }

    void setCol(int col) {
        col_ = col;
    }


    virtual bool isValidMove(int row, int col) const = 0;

protected:
    PieceType type_;
    PieceColor color_;
    int row_;
    int col_;
};

#endif // PIECE_H
