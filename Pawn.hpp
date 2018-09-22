#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include "Square.hpp"
#include "User.hpp"

class User;
class Square;
class Pawn {
public:
    Pawn( User*, Square* );
    ~Pawn();

    void move( Square* );

    sf::Color getColor() const;
    sf::CircleShape getShape() const;
private:
    User* m_user;
    Square* m_square;
    sf::CircleShape m_shape;
};

#endif
