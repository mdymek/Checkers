#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "Square.hpp"

class Square;
class Board {
public:
    Board();
    ~Board();

    Square* get( int, int );

    void checkSquare( int, int );
    void deleteOptions();
    void movePawn( Square* );
    void draw( sf::RenderWindow& );
private:
    std::vector < std::vector <Square*> > m_squares;
};
#endif
