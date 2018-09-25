#ifndef MAN_H
#define MAN_H

#include "King.hpp"

class Board;
class Man: public Pawn {
public:
    using Pawn::Pawn;
    void checkOptions( int, int, bool, Board* );
    void movePawn( int, int, Board* );
};
#endif