#include "consts.h"

#include "Man.hpp"

void Man::checkOptionsCapture( int x, int y, bool& play, Board* board ){
    if ( DEBUG ) std::cout << "sprawdzam bicia" << std::endl;
    play = false;
    int shift;
    if ( m_user->getId() == 1 ) shift = -1;
    else shift = 1;

    if ( x - 2 >= 0 && y + 2*shift >= 0 ){
        if ( !board->get(x - 1, y + shift)->isFree() && board->get(x - 1, y + shift)->getPawn()->getUser() != m_user && board->get(x - 2,y + 2*shift)->isFree()){
            board->get(x - 2, y + 2*shift)->setOption( m_square );
            if ( DEBUG ) std::cout << "opcja " << x-2 << " " << y + 2*shift << std::endl;
            play = true;
        }
    }
    if ( x + 1 < 10 && y + shift >= 0 ){
        if ( x + 2 < 10 && y + 2*shift >= 0 ){
            if ( !board->get(x+1, y + shift)->isFree() && board->get(x+1, y + shift)->getPawn()->getUser() != m_user && board->get(x+2, y + 2*shift)->isFree() ){
                board->get(x+2, y + 2*shift)->setOption( m_square );
                if ( DEBUG ) std::cout << "opcja " << x+2 << " " << y + 2*shift << std::endl;
                play = true;
            }
        }
    }
}

void Man::checkOptionsMove( int x, int y, bool& play, Board* board ){
    if ( DEBUG ) std::cout << "sprawdzam ruchy" << std::endl;
    if ( DEBUG ) std::cout << m_user->getId() << std::endl;
    int shift;
    if ( m_user->getId() == 1 ) shift = -1;
    else shift = 1;

    if ( x - 1 >= 0 && y + shift >= 0 && board->get(x - 1, y + shift)->isFree()){
        board->get(x - 1, y + shift)->setOption( m_square );
        if ( DEBUG ) std::cout << "opcja " << x-1 << " " << y + shift << std::endl;
        play = true;
    }
    if ( x + 1 < 10 && y + shift >= 0 && board->get(x+1, y + shift)->isFree()){
        board->get(x+1, y + shift)->setOption( m_square );
        if ( DEBUG ) std::cout << "opcja " << x+1 << " " << y + shift << std::endl;
        play = true;
    }
}

bool Man::movePawn( int x, int y, Board* board ){
    if ( DEBUG ) std::cout << "ruch pionka z " << m_square->getPosition().x << " " << m_square->getPosition().y << " na " << x << " " << y << std::endl;
    bool play;
    Square* destination = board->get(x, y);
    if ( abs( x - m_square->getPosition().x ) == 2 ){
        Square* target = board->get( abs(x + m_square->getPosition().x)/2, abs(y + m_square->getPosition().y)/2 );
        target->getPawn()->getUser()->deletePawn(target->getPawn()->getId());
        target->removePawn();
        play = true;
    }
    else {
        play = false;
    }
    if ( y == 0 ){
        King* king = new King( m_id, m_user, destination );
        m_user->changePawn( m_id, king );
        m_square->removePawn();
    }
    else {
        Square* origin = m_square;
        origin->removePawn();
        m_square = destination;
        destination->addPawn(this);
    }
    m_moved = true;
    return play;
}
