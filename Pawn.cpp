#include "Pawn.hpp"

Pawn::Pawn( int id, User* user, Square* square ):
    m_id( id ),
    m_moved( false ),
    m_user( user ),
    m_square( square )
{
    square->addPawn(this);
    m_shape.setRadius(25);
}

Pawn::~Pawn(){
    std::cout << "usunięcie pionka " << m_id << std::endl;
    delete m_user;
    delete m_square;
}

void Pawn::setSquare( Square* square ){ m_square = square; }
Square* Pawn::getSquare() const{ return m_square; }

int Pawn::getId() const{ return m_id; }
void Pawn::reset() { m_moved = false; }
bool Pawn::ifUsed() const{ return m_moved; }

sf::Color Pawn::getColor() const{ return m_user->getColor(); }
sf::CircleShape Pawn::getShape() const { return m_shape; }
User* Pawn::getUser() const{ return m_user; }
