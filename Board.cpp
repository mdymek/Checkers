#include "Board.hpp"
#include "King.hpp"

Board::Board(){
    sf::Color color = sf::Color::White;
    for ( int x = 0; x < 10; x++ ){
        std::vector <Square*> column;
        for ( int y = 0; y < 10; y++ ){
            //std::cout << "x y " << x << " " << y << std::endl;
            Square* square = new Square(sf::Vector2f(x, y), color);
            column.push_back(square);
            color = (color == sf::Color::White ? sf::Color::Black : sf::Color::White);
        }
        m_squares.push_back(column);
        color = (color == sf::Color::White ? sf::Color::Black : sf::Color::White);
    }
}

Board::~Board(){}

Square* Board::get( int x, int y ){ return m_squares[x][y]; }

bool Board::checkSquare( int x, int y, User* user, bool& first ){
    std::cout << "kwadrat: " << x << " " << y << " pionek: " << ( m_squares[x][y]->isFree() ? -1 : m_squares[x][y]->getPawn()->getId()) << std::endl;
    bool play = true;
    std::cout << "user: " << user->getId() << std::endl;
    if ( !m_squares[x][y]->isFree() ){
        if ( m_squares[x][y]->getPawn()->getUser() == user && (first || m_squares[x][y]->getPawn()->ifUsed()) ){
            deleteOptions();
            m_squares[x][y]->getPawn()->checkOptionsCapture(x, y, play, this);
            if ( play ) std::cout << "możliwość bicia" << std::endl;
            if ( !play && first ){
                m_squares[x][y]->getPawn()->checkOptionsMove(x, y, play, this);
            }
        }
    }
    else {
        if ( m_squares[x][y]->getOption() != nullptr ) {
            play = m_squares[x][y]->getOption()->getPawn()->movePawn( x, y, this );
            first = false;
        }
        deleteOptions();
    }
    if ( play == false ){
        std::cout << "Reset" << std::endl;
        user->reset();
    }
    std::cout << "play: " << play << std::endl;
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
