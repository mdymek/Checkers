#include "consts.h"

#include "Board.hpp"
#include "Square.hpp"
#include "User.hpp"
#include "Pawn.hpp"
#include "Man.hpp"

int main(){
    Board board;
    User* player1 = new User(1, sf::Color::Red, board );
    User* player2 = new User(2, sf::Color::Blue, board);

    sf::RenderWindow window(sf::VideoMode(509,509), "checkers");
    window.setFramerateLimit(30);

    bool first = true;
    Board::State state = Board::Play;
    int turn = 1;
    while ( window.isOpen() ){
        while ( state == Board::Play ){
            sf::Event event;
            while( window.pollEvent(event) ){
                if( event.type == sf::Event::Closed){
                    state = Board::End;
                    window.close();
                }
                else if( event.type == sf::Event::KeyPressed ){
                    if( event.key.code == sf::Keyboard::Escape ){
                        state = Board::End;
                        window.close();
                    }
                }
                else if( event.type == sf::Event::MouseButtonPressed ){
                    // if ( state == Board::End ) window.close();
                    if ( DEBUG ) std::cout << "tura: " << turn << std::endl;
                    state = board.checkSquare(event.mouseButton.x/51, event.mouseButton.y/51, (turn == 1 ? player1 : player2 ), first);
                }
            }

            window.clear();
            window.draw( board );
            window.display();
        }
        if ( player1->getNumber() == 0 || player2->getNumber() == 0 ){
            std::cout << "END" << std::endl;
            state = Board::End;
            window.close();
        }
        else {
            turn = ( turn == 1 ? 2 : 1 );
            state = Board::Play;
            first = true;
        }
    }

    delete player1;
    delete player2;

    return 0;
}
