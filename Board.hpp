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

    void draw( sf::RenderWindow& );
private:
    friend class User;
    std::vector < std::vector <Square*> > m_squares;
};
#endif
