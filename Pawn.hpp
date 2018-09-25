#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include "User.hpp"

class Board;
class User;
class Square;
class Pawn {
public:
    explicit Pawn( int, User*, Square* );
    virtual ~Pawn();

    int getId() const;

    sf::Color getColor() const;
    sf::CircleShape getShape() const;
    User* getUser() const;

    virtual void movePawn( int, int, Board* ) =0;
    virtual void checkOptions( int, int, bool, Board* ) =0;
protected:
    int m_id;
    User* m_user;
    Square* m_square;
    sf::CircleShape m_shape;
};

#endif
