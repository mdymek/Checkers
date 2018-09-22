#ifndef SQUARE_H
#define SQUARE_H
#include "Pawn.hpp"
#include <iostream>

class User;
class Pawn;
class Square {
public:
    Square( sf::Vector2f, sf::Color );
    ~Square();

    void setOption();    
    bool isFree() const;
    void addPawn( Pawn* );
    void removePawn();
    void draw( sf::RenderWindow& );
private:
    bool m_isOption;
    sf::Vector2f m_position;
    sf::RectangleShape m_shape;
    Pawn* m_pawn;
};
#endif
