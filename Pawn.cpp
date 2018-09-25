#include "Pawn.hpp"

Pawn::Pawn( int id, User* user, Square* square ):
    m_id( id ),
    m_user( user ),
    m_square( square )
{
    square->addPawn(this);
    m_shape.setRadius(25);
}

Pawn::~Pawn(){
    delete m_user;
    delete m_square;
}

int Pawn::getId() const{ return m_id; }

sf::Color Pawn::getColor() const{ return m_user->getColor(); }
sf::CircleShape Pawn::getShape() const { return m_shape; }
User* Pawn::getUser() const{ return m_user; }
