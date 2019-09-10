#include "card.h"
#include "hand.h"
#include "deck.h"
#include "game.h"
#include <iostream>
#include <vector>

int main(){
    Deck deck{104};
    deck.shuffle();
    Game game{deck};
    std::vector<Hand> hands;
    for(int i = 0; i < 4; i++){
        hands.push_back(Hand{deck});
    }
    std::cout << game.to_string() << std::endl;
    std::cout << game.play(hands[0].play(0)) << std::endl;
    std::cout << game.to_string() << std::endl;
    std::cout << game.play(hands[0].play(0)) << std::endl;
    std::cout << game.to_string() << std::endl;
    std::cout << game.play(hands[0].play(0)) << std::endl;
    std::cout << game.to_string() << std::endl;
    std::cout << game.play(hands[0].play(0)) << std::endl;
    std::cout << game.to_string() << std::endl;
    std::cout << game.play(hands[0].play(0)) << std::endl;
    std::cout << game.to_string() << std::endl;
}
