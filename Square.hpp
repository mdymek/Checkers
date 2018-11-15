#ifndef SQUARE_H
#define SQUARE_H
#include "Pawn.hpp"
#include <iostream>

class User;
class Pawn;
class Square : public sf::Drawable {
public:
    Square( sf::Vector2f, sf::Color );
    ~Square();

    void setOption( Square* );
    void unsetOption();
    Square* getOption() const;

    sf::Vector2f getPosition() const;

    bool isFree() const;
    void addPawn( Pawn* );
    Pawn* getPawn() const;
    void removePawn();

    void draw( sf::RenderTarget&, sf::RenderStates ) const;
private:
    bool m_isOption;
    Square* m_option;
    sf::Vector2f m_position;
    mutable sf::RectangleShape m_shape;
    Pawn* m_pawn;
};
#endif
