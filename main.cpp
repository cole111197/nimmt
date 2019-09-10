#include "card.h"
#include "hand.h"
#include "deck.h"
#include "game.h"
#include <iostream>

int main(){
    Deck deck{104};
    deck.shuffle();
    Game game{deck};
    Hand hand0{deck};
    Hand hand1{deck};
    //game.play(hand0.play(0), 2);
}
