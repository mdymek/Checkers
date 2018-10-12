#include "consts.h"

#include "Board.hpp"
#include "Square.hpp"
#include "User.hpp"
#include "Pawn.hpp"
#include "Man.hpp"

int main(){
    bool wait = false;
    Board board;
    User* player1 = new User(1, sf::Color::Red, board );
    User* player2 = new User(2, sf::Color::Blue, board);

    sf::RenderWindow window(sf::VideoMode(509,509), "checkers");

    bool first = true;
    bool play = true;
    int turn = 1;
    while ( window.isOpen() ){
        while ( play ){
            if( !wait ){
                window.clear();
                board.draw( window );
                window.display();
                wait = true;
            }

            sf::Event event;
            while( window.pollEvent(event) ){
                if( event.type == sf::Event::Closed){
                    play = false;
                    window.close();
                }
                else if( event.type == sf::Event::KeyPressed ){
                    if( event.key.code == sf::Keyboard::Escape ){
                        play = false;
                        window.close();
                    }
                }
                else if( event.type == sf::Event::MouseButtonPressed ){
                    if ( DEBUG ) std::cout << "tura: " << turn << std::endl;
                    wait = false;
                    play = board.checkSquare(event.mouseButton.x/51, event.mouseButton.y/51, (turn == 1 ? player1 : player2 ), first);
                }
            }
        }

        turn = ( turn == 1 ? 2 : 1 );
        play = true;
        first = true;
    }
    return 0;
}
