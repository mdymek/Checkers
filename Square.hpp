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

    void setOption( Square* );
    void unsetOption();
    Square* getOption() const;

    bool isFree() const;
    void addPawn( Pawn* );
    Pawn* getPawn() const;
    void removePawn();

    void draw( sf::RenderWindow& );
private:
    bool m_isOption;
    Square* m_option;
    sf::Vector2f m_position;
    sf::RectangleShape m_shape;
    Pawn* m_pawn;
};
#endif
