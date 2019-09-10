#include "card.h"
#include "hand.h"
#include "deck.h"
#include "game.h"
#include <iostream>

int main(){
    Deck deck{104};
    deck.shuffle();
    Game game{deck};
    std::cout << game.to_string() << std::endl;
}
