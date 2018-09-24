CFLAGS = -std=c++14 -O2 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wmisleading-indentation -Wnull-dereference
LIBS = -lsfml-system -lsfml-window -lsfml-graphics
SFMLPATH = C:\SFML-2.4.0

all:
	g++ $(CFLAGS) main.cpp Board.cpp Square.cpp Pawn.cpp Man.cpp User.cpp -I$(SFMLPATH)/include $(LIBS) -L$(SFMLPATH)/lib -o checkers
