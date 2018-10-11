#include "Man.hpp"

void Man::checkOptions( int x, int y, bool& play, bool first, Board* board ){
    play = false;
    if ( m_user->getId() == 1 ){
        if ( x - 1 >= 0 && y - 1 >= 0 ){
            if ( board->get(x-1, y-1)->isFree() ){
                if ( first ) {
                    board->get(x-1, y-1)->setOption( m_square );
                    play = true;
                }
            }
            else if ( x - 2 >= 0 && y - 2 >= 0 ){
                if ( board->get(x-1, y-1)->getPawn()->getUser() != m_user && board->get(x-2,y-2)->isFree()){
                    board->get(x-2,y-2)->setOption( m_square );
                    play = true;
                }
            }
        }
        if ( x + 1 < 10 && y - 1 >= 0 ){
            if ( board->get(x+1, y-1)->isFree() ){
                if ( first ){
                    board->get(x+1, y-1)->setOption( m_square );
                    play = true;
                }
            }
            else if ( x + 2 < 10 && y - 2 >= 0 ){
                if ( board->get(x+1, y-1)->getPawn()->getUser() != m_user && board->get(x+2, y-2)->isFree() ){
                    board->get(x+2, y-2)->setOption( m_square );
                    play = true;
                }
            }
        }
    }
    else if ( m_user->getId() == 2 ){
        if ( x + 1 < 10 && y + 1 < 10 ){
            if ( board->get(x+1, y+1)->isFree() ){
                if ( first ) {
                    board->get(x+1, y+1)->setOption( m_square );
                    play = true;
                }
            }
            else if ( x + 2 < 10 && y + 2 < 10 ){
                if ( board->get(x+1, y+1)->getPawn()->getUser() != m_user && board->get(x+2,y+2)->isFree()){
                    board->get(x+2, y+2)->setOption( m_square );
                    play = true;
                }
            }
        }
        if ( x - 1 >= 0 && y + 1 < 10 ){
            if ( board->get(x-1, y+1)->isFree() ){
                if ( first ) {
                    board->get(x-1, y+1)->setOption( m_square );
                    play = true;
                }
            }
            else if ( x - 2 >= 0 && y + 2 < 10 ){
                if ( board->get(x-1, y+1)->getPawn()->getUser() != m_user && board->get(x-2, y+2)->isFree() ){
                    board->get(x-2, y+2)->setOption( m_square );
                    play = true;
                }
            }
        }
    }
}

void Man::movePawn( int x, int y, Board* board ){
    Square* destination = board->get(x, y);
    if ( abs( x - m_square->getPosition().x ) == 2 ){
        Square* target = board->get( abs(x + m_square->getPosition().x)/2, abs(y + m_square->getPosition().y)/2 );
        target->getPawn()->setSquare( nullptr );
        target->removePawn();
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
}
