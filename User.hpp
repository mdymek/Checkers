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
    void deletePawn( int );

    sf::Color getColor() const;
    int getId() const;
    int getNumber() const;
    void reset();
private:
    int m_id;
    int m_num_pawns;
    std::vector<Pawn*> m_pawns;
    sf::Color m_color;
};
#endif
