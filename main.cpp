#include "Board.hpp"
#include "Square.hpp"
#include "User.hpp"
#include "Pawn.hpp"
#include "Man.hpp"

int main(){
    bool wait = false;
    Board board;
    User user( sf::Color::Red, board );

    sf::RenderWindow window(sf::VideoMode(509,509), "checkers");

    while ( window.isOpen() ){
        if( !wait ){
            window.clear();
            board.draw( window );
            window.display();
            wait = true;
        }

        sf::Event event;
        while( window.pollEvent(event) ){
            if( event.type == sf::Event::Closed){
                window.close();
            }
            else if( event.type == sf::Event::KeyPressed ){
                if( event.key.code == sf::Keyboard::Escape ){
                    window.close();
                }
            }
            else if( event.type == sf::Event::MouseButtonPressed ){
                wait = false;
                board.checkSquare(event.mouseButton.x/51, event.mouseButton.y/51);
                std::cout << "x: " << event.mouseButton.x;
                std::cout << "y: " << event.mouseButton.y;
                std::cout << std::endl;
                std::cout << "square: " << event.mouseButton.x/51 << " " << event.mouseButton.y/51 << std::endl;
            }
        }
    }
    return 0;
}
