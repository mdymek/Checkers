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
    User( int, sf::Color, Board& );
    ~User();

    void changePawn( int, Pawn* );
    sf::Color getColor() const;
    int getId() const;
    void reset();
private:
    int m_id;
    std::vector<Pawn*> m_pawns;
    sf::Color m_color;
};
#endif
