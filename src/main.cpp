#include "Chess.h"
#include "Chessboard.h"
#include <vector>

std::vector<int> getCoordinates(std::string res);

int main()
{
    string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr";
    Chess a(board);
    Chessboard chessboard;
    int codeResponse = 0;
    string res = a.getInput();
    while (res != "exit")
    {
        /*
        codeResponse value :
        Illegal movements :
        11 - there is not piece at the source
        12 - the piece in the source is piece of your opponent
        13 - there one of your pieces at the destination
        21 - illegal movement of that piece
        31 - this movement will cause you checkmate

        legal movements :
        41 - the last movement was legal and cause check
        42 - the last movement was legal, next turn
        */

        /**/
        { // put your code here instead that code
            std::vector<int> coordinates = getCoordinates(res);
            codeResponse = chessboard.movePiece(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
        }
        /**/

        a.setCodeResponse(codeResponse);
        res = a.getInput();
    }

    cout << endl << "Exiting " << endl;
    return 0;
}

std::vector<int> getCoordinates(string res) {
    std::vector<int> coordinates;
    for (int i = 0; i < res.length(); i++) {
        char c = res[i];
        if (isdigit(c))
        {
            coordinates.push_back(c - '1');
        }
        else {
            switch (c)
            {
            case 'a':
            case 'A':
                coordinates.push_back(0);
                break;
            case 'b':
            case 'B':
                coordinates.push_back(1);
                break;
            case 'c':
            case 'C':
                coordinates.push_back(2);
                break;
            case 'd':
            case 'D':
                coordinates.push_back(3);
                break;
            case 'e':
            case 'E':
                coordinates.push_back(4);
                break;
            case 'f':
            case 'F':
                coordinates.push_back(5);
                break;
            case 'g':
            case 'G':
                coordinates.push_back(6);
                break;
            case 'h':
            case 'H':
                coordinates.push_back(7);
                break;
            default:
                coordinates.push_back(10);
                break;
            }
        }
    }
    return coordinates;
}
