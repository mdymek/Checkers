#ifndef MAN_H
#define MAN_H

#include <cmath>
#include "King.hpp"

class Board;
class Man: public Pawn {
public:
    using Pawn::Pawn;
    void checkOptionsCapture( int, int, bool&, Board* );
    void checkOptionsMove( int, int, bool&, Board* );
    bool movePawn( int, int, Board* );
};
#endif
