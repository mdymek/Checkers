#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include "User.hpp"

class Board;
class User;
class Square;
class Pawn {
public:
    explicit Pawn( User*, Square* );
    virtual ~Pawn();

    sf::Color getColor() const;
    sf::CircleShape getShape() const;
    User* getUser() const;

    void move( Square* );
    virtual void checkOptions( int, int, bool, Board* ) =0;
protected:
    User* m_user;
    Square* m_square;
    sf::CircleShape m_shape;
};

#endif
