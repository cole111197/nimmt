#include "card.h"
#include "hand.h"
#include "deck.h"
#include "game.h"
#include <iostream>
#include <vector>

int main(){
    Deck deck{104};
    deck.shuffle();
    Game game{deck, 4};

    std::cout << game.to_string() << std::endl;
    std::cout << game.play(0,0) << std::endl;
    std::cout << game.to_string() << std::endl;
    std::cout << game.play(0,0) << std::endl;
    std::cout << game.to_string() << std::endl;
    std::cout << game.play(0,0) << std::endl;
    std::cout << game.to_string() << std::endl;
    std::cout << game.play(0,0) << std::endl;
    std::cout << game.to_string() << std::endl;
    std::cout << game.play(0,0) << std::endl;
    std::cout << game.to_string() << std::endl;
}
