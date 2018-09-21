#include "Board.hpp"

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
        }
    }
    return 0;
}
