#include "Pawn.hpp"

Pawn::Pawn( User* user, Square* square ):
    m_user( user ),
    m_square( square)
{
    square->addPawn(this);
    m_shape.setRadius(25);
}

Pawn::~Pawn(){}

sf::Color Pawn::getColor() const{ return m_user->getColor(); }
sf::CircleShape Pawn::getShape() const { return m_shape; }
User* Pawn::getUser() const{ return m_user; }

void Pawn::move( Square* destination ) {
    Square* origin = m_square;
    m_square = destination;
    origin->removePawn();
    destination->addPawn(this);
}

void Pawn::checkOptions( int x, int y, bool first, Board* board ){
    if ( board->get(x, y)->isFree() ){
        board->get(x, y)->setOption( m_square );
    }
    if ( x - 1 >= 0 && y - 1 >= 0 ){
        if ( board->get(x-1, y-1)->isFree() ){
            if ( first ) board->get(x-1, y-1)->setOption( m_square );
        }
        else if ( x - 2 >= 0 && y - 2 >= 0 ){
            if ( board->get(x-1, y-1)->getPawn()->getUser() != m_user && board->get(x-2,y-2)->isFree()){
                checkOptions( x - 2, y - 2, false, board );
            }
        }
    }
    if ( x + 1 < 10 && y - 1 >= 0 ){
        if ( board->get(x+1, y-1)->isFree()){
            if ( first ) board->get(x+1, y-1)->setOption( m_square );
        }
        else if ( x + 2 < 10 && y - 2 >= 0 ){
            if ( board->get(x+1, y-1)->getPawn()->getUser() != m_user && board->get(x+2, y-2)->isFree() ){
                checkOptions( x + 2, y - 2, false, board );
            }
        }
    }
}
