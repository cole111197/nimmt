CXXFLAGS = --std=c++17
nimmt: main.o deck.o hand.o card.o
	$(CXX) $(CXXFLAGS) main.o deck.o hand.o card.o -o nimmt
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
deck.o: deck.cpp
	$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o
hand.o: hand.cpp
	$(CXX) $(CXXFLAGS) -c hand.cpp -o hand.o
card.o: card.cpp
	$(CXX) $(CXXFLAGS) -c card.cpp -o card.o
clean:
	rm -f *.o *.gch ~* a.out nimmt
