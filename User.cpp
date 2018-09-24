#include "User.hpp"
#include "Man.hpp"

User::User( sf::Color color, Board& board ):
    m_color( color )
{
    int x = 0;
    int y = 9;
    for ( int i = 0; i < 20; i++ ){
        Man* man = new Man(this, board.get(x, y));
        m_pawns.push_back(man);

        x += 2;
        if ( x > 9 ){
            x %= 9;
            y--;
            if ( y % 2 != 0 ) x = 0;
        }
    }
}

User::~User(){}

sf::Color User::getColor() const{ return m_color; }
