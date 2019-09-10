CXXFLAGS = --std=c++17
DIRECTORY = /
DEBUG = -D DEBUG
nimmt: main.o deck.o hand.o card.o game.o
	$(CXX) $(CXXFLAGS) main.o deck.o hand.o card.o game.o -o $(DIRECTORY)nimmt
main.o: main.cpp card.o hand.o deck.o game.o
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(DIRECTORY)main.o
card.o: card.cpp
	$(CXX) $(CXXFLAGS) -c card.cpp -o $(DIRECTORY)card.o
hand.o: hand.cpp card.o deck.o
	$(CXX) $(CXXFLAGS) -c hand.cpp -o $(DIRECTORY)hand.o
deck.o: deck.cpp card.o
	$(CXX) $(CXXFLAGS) -c deck.cpp -o $(DIRECTORY)deck.o
game.o: game.cpp card.o deck.o hand.o
	$(CXX) $(CXXFLAGS) -c game.cpp -o $(DIRECTORY)game.o
debug: CXXFLAGS += -D DEBUG -g
debug: mkdir debug
debug: DIRECTORY = debug/
debug: nimmt
clean:
	rm -f *.o *.gch ~* a.out nimmt
	rm -rf debug
