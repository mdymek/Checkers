#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include "Pawn.hpp"
#include "Board.hpp"

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
