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

    void setSquare ( Square* );
    Square* getSquare() const;

    int getId() const;
    bool ifUsed() const;
    void reset();

    sf::Color getColor() const;
    sf::CircleShape getShape() const;
    User* getUser() const;

    virtual bool movePawn( int, int, Board* ) =0;
    virtual void checkOptionsCapture( int, int, bool&, Board* ) =0;
    virtual void checkOptionsMove( int, int, bool&, Board* ) =0;
protected:
    int m_id;
    bool m_moved;
    User* m_user;
    Square* m_square;
    sf::CircleShape m_shape;
};

#endif
