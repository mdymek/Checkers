#include "Pawn.hpp"

Pawn::Pawn( User* user, Square* square ){
    m_user = user;
    m_square = square;
    square->addPawn(this);
    m_shape.setRadius(25);
}

Pawn::~Pawn(){}

void Pawn::move( Square* destination ) { m_square = destination; }

sf::Color Pawn::getColor() const{ return m_user->getColor(); }
sf::CircleShape Pawn::getShape() const { return m_shape; }
