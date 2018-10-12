#ifndef KING_H
#define KING_H

#include "Pawn.hpp"

class Board;
class King: public Pawn {
public:
    using Pawn::Pawn;
    void checkOptionsCapture( int, int, bool&, Board* );
    void checkOptionsMove( int, int, bool&, Board* );
    bool movePawn( int, int, Board* );
};
#endif
