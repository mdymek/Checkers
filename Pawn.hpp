#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "Square.hpp"
#include "User.hpp"

class User;
class Square;
class Pawn {
public:
    Pawn( User*, Square* );
    ~Pawn();

    sf::Color getColor() const;
    sf::CircleShape getShape() const;
    User* getUser() const;

    void move( Square* );
    void checkOptions( int, int, bool, Board* );
private:
    User* m_user;
    Square* m_square;
    sf::CircleShape m_shape;
};

#endif
