#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "Square.hpp"
#include "User.hpp"

class User;
class Square;
class Board {
public:
    enum State {
        End = 0,
        Change = 2,
        Play = 4
    };

    Board();
    ~Board();

    Square* get( int, int );

    State checkSquare( int, int, User*, bool& );
    void deleteOptions();
    void movePawn( int, int );
    void draw( sf::RenderWindow& );
private:
    std::vector < std::vector <Square*> > m_squares;
};
#endif
