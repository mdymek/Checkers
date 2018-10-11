#include "User.hpp"
#include "Man.hpp"

User::User( int id, sf::Color color, Board& board ):
    m_id( id ),
    m_color( color )
{
    if ( id == 1 ){
        int x = 0;
        int y = 9;
        for ( int i = 0; i < 20; i++ ){
            Man* man = new Man( i, this, board.get(x, y) );
            m_pawns.push_back( man );

            x += 2;
            if ( x > 9 ){
                x %= 9;
                y--;
                if ( y % 2 != 0 ) x = 0;
            }
        }
    }
    else if ( id == 2 ){
        int x = 1;
        int y = 0;
        for ( int i = 0; i < 20; i++ ){
            Man* man = new Man( i, this, board.get(x, y) );
            m_pawns.push_back( man );

            x += 2;
            if ( x > 9 ){
                x %= 9;
                y++;
                if ( y % 2 != 0 ) x = 0;
            }
        }
    }
}

User::~User(){}

void User::changePawn( int i, Pawn* pawn ){
    m_pawns[i] = pawn;
}

sf::Color User::getColor() const{ return m_color; }
int User::getId() const{ return m_id; }

void User::reset(){
    for( int i = 0; i < 20; i++ ){
        if( m_pawns[i]->getSquare() == nullptr ) {
            //delete m_pawns[i];
            m_pawns[i] = nullptr;
        }
        else {
            m_pawns[i]->reset();
        }
    }
}
