#include "Square.hpp"

Square::Square( sf::Vector2f position, sf::Color color ){
    m_position = position;
    m_shape.setSize( sf::Vector2f(50,50) );
    m_shape.setFillColor( color );
    m_shape.setPosition( position );
    m_pawn = nullptr;
}

Square::~Square(){}

bool Square::isFree() const{ return m_pawn == nullptr; }
void Square::addPawn( Pawn* pawn ) { m_pawn = pawn; }
void Square::removePawn() { m_pawn = nullptr; }

void Square::draw( sf::RenderWindow& window ){
    window.draw( m_shape );
    if( m_pawn != nullptr ){
        sf::CircleShape pawn = m_pawn->getShape();
        pawn.setFillColor( m_pawn->getColor() );
        pawn.setOrigin(0,0);
        pawn.setPosition(m_position);
        window.draw( pawn );
    }
}
