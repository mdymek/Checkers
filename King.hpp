#ifndef KING_H
#define KING_H

#include "Pawn.hpp"

class Board;
class King: public Pawn {
public:
    using Pawn::Pawn;
    void checkOptions( int, int, bool, Board* );
    void movePawn( int, int, Board* );
};
#endif
