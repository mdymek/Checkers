#include "Pawn.hpp"

Pawn::Pawn( User* user, Square* square ):
    m_user( user ),
    m_square( square)
{
    square->addPawn(this);
    m_shape.setRadius(25);
}

Pawn::~Pawn(){
    delete m_user;
    delete m_square;
}

sf::Color Pawn::getColor() const{ return m_user->getColor(); }
sf::CircleShape Pawn::getShape() const { return m_shape; }
User* Pawn::getUser() const{ return m_user; }

void Pawn::move( Square* destination ) {
    Square* origin = m_square;
    m_square = destination;
    origin->removePawn();
    destination->addPawn(this);
}
