#include "consts.h"

#include "Board.hpp"
#include "King.hpp"

Board::Board(){
    sf::Color color = sf::Color::White;
    for ( int x = 0; x < 10; x++ ){
        std::vector <Square*> column;
        for ( int y = 0; y < 10; y++ ){
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

Board::State Board::checkSquare( int x, int y, User* user, bool& first ){
    if ( DEBUG ) std::cout << "kwadrat: " << x << " " << y << " pionek: " << ( m_squares[x][y]->isFree() ? -1 : m_squares[x][y]->getPawn()->getId()) << std::endl;
    bool play = true;
    if ( DEBUG ) std::cout << "user: " << user->getId() << std::endl;
    if ( !m_squares[x][y]->isFree() ){
        if ( m_squares[x][y]->getPawn()->getUser() == user && (first || m_squares[x][y]->getPawn()->ifUsed()) ){
            deleteOptions();
            m_squares[x][y]->getPawn()->checkOptionsCapture(x, y, play, this);
            if ( DEBUG && play ) std::cout << "możliwość bicia" << std::endl;
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
        if ( DEBUG ) std::cout << "Reset" << std::endl;
        user->reset();
    }
    if ( DEBUG ) std::cout << "play: " << play << std::endl;

    if ( play ) return Board::Play;
    else return Board::Change;
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
    // if ( state == Board::End ){
    //     sf::RectangleShape endCard;
    //     endCard.setSize( sf::Vector2f(500, 500) );
    //     endCard.setOrigin( sf::Vector2f(0,0) );
    //     endCard.setPosition( sf::Vector2f(4, 4) );
    //     endCard.setFillColor( sf::Color(255, 255, 255) );
    // }
}
