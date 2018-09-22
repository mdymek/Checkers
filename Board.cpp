#include "Board.hpp"

Board::Board(){
    sf::Color color = sf::Color::White;
    for ( int x = 0; x < 10; x++ ){
        std::vector <Square*> column;
        for ( int y = 0; y < 10; y++ ){
            //std::cout << "x y " << x << " " << y << std::endl;
            Square* square = new Square(sf::Vector2f(51*x, 51*y), color);
            column.push_back(square);
            color = (color == sf::Color::White ? sf::Color::Black : sf::Color::White);
        }
        m_squares.push_back(column);
        color = (color == sf::Color::White ? sf::Color::Black : sf::Color::White);
    }
}

Board::~Board(){}

void Board::checkSquare( int x, int y ){
    if ( !m_squares[x][y]->isFree() ){
        checkOptions(x, y, true);
    }
}

void Board::checkOptions( int x, int y, bool first ){
    if ( m_squares[x][y]->isFree() ){
        m_squares[x][y]->setOption();
    }
    if ( x - 1 >= 0 && y - 1 >= 0 ){
        if ( m_squares[x-1][y-1]->isFree() ){
            if ( first ) m_squares[x-1][y-1]->setOption();
        }
        else if ( x - 2 >= 0 && y - 2 >= 0 ){
            if ( m_squares[x-2][y-2]->isFree()){
                checkOptions( x - 2, y - 2, false );
            }
        }
    }
    if ( x + 1 < 10 && y - 1 >= 0 ){
        if ( m_squares[x+1][y-1]->isFree()){
            if ( first ) m_squares[x+1][y-1]->setOption();
        }
        else if ( x + 2 < 10 && y - 2 >= 0 ){
            if ( m_squares[x+2][y-2]->isFree() ){
                checkOptions( x + 2, y - 2, false );
            }
        }
    }
}

void Board::draw( sf::RenderWindow& window ){
    for ( int x = 0; x < 10; x++ ){
        for ( int y = 0; y < 10; y++ ){
            m_squares[x][y]->draw( window );
        }
    }
}
