#include "Board.hpp"
#include "King.hpp"

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

Square* Board::get( int x, int y ){ return m_squares[x][y]; }

bool Board::checkSquare( int x, int y ){
    bool play = true;
    if ( !m_squares[x][y]->isFree() ){
        m_squares[x][y]->getPawn()->checkOptions(x, y, play, this);
    }
    else {
        if ( m_squares[x][y]->getOption() != nullptr ) {
            m_squares[x][y]->getOption()->getPawn()->movePawn( x, y, this );
        }
        deleteOptions();
    }
    return play;
}

void Board::deleteOptions(){
    for ( int x = 0; x < 10; x++ ){
        for ( int y = 0; y < 10; y++ ){
            m_squares[x][y]->unsetOption();
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
