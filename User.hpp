#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include "Board.hpp"
#include "Pawn.hpp"


class Board;
class Pawn;
class User {
public:
    User( sf::Color, Board& );
    ~User();

    sf::Color getColor() const;
private:
    std::vector<Pawn*> m_pawns;
    sf::Color m_color;
};
#endif
