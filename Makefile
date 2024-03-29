CXXFLAGS = --std=c++17
DEBUG = -g -D DEBUG
nimmt: main.o deck.o hand.o card.o game.o
	$(CXX) $(CXXFLAGS) main.o deck.o hand.o card.o game.o -o nimmt
main.o: main.cpp card.o hand.o deck.o game.o
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
card.o: card.cpp
	$(CXX) $(CXXFLAGS) -c card.cpp -o card.o
hand.o: hand.cpp card.o deck.o
	$(CXX) $(CXXFLAGS) -c hand.cpp -o hand.o
deck.o: deck.cpp card.o
	$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o
game.o: game.cpp card.o deck.o hand.o
	$(CXX) $(CXXFLAGS) -c game.cpp -o game.o
debug:
	mkdir debug
	$(CXX) $(CXXFLAGS) $(DEBUG) -c card.cpp -o debug/card.o
	$(CXX) $(CXXFLAGS) $(DEBUG) -c hand.cpp -o debug/hand.o
	$(CXX) $(CXXFLAGS) $(DEBUG) -c deck.cpp -o debug/deck.o
	$(CXX) $(CXXFLAGS) $(DEBUG) -c game.cpp -o debug/game.o
	$(CXX) $(CXXFLAGS) $(DEBUG) -c main.cpp -o debug/main.o
	$(CXX) $(CXXFLAGS) debug/main.o debug/deck.o debug/hand.o debug/card.o debug/game.o -o debug/nimmt
clean:
	rm -f *.o *.gch ~* a.out nimmt
	rm -rf debug
