#include "Square.hpp"

Square::Square( sf::Vector2f position, sf::Color color ):
    m_isOption( false ),
    m_option( nullptr ),
    m_position( position ),
    m_pawn( nullptr )
{
    m_shape.setSize( sf::Vector2f(50,50) );
    m_shape.setFillColor( color );
    m_shape.setPosition( sf::Vector2f(position.x*51, position.y*51) );
}

Square::~Square(){}

void Square::setOption( Square* option ){
    m_isOption = true;
    m_option = option;
}
void Square::unsetOption(){
    m_isOption = false;
    m_option = nullptr;
}
Square* Square::getOption() const{ return m_option; }

sf::Vector2f Square::getPosition() const{ return m_position; }

bool Square::isFree() const{ return m_pawn == nullptr; }
void Square::addPawn( Pawn* pawn ) { m_pawn = pawn; }
Pawn* Square::getPawn() const{ return m_pawn; }
void Square::removePawn() { m_pawn = nullptr; }

void Square::draw( sf::RenderTarget& target, sf::RenderStates states ) const{
    sf::Color color = m_shape.getFillColor();
    if ( m_isOption ){
        m_shape.setFillColor(sf::Color(73, 20, 20));
    }
    target.draw( m_shape, states );
    m_shape.setFillColor(color);
    if( m_pawn != nullptr ){
        sf::CircleShape pawn = m_pawn->getShape();
        pawn.setFillColor( m_pawn->getColor() );
        pawn.setOrigin(0,0);
        pawn.setPosition(m_position.x*51, m_position.y*51);
        target.draw( pawn, states );
    }
}
