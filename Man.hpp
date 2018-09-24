#ifndef MAN_H
#define MAN_H

#include "Pawn.hpp"

class Board;
class Man: public Pawn {
public:
    using Pawn::Pawn;
    void checkOptions( int, int, bool, Board* );
};
#endif
