#include "King.hpp"

void King::checkOptions( int t_x, int t_y, bool first, Board* board ){
    int x = t_x + 1;
    int y = t_y + 1;

    while ( x < 10 && y < 10 ){
        if ( board->get(x, y)->isFree() ){
            board->get(x, y)->setOption( m_square );
        }
        x++;
        y++;
    }

    x = t_x - 1;
    y = t_y + 1;
    while ( x >= 0 && y < 10 ){
        if ( board->get(x, y)->isFree() ){
            board->get(x, y)->setOption( m_square );
        }
        x--;
        y++;
    }

    x = t_x - 1;
    y = t_y - 1;

    while ( x >= 0 && y >= 0){
        if ( board->get(x, y)->isFree() ){
            board->get(x, y)->setOption( m_square );
        }
        x--;
        y--;
    }

    x = t_x + 1;
    y = t_y - 1;
    while ( x < 10 && y >= 0 ){
        if ( board->get(x, y)->isFree() ){
            board->get(x, y)->setOption( m_square );
        }
        x++;
        y--;
    }
}

void King::movePawn( int x, int y, Board* board ){
    Square* destination = board->get(x, y);
    Square* origin = m_square;
    m_square = destination;
    origin->removePawn();
    destination->addPawn(this);
}