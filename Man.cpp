#include "Man.hpp"

void Man::checkOptions( int x, int y, bool first, Board* board ){
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

void Man::movePawn( int x, int y, Board* board ){
    Square* destination = board->get(x, y);
    if ( y == 0 ){
        King* king = new King( m_id, m_user, destination );
        m_user->changePawn( m_id, king );
        m_square->removePawn();

    }
    else {
        Square* origin = m_square;
        m_square = destination;
        origin->removePawn();
        destination->addPawn(this);
    }
}
